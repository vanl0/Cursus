/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:56:44 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/02 16:18:02 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	numlen(long int nb)
{
	int	i;

	i = 0;
	if (nb <= 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb, int *perr)
{
	int	len;

	if (*perr < 0)
		return (-1);
	len = numlen(nb);
	if (nb == -2147483648)
		return (ft_putstr("-2147483648", perr));
	if (nb == 0)
		return (ft_putchar ('0', perr));
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar ('-', perr);
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, perr);
		ft_putnbr(nb % 10, perr);
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0', perr);
	}
	return (len);
}
