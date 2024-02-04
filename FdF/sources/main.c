/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 20:12:50 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/01 09:41:11 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	pack_init(t_pack *pack)
{
	pack->img.win.mlx_ptr = mlx_init();
	pack->img.win.win_ptr = mlx_new_window(pack->img.win.mlx_ptr, \
	2500, 1300, "fdf");
	pack->img.img = mlx_new_image(pack->img.win.mlx_ptr, 2500, 1300);
	pack->img.addr = mlx_get_data_addr(pack->img.img, \
	&pack->img.bits_per_pixel, &pack->img.line_length, &pack->img.endian);
	pack->map.str = NULL;
	pack->map.xlen = 0;
	pack->map.ylen = 0;
	pack->map.points = NULL;
	pack->map.z_scale = 0.1;
}

void	check_path(int argc, char **argv)
{
	char	**split_file;

	if (argc != 2)
		error_end("Numero de argumentos incorrecto\n", NULL);
	split_file = ft_split(argv[1], '.');
	if (!split_file)
		error_end("Malloc fail\n", NULL);
	if (!split_file[1] || ft_strncmp(split_file[1], "fdf", 4) != 0)
	{
		matrix_free(split_file);
		error_end("Formato incorrecto\n", NULL);
	}
	matrix_free(split_file);
}

int	main(int argc, char **argv)
{
	t_pack	pack;

	check_path(argc, argv);
	pack_init(&pack);
	load_map(&pack.map, argv[1]);
	to_iso(&pack.map);
	get_limits(&pack.map);
	set_scale(&pack.map);
	set_axis(&pack.map);
	draw_map(&pack.map, &pack.img);
	mlx_put_image_to_window(pack.img.win.mlx_ptr, \
	pack.img.win.win_ptr, pack.img.img, 0, 0);
	mlx_key_hook(pack.img.win.win_ptr, handle_input, &pack);
	mlx_hook(pack.img.win.win_ptr, 17, 0, end, &pack);
	mlx_loop(pack.img.win.mlx_ptr);
	return (0);
}
