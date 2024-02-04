/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:38:24 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/10/17 14:38:28 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*erase_free(char	**buffer)
{
	free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*read_file(int fd, char	*backup)
{
	ssize_t	bytes_read;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (erase_free(&backup));
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(backup, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			if (!backup)
				backup = ft_strdup(buffer);
			else
				backup = ft_strjoin(backup, buffer);
			if (!backup)
				return (erase_free(&buffer));
		}
	}
	erase_free(&buffer);
	if (bytes_read < 0)
		return (erase_free(&backup));
	return (backup);
}

char	*set_line(char	*backup)
{
	char	*line;
	char	*newline;

	newline = ft_strchr(backup, '\n');
	if (!newline)
		return (ft_strdup(backup));
	line = ft_substr(backup, 0, (newline - backup + 1));
	if (!line)
		return (NULL);
	return (line);
}

char	*cut_backup(char *backup)
{
	char	*cut_backup;
	char	*newline;

	newline = ft_strchr(backup, '\n');
	if (!newline || !newline[1])
		return (erase_free(&backup));
	else
	{
		cut_backup = ft_strdup(newline + 1);
		erase_free(&backup);
		if (!cut_backup)
			return (NULL);
		return (cut_backup);
	}
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((backup && !ft_strchr(backup, '\n')) || !backup)
		backup = read_file(fd, backup);
	if (!backup)
		return (NULL);
	line = set_line(backup);
	if (!line)
		return (erase_free(&backup));
	backup = cut_backup(backup);
	return (line);
}
