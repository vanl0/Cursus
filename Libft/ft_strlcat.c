/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 12:47:13 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/07/21 13:30:48 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i ++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	destsize;
	int				srcsize;

	i = 0;
	srcsize = ft_strlen(src);
	destsize = ft_strlen(dest);
	if (size <= destsize)
		return (srcsize + size);
	while (src[i] != '\0' && destsize + i < size - 1)
	{
		dest[destsize + i] = src[i];
		i ++;
	}
	dest[destsize + i] = '\0';
	return (srcsize + destsize);
}
