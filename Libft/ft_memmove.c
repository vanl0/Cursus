/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:53:12 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/17 14:21:29 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const char *src, size_t len)
{
	size_t	i;
	char	*cdest;
	char	*csrc;
	char	temp[6];

	i = 0;
	cdest = (char *)dest;
	csrc = (char *)src;
	while (i < len)
	{
		temp[i] = csrc[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		cdest[i] = temp[i];
		i++;
	}
	return (dest);
}
