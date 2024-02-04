/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:19:23 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/26 20:23:18 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	to_iso(t_map *map)
{
	float	x;
	float	y;
	int		i;

	i = 0;
	while (i < map->xlen * map->ylen)
	{
		x = map->points[i].x;
		y = map->points[i].y;
		map->points[i].x = (x - y) * cos(0.523599);
		map->points[i].y = -map->points[i].z * map->z_scale + \
		((x + y) * sin(0.523599));
		i++;
	}
}

void	get_limits(t_map *map)
{
	int	i;

	i = 1;
	map->x_min = map->points[0].x;
	map->x_max = map->points[0].x;
	map->y_min = map->points[0].y;
	map->y_max = map->points[0].y;
	while (i < map->xlen * map->ylen)
	{
		if (map->points[i].x < map->x_min)
			map->x_min = map->points[i].x;
		else if (map->points[i].x > map->x_max)
			map->x_max = map->points[i].x;
		if (map->points[i].y < map->y_min)
			map->y_min = map->points[i].y;
		else if (map->points[i].y > map->y_max)
			map->y_max = map->points[i].y;
		i++;
	}
	map->iso_xlen = map->x_max - map->x_min;
	map->iso_ylen = map->y_max - map->y_min;
}

void	set_scale(t_map *map)
{
	if (map->iso_xlen > map->iso_ylen)
		map->scale = 2500 / (2 * map->iso_xlen);
	else
		map->scale = 1300 / (2 * map->iso_xlen);
}

void	set_axis(t_map *map)
{
	map->ox = (2500 / 4) - map->x_min * map->scale;
	map->oy = (1300 / 4) - map->y_min * map->scale;
}
