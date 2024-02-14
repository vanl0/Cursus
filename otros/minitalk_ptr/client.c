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

#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include "./ft_printf/ft_printf.h"

char	*ft_strdup(const char *s)
{
	char		*sdup;
	size_t		n;
	size_t		i;

	n = strlen(s);
	sdup = malloc((n + 1) * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

void send_ptr(pid_t pid, char *ptr) {
    unsigned long long int address = (unsigned long long int)ptr;
    unsigned long long int bit = 0;
	int	i = sizeof(char *) * 8 - 1;

	while (i >= 0)
	{
		bit = (address >> i) & 1;
		kill(pid, 30 + bit);
		usleep(100);
		i--;
	}
	printf("pointer: %p\n", ptr);
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

int	main(int argc, char ** argv)
{
	pid_t	pid;
	char	*ptr;

	if (argc != 3)
	{
		ft_printf("PID y MENSAJE necesarios\n");
		return (0);
	}
	pid = ft_atopid(argv[1]);
	ptr = ft_strdup(argv[2]);
	send_ptr(pid, ptr);
}