/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:05:14 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/22 09:02:31 by ilorenzo         ###   ########.fr       */
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

t_line line_set(t_point point1, t_point point2, int scale)
{
	t_line line;
	
	point1.x *= scale;
	point1.y *= scale;
	point2.x *= scale;
	point2.y *= scale;
	
	line.dx = fabs(point2.x - point1.x);
	line.dy = fabs(point2.y - point1.y);
	if (line.dx > line.dy)
		line.pixels = line.dx;
	else
		line.pixels = line.dy;
	line.xstep = (float)(point2.x - point1.x) / line.pixels;
	line.ystep = (float)(point2.y - point1.y) / line.pixels;

	return line;
}


void draw_line(t_img_data *img, t_point point1, t_point point2, int scale)
{
	t_line	line;
	
	line = line_set(point1, point2, scale);
    float x = (float) scale * point1.x + 500;
    float y = (float) scale * point1.y + 400;
	while (line.pixels)
	{
		draw_pixel(img, x, y, 0xffffff);
		x += line.xstep;
		y += line.ystep;
		line.pixels--;
	}
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img, 0, 0);
}