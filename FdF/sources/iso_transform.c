#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

t_map   iso_map(t_map *map)
{
    t_map   iso_map;
    int     i;
    int     x;
    int     y;
    int     z;

    i = 0;
    iso_map.points = ft_calloc(map->xlen * map->ylen, sizeof(t_point));
    while (i < map->xlen * map->ylen)
    {
        x = map->points[i].x;
        y = map->points[i].y;
        z = map->points[i].z;
        iso_map.points[i].x = (x - z) * cos(0.46365);
        iso_map.points[i].y = -(y + (x + z) * sin(0.46365));
        i++;
    }
    iso_map.xlen = map->xlen;
    iso_map.ylen = map->ylen;
    return (iso_map);
}