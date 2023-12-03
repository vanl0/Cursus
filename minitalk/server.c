/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:05:24 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/01 12:53:32 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdio.h>


void gotsign(int signal) 
{
	static int bit_pos = 0;
	static char	tchar = 0;

	if (signal == SIGUSR2)
	{
        tchar |= (1 << (7 - bit_pos));
	}
    bit_pos++;
    if (bit_pos == 8)
    {
        //send_char(tchar);
        write(1, &tchar, 1);
        bit_pos = 0;
        tchar = 0;
    }
}

int main(void) {
    struct sigaction sa;
    sa.sa_handler = gotsign;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("PID: %d\n", getpid());

    while (1) {
        pause();
    }

    return 0;
}
