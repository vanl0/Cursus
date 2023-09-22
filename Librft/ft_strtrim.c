/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 18:35:27 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/09/22 19:12:45 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	checkbeg(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*cs1;

	cs1 = (char *)s1;
	i = 0;
	j = 0;
	while (set[j] != '\0' && cs1[i] != '\0')
	{
		if (cs1[i] == set[j])
		{
			cs1[i] = '\0';
			i++;
			j = 0;
		}
		else
			j++;
	}
	return (i);
}

void	checkend(char const *s1, char const *set, size_t size)
{
	int		j;
	char	*cs1;

	cs1 = (char *)s1;
	j = 0;
	size--;
	while (set[j] != '\0' && size >= 0)
	{
		if (cs1[size] == set[j])
		{
			cs1[size] = '\0';
			size--;
			j = 0;
		}
		else
			j++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*strtrim;
	size_t	size;
	int		k;

	checkend(s1, set, ft_strlen(s1));
	size = checkbeg(s1, set);
	strtrim = malloc((ft_strlen(s1 + size) + 1) * sizeof(char));
	if (strtrim == NULL)
		return (NULL);
	k = 0;
	while (s1[size] != '\0')
		strtrim[k++] = s1[size++];
	strtrim[k] = '\0';
	return (strtrim);
}
