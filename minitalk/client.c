/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:20:23 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/01 12:59:19 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>

#include <stdlib.h>
#include <stdio.h>


void	send_char(char c, pid_t pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> (7 - i)) & 1;
		i++;
		//printf("%d", bit);
		kill (pid, 30 + bit);
		usleep(10000);
	}
	printf("\n");
}

pid_t	get_pid(char	*arg)
{
	pid_t	pid;

	pid = (pid_t) atoi(arg);
	return (pid);
}

int main(int argc, char **argv)
{
	pid_t pid;
	int i = 0;

	if (argc != 3)
	{
		printf("PID and CHR needed\n");
		return (0);
	}
	pid = get_pid(argv[1]);
	while(argv[2][i])
		send_char(argv[2][i++], pid);
	return (1);
}
