/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:52:37 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/22 08:58:28 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	load_map(t_map	*map, char *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 2)
		return ;
	map->str = read_map(fd);
	get_map_size(map);
	set_points(map);
    free(map->str);
	close (fd);
}

/*Lee el archivo y lo devuelve en una string "map"
	Se asume que strdup, strjoin y read no dan error*/
char	*read_map(int fd)
{
	char	*buffer;
	char	*map;
	size_t	read_bytes;
	size_t	chunk_read;

	chunk_read = 5000;
	read_bytes = chunk_read;
	map = ft_strdup("");
	buffer = malloc(chunk_read * sizeof(char));
	if (!buffer)
		error_end("malloc");
	while (read_bytes == chunk_read)
	{
		ft_bzero(buffer, chunk_read);
		read_bytes = read(fd, buffer, chunk_read);
		map = ft_strjoin_gnl(map, buffer);
		printf("Bytes leidos: %zu\n", read_bytes);
		//read_bytes += chunk_read;
	}
	free(buffer);
	return (map);
}

/*Comprobamos que es rectangular
	y guardamos las midas en map*/
void	get_map_size(t_map	*map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
    map->xlen = 0;
	while (map->str[i])
	{
        /*printf("c: %c\n\
                x: %i\n\
                xlen: %i\n\
                ---\n", map->str[i], x, map->xlen);*/
		if (ft_isalnum(map->str[i]) && (map->str[i + 1] == ' ' || \
					map->str[i + 1] == '\n' || map->str[i + 1] == '\0'))
			x++;
		if (map->str[i] == '\n')
		{
			if (!map->xlen)
				map->xlen = x;
			if (map->xlen != x)
				error_end("No es rectangular1");
			x = 0;
			map->ylen++;
		}
		i++;
	}
	//printf("x: %i, xlen: %i\n", x, map->xlen);
	if (map->xlen != x && x != 0)
		error_end("No es rectangular2");
	if (x != 0)
		map->ylen++;
    //printf("\nxlen: %i\nylen: %i\n", map->xlen, map->ylen);
}

/*Una vez sabemos que el mapa es valido lo leemos linea a linea
	y asignamos las coordenadas y color a cada punto del array
   	de t_point en t_map*/

void	set_points(t_map *map)
{
	int		i;
	char	*line;
	char	*start;
	int		y;

	i = 0;
	y = 0;
	start = map->str;
	map->points = ft_calloc(map->xlen * map->ylen, sizeof(t_point));
	while (map->str[i])
	{
		if (map->str[i] == '\n')
		{
			//printf("Size: %li\n", &map->str[i] - start);
			line = ft_substr(start, 0, &map->str[i] - start);
			//printf("%s\n", line);
			set_coords(map, y, line);
			free(line);
			y++;
			start = &map->str[i + 1];
		}
		i++;
	}
	line = ft_substr(start, 0, start - &map->str[i]);
	set_coords(map, y, line);
	free(line);
}
