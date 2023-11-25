
#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

int	handle_input(int key, t_pack *pack)
{
	if (key == 34)
	{
		t_map imap;
		imap = iso_map(&pack->map);
		draw_map(&imap, &pack->img);
	}
	if (key == 0)
	{
		draw_map(&pack->map, &pack->img);
	}
	if (key == 53)
	{
		mlx_destroy_image(pack->img.win.mlx_ptr, pack->img.img);
		mlx_destroy_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr);
		exit (0);
	}
	if (key == 2)
	{
		mlx_clear_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr);
		mlx_destroy_image(pack->img.win.mlx_ptr, pack->img.img);
		pack->img.img =  mlx_new_image(pack->img.win.mlx_ptr, 2500, 1300);
		pack->img.addr = mlx_get_data_addr(pack->img.img, &pack->img.bits_per_pixel, &pack->img.line_length, &pack->img.endian);
	}
	return (0);
}

/*	if (key == 37)
	{
		t_point	 point1;
		t_point  point2;
		point1.x = rand() % 100;
		point1.y = rand() % 100;
		point2.x = rand() % 100;
		point2.y = rand() % 100;

		draw_line(&pack->img, point1, point2, pack->scale);
		mlx_put_image_to_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr, &pack->img, 0, 0);
	}*/