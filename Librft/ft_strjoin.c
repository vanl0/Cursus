/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 17:14:49 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/22 17:26:55 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	int		n;
	int		i;

	i = 0;
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = malloc(n * sizeof(char));
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	ft_strlcat(strjoin, s2, n);
	return (strjoin);
}
