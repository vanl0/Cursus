/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:05:14 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/29 10:31:14 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	draw_pixel(t_img_data *idata, int x, int y, int color)
{
	char	*dst;

	dst = idata->addr + (y * idata->line_length + \
			x * (idata->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

t_line	line_set(t_point point1, t_point point2, t_map *map)
{
	t_line	line;

	point1.x *= map->scale;
	point1.y *= map->scale;
	point2.x *= map->scale;
	point2.y *= map->scale;
	line.dx = fabs(point2.x - point1.x);
	line.dy = fabs(point2.y - point1.y);
	if (line.dx > line.dy)
		line.pixels = line.dx;
	else
		line.pixels = line.dy;
	line.xstep = (float)(point2.x - point1.x) / line.pixels;
	line.ystep = (float)(point2.y - point1.y) / line.pixels;
	return (line);
}

void	draw_line(t_img_data *img, t_point point1, t_point point2, t_map *map)
{
	t_line	line;
	float	x;
	float	y;
	int		cstep;
	int		i;

	i = 0;
	line = line_set(point1, point2, map);
	if (line.pixels != 0)
		cstep = (point2.color - point1.color) / line.pixels;
	else
		cstep = 0xffffff;
	x = (float) map->scale * point1.x + map->ox;
	y = (float) map->scale * point1.y + map->oy;
	while (line.pixels && x < 2500 && x > 0 && y < 1300 && y > 0)
	{
		draw_pixel(img, x, y, point1.color + i * cstep);
		x += line.xstep;
		y += line.ystep;
		line.pixels--;
		i++;
	}
}
