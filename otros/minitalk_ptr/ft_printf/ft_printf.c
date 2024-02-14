/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:40:38 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/03 17:27:03 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	printer(const char *s, va_list vargs)
{
	int	i;
	int	n;
	int	err;

	i = 0;
	n = 0;
	err = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			n += put_var(vargs, s[i + 1], &err);
			i += 2;
			if (err < 0)
				return (err);
		}
		else
		{
			if (write(1, &s[i], 1) < 0)
				return (-1);
			i++;
			n++;
		}
	}
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	vargs;
	int		res;

	va_start(vargs, s);
	res = printer(s, vargs);
	va_end(vargs);
	return (res);
}
