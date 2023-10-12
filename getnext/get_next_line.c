/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:22:49 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/05 16:45:36 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <stdio.h>

char	*split_newline(char *buffer, char	*newline)
{
	char	*temp;
	int		size;

	size = newline - buffer + 1;
	temp = ft_substr(buffer, 0, size);
	if (!temp)
		return (free(buffer), NULL);
	buffer = ft_substr(buffer, size, ft_strlen(newline));
	if (!buffer)
		return (free(temp), NULL);
	return (temp);
}

char	*find_newline(char *buffer, char *temp, int fd)
{
	while (!ft_strchr(buffer, '\n'))
	{
		if (!temp)
		{
			temp = ft_substr(buffer, 0, ft_strlen(buffer));
			if (!temp)
				return (free(buffer), NULL);
		}
		else
		{
			temp = ft_strjoin(temp, buffer);
			if (!temp)
				return (free(buffer), NULL);
		}
		if (!read(fd, buffer, BUFFER_SIZE - 1))
			return (free(temp), NULL);
	}
	return (ft_strjoin(temp, split_newline(buffer, ft_strchr(buffer, '\n'))));
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*temp;
	int			r;

	temp = NULL;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE - 1] = '\0';
	if (!(*buffer))
	{
		r = read(fd, buffer, BUFFER_SIZE - 1);
		if (r < 0)
			return (free(buffer), NULL);
	}
	if (ft_strchr(buffer, '\n'))
		temp = split_newline(buffer, ft_strchr(buffer, '\n'));
	else
		temp = find_newline(buffer, temp, fd);
	if (!temp)
		return (free(buffer), NULL);
	return (temp);
}
