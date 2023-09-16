/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 13:40:12 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/13 14:05:30 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	n;
	int	i;
	int	neg;

	n = 0;
	i = 0;
	neg = 1;
	if (str[0] == '-')
	{
		neg = -1;
		i ++;
	}
	else
		if (str[0] == '+')
			i ++;
	while (str[i] == '0')
		i ++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		n = 10 * n + str[i] - '0';
		i ++;
	}
	return (n * neg);
}
