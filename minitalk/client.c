/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:20:23 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/09 13:26:35 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./ft_printf/ft_printf.h"

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

int	ft_atopid(const char *str)
{
	int	n;
	int	i;
	int	neg;

	n = 0;
	i = 0;
	neg = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i ++;
	}
	else if (str[i] == '+')
		i ++;
	while (str[i] == '0')
		i ++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = 10 * n + str[i] - '0';
		i ++;
	}
	return ((pid_t)(n * neg));
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
	pid = ft_atopid(argv[1]);
	while (argv[2][i])
		send_char(argv[2][i++], pid);
	return (0);
}
