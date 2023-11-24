
#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

int	handle_input(int key, t_pack *pack)
{
	if (key == 0)
	{
		draw_map(&pack->map, &pack->img);
	}
	if (key == 37)
	{
		t_point	 point1;
		t_point  point2;
		point1.x = rand() % 500;
		point1.y = rand() % 500;
		point2.x = rand() % 500;
		point2.y = rand() % 500;
		printf("p1: x: %i, y: %i\np2: x: %i, y: %i\n", point1.x, point1.y, point2.x, point2.y);
		
		draw_line(&pack->img, point1, point2, 2);
		mlx_put_image_to_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr, &pack->img, 0, 0);
	}
	if (key == 53)
	{
		mlx_destroy_image(pack->img.win.mlx_ptr, pack->img.img);
		mlx_destroy_window(pack->img.win.mlx_ptr, pack->img.win.win_ptr);
		exit (0);
	}
	return (0);
}
