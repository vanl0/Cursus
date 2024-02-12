/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:20:23 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/02/06 13:43:59 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	send_char(char c, pid_t pid)
{
	int	i;
	int	bit;

	i = 0;
	while (i < 8)
	{
		bit = (c >> (7 - i)) & 1;
		i++;
		kill(pid, 30 + bit);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	int					i;

	i = 0;
	if (argc != 3)
	{
		ft_printf("PID y MENSAJE necesarios\n");
		return (0);
	}
	pid = (pid_t) ft_atoi(argv[1]);
	while (argv[2][i])
		send_char(argv[2][i++], pid);
	return (0);
}
