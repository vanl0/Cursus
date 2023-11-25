
#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"


void    draw_map(t_map *map, t_img_data *img)
{
    connect_x(map, img);
    //printf("connect_x ✅\n");
    connect_y(map, img);
    //printf("connect_y ✅\n");
    mlx_put_image_to_window(img->win.mlx_ptr, img->win.win_ptr, img->img, 300, 100);
    //printf("image ✅\n");
}
int scale = 20;
void    connect_x(t_map *map, t_img_data *img)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i + 1 < map->xlen * map->ylen)
    {
        //printf("\x1b[31m" "Linea X: %i\n", j);
        while ((i < map->xlen * map->ylen) && j < map->ylen - 1)
        {
            //printf("\x1b[37m" "Linea: p0: %i, p1: %i\n r0: %f, %f\n r1: %f, %f\n", i, i + 1, map->points[i].x, map->points[i].y, map->points[i + 1].x, map->points[i + 1].y);
            draw_line(img, map->points[i], map->points[i + 1], scale);
            i++;
            j++;
        }
        j = 0;
        i++;
    }
}

void    connect_y(t_map *map, t_img_data *img)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < map->xlen * map->ylen - 1)
    {
        i = j;
       // printf("\x1b[31m" "Linea Y: %i\n", j);
        while ((i + map->xlen) < map->xlen * map->ylen)
        {
            //printf("i + xlen = %i, map->xlen * map->ylen = %i\n", i + map->xlen, map->xlen * map->ylen);
            //printf("\x1b[37m" "Linea: p0: %i, p1: %i\n r0: %i, %i\n r1: %i, %i\n", i, i + map->xlen, map->points[i].x, map->points[i].y, map->points[i + map->xlen].x, map->points[i + map->xlen].y);
            draw_line(img, map->points[i], map->points[i + map->xlen], scale);
            i += map->xlen;
        }
        j++;
    }
}