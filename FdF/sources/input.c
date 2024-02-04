/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:31:29 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/29 10:32:12 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

int	end(t_pack *pack)
{
	mlx_destroy_image(pack->img.win.mlx_ptr, pack->img.img);
	mlx_destroy_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr);
	free(pack->map.points);
	exit (0);
	return (0);
}

int	handle_input(int key, t_pack *pack)
{
	if (key == 6 || key == 7)
		zoom(key, pack);
	if (key == 0 || key == 1)
	{
		z_scale(key, &pack->map);
		redraw(pack);
	}
	if (key >= 123 && key <= 126)
		move_map(key, pack);
	if (key >= 86 && key <= 91)
		move_map_fast(key, pack);
	if (key == 53)
		end(pack);
	return (0);
}
