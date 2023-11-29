/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:29:32 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/29 10:42:03 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	redraw(t_pack *pack)
{
	mlx_clear_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr);
	mlx_destroy_image(pack->img.win.mlx_ptr, pack->img.img);
	pack->img.img = mlx_new_image(pack->img.win.mlx_ptr, 2500, 1300);
	pack->img.addr = mlx_get_data_addr(pack->img.img, \
			&pack->img.bits_per_pixel, &pack->img.line_length, \
			&pack->img.endian);
	draw_map(&pack->map, &pack->img);
	mlx_put_image_to_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr, \
			pack->img.img, pack->img_x, pack->img_y);
}

void	move_map(int key, t_pack *pack)
{
	if (key == 126)
	{
		pack->map.oy -= 20;
		redraw(pack);
	}
	if (key == 125)
	{
		pack->map.oy += 20;
		redraw(pack);
	}
	if (key == 123)
	{
		pack->map.ox -= 20;
		redraw(pack);
	}
	if (key == 124)
	{
		pack->map.ox += 20;
		redraw(pack);
	}
}

void	move_map_fast(int key, t_pack *pack)
{
	if (key == 87)
	{
		pack->map.oy -= 75;
		redraw(pack);
	}
	if (key == 91)
	{
		pack->map.oy += 75;
		redraw(pack);
	}
	if (key == 86)
	{
		pack->map.ox += 75;
		redraw(pack);
	}
	if (key == 88)
	{
		pack->map.ox -= 75;
		redraw(pack);
	}
}

void	z_scale(int key, t_map *map)
{
	int	i;

	i = 0;
	if (key == 0)
	{
		while (i < map->xlen * map->ylen)
		{
			map->points[i].y += -map->points[i].z * 0.01;
			i++;
		}
	}
	else
	{
		while (i < map->xlen * map->ylen)
		{
			map->points[i].y -= -map->points[i].z * 0.01;
			i++;
		}
	}
}

void	zoom(int key, t_pack *pack)
{
	if (key == 6)
	{
		pack->map.scale += 1;
		redraw(pack);
	}
	if (key == 7 && pack->map.scale > 0)
	{
		pack->map.scale -= 1;
		redraw(pack);
	}
}
