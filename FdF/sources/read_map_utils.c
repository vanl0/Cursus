/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:58:57 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/22 08:59:58 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	check_point(char *val)
{
	int	i;

	i = 0;
	if (*val == '-' || *val == '+' || ft_isdigit(val[i]))
		i++;
	while (ft_isdigit(val[i]))
		i++;
	if (val[i] != ',' && val[i] != '\0')
		error_end("Puntos invalidos");
}

int	get_color(char *val)
{
	char	**split_val;
	int		color;

	if (ft_strchr(val, ','))
	{
		split_val = ft_split(val, ',');
		color = strtol(split_val[1] + 2, NULL, 16);
		matrix_free(split_val);
		return (color);
	}
	else
		return (0);
}

void	set_coords(t_map *map, int y, char	*line)
{
	int		i;
	int		j;
	char	**split_line;

	i = y * map->xlen;
	j = 0;
	split_line = ft_split(line, ' ');
	while (split_line[j])
	{
		check_point(split_line[j]);
		map->points[i].x = j;
		map->points[i].y = y;
		map->points[i].z = ft_atoi(split_line[j]);
		map->points[i].color = get_color(split_line[j]);
		//printf("Punto: %i\n x = %i, y = %i, z = %i\n",i,  j, y,map->points[i].z);
		i++;
		j++;
	}
	matrix_free(split_line);
}
