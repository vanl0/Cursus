/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:18:19 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/03 17:29:23 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int *perr)
{
	int	i;

	if (!s)
		return (ft_putstr("(null)", perr));
	i = 0;
	while (s[i])
	{
		ft_putchar(s[i], perr);
		i++;
	}
	return (i);
}
