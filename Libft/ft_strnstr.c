/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:56:24 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/17 16:45:24 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	j = 0;
	if (find[0] == '\0' || str[0] == '\0')
		return ((char *)str);
	while (i < len || str[i] != '\0')
	{
		if (find[j] == str[i + j])
		{
			j++;
			if (find[j] == '\0')
				return ((char *)&str[i + j]);
		}
		i++;
		j = 0;
	}
	return (0);
}
