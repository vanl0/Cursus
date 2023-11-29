/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_points.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:25:02 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/26 20:26:29 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	draw_map(t_map *map, t_img_data *img)
{
	connect_x(map, img);
	connect_y(map, img);
}

void	connect_x(t_map *map, t_img_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i + 1 < map->xlen * map->ylen)
	{
		while ((i < map->xlen * map->ylen) && j < map->xlen - 1)
		{
			draw_line(img, map->points[i], map->points[i + 1], map);
			i++;
			j++;
		}
		j = 0;
		i++;
	}
}

void	connect_y(t_map *map, t_img_data *img)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->xlen * map->ylen - 1)
	{
		i = j;
		while ((i + map->xlen) < map->xlen * map->ylen)
		{
			draw_line(img, map->points[i], map->points[i + map->xlen], map);
			i += map->xlen;
		}
		j++;
	}
}
