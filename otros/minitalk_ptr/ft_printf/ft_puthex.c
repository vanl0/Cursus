/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:09:22 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/03 17:28:13 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	hexlen(unsigned int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		i++;
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int nb, char c, int *perr)
{
	int	len;

	if (*perr < 0)
		return (-1);
	len = hexlen(nb);
	if (nb == 0)
		return (ft_putchar('0', perr));
	if (nb >= 16)
	{
		ft_puthex(nb / 16, c, perr);
		ft_puthex(nb % 16, c, perr);
	}
	else
	{
		if (nb >= 10)
		{
			if (c == 'x')
				ft_putchar(nb - 10 + 'a', perr);
			else
				ft_putchar(nb - 10 + 'A', perr);
		}
		else
			ft_putchar(nb + '0', perr);
	}
	return (len);
}
