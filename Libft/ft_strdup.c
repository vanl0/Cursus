/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 14:51:44 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/17 16:52:05 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*sdup;
	size_t		n;
	size_t		i;

	n = ft_strlen(sdup);
	sdup = malloc(n * sizeof(char));
	if (sdup == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		sdup[i] = s[i];
		i++;
	}
	return (sdup);
}
