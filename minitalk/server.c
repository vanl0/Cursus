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
	if (signal == SIGUSR1)
		printf("0");
	else
		printf("1");
}

int	main(void)
{
	signal(SIGUSR1, gotsign);
	signal(SIGUSR2, gotsign);
	printf("PID: %d\n", getpid());
	while(1)
		pause();
	return (0);
}
