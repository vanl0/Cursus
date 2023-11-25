/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 test.c												:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/11/08 13:12:10 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/11/08 13:12:14 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

void	pack_init(t_pack *pack)
{
	pack->img.win.mlx_ptr = mlx_init();
	pack->img.win.win_ptr = mlx_new_window(pack->img.win.mlx_ptr, 2500, 1300, "test");
	pack->img.img =  mlx_new_image(pack->img.win.mlx_ptr, 2500, 1300);
	pack->img.addr = mlx_get_data_addr(pack->img.img, &pack->img.bits_per_pixel, &pack->img.line_length, &pack->img.endian);
	pack->map.str = NULL;
	pack->map.xlen = 0;
	pack->map.ylen = 0;
	pack->map.points = NULL;
	pack->ox = 300;
	pack->oy = 200;
}

int	main(void)
{
	t_pack	pack;

	pack_init(&pack);
	load_map(&pack.map, "./test_maps/pylone.fdf");
	mlx_key_hook(pack.img.win.win_ptr, handle_input, &pack);
	mlx_loop(pack.img.win.mlx_ptr);
	return (0);
}

/*int main(int argc, char **argv)
{
	char	*path;
	int		fd;
	t_map	map;

	if (argc != 2)
	{
		printf("Path needed\n");
		return (1);
	}
	path = argv[1];
	fd = open("test_maps/42.fdf", O_RDONLY);
	load_map(&map, path);
	printf("x: %d\ny: %d", map.xlen, map.ylen);
	for (int i = 0; i < map.xlen * map.ylen; i++)
	{
		printf("Punto: %i\n x: %i\n y: %i\n z: %i\n color: %i\n", i, map.points[i].x, map.points[i].y, map.points[i].z, map.points[i].color);
	}
}*/
