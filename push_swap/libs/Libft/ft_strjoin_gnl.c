/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 17:18:25 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/05 17:18:27 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*strjoin;
	int		n;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = malloc(n * sizeof(char));
	if (!strjoin)
		return (erase_free(&s1));
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		strjoin[i++] = s2[j++];
	}
	strjoin[i] = '\0';
	erase_free (&s1);
	return (strjoin);
}
