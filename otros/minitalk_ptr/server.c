/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 server.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/01 12:05:24 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/01 12:53:32 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"

void	gotsign(int signal)
{
	static int	bit_pos = 0;
	static unsigned long long	ptr = 0;
	char	*str;

	if (signal == SIGUSR2)
		ptr = 2 * ptr + 1;
	else
		ptr = 2 * ptr;
	bit_pos++;
	if (bit_pos == 64)
	{
		str = (char *)ptr;
		printf("pointer: %p\n", str);
		//printf("string: %s\n", str);
		//free(str);
		bit_pos = 0;
		ptr = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = gotsign;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
	{
		pause();
	}
	return (0);
}
