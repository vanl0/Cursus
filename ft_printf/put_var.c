/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:13:42 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/02 16:14:54 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	put_var(va_list args, char c, int *perr)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int), perr));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *), perr));
	if (c == 'p')
		return (ft_putpoint(va_arg(args, unsigned long), perr));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int ), perr));
	if (c == 'u')
		return (ft_putunsig(va_arg(args, unsigned int), perr));
	if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c, perr));
	if (c == '%')
		return (ft_putchar('%', perr));
	return (0);
}
