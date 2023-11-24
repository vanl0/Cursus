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

void draw_line2(t_img_data *img, t_point point1, t_point point2, int scale)
{
    t_line line;
    int slope;
    int x;
    int y;

    line = line_set(point1, point2, scale);
    x = line.x0;
    y = line.y0;
    slope = (line.yf - line.y0) / (float)(line.xf - line.x0);
	//printf("\x1b[37m" "Line:\n x0: %i, y0: %i\n xf: %i, yf: %i\n", line.x0, line.y0, line.xf, line.yf);
    while (x < line.xf)
    {
        draw_pixel(img, x, y, line.color);
        x++;

        while(y != slope * (x - line.x0) + line.y0)
        {
            y += slope / abs(slope);
            draw_pixel(img, x, y, line.color);
			//printf("x: %i, y: %i\n", x, y);
        }
    }
    //mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img, 0, 0);
}

t_line line_set(t_point point1, t_point point2, int scale)
{
	t_line line;

	if (point1.x > point2.x)
	{
		point1.x ^= point2.x;
		point2.x ^= point1.x;
		point1.x ^= point2.x;
		point1.y ^= point2.y;
		point2.y ^= point1.y;
		point1.y ^= point2.y;
	}
	line.x0 = scale * point1.x;
	line.y0 = scale * point1.y;
	line.xf = scale * point2.x;
	line.yf = scale * point2.y;
	line.color = 0xffffff;

	line.dx = line.xf - line.x0;
	line.dy = line.yf - line.y0;
	line.p = 2 * line.dy + line.dx;

	return line;
}

void draw_line(t_img_data *img, t_point point1, t_point point2, int scale)
{
	t_line	line;
	int		y;
	int		x;

	line = line_set(point1, point2, scale);
	printf("111111\n");
	x = line.x0;
	y = line.y0;
	if (line.xf == line.x0)
	{
		while (y != line.yf)
		{
			draw_pixel(img, x, y, line.color);
			printf("22222\n");
			y += (line.dy)/abs(line.dy);
		}
		x++;
	}
	while (x <= line.xf)
	{
		draw_pixel(img, x, y, line.color);
		x++;
		if (line.p >= 0)
		{
			y++;
			line.p += 2 * (line.dy - line.dx);
		}
		else
			line.p += 2 * line.dy;
	}
	mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img, 0, 0);
}