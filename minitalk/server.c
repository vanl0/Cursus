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

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	printf("pid: %d\nSIGUSR1: %d\nSIGUSR2: %d\n", pid, SIGUSR1, SIGUSR2);
	return (0);
}
