/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:15:49 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/03 17:27:25 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putchar(char c, int *perr)
{
	if (*perr >= 0)
		*perr = write(1, &c, 1);
	else
		write(1, &c, 1);
	return (1);
}
