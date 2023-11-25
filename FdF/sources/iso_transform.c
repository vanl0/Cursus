#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

t_map   iso_map(t_map *map)
{
    t_map   iso_map;
    int     i;
    float     x;
    float     y;
    float     z;

    i = 0;
    iso_map.points = ft_calloc(map->xlen * map->ylen, sizeof(t_point));
    while (i < map->xlen * map->ylen)
    {
        x = map->points[i].x;
        y = map->points[i].y;
        z = map->points[i].z;
        iso_map.points[i].x = (x - y) * cos(0.523599);
        iso_map.points[i].y = - z/5 + ((x + y) * sin(0.523599));
        i++;
    }
    iso_map.xlen = map->xlen;
    iso_map.ylen = map->ylen;
    return (iso_map);
}
        //printf("Punto : %i\n x0: %f  y0: %f  z0: %f\n  x: %f   y: %f\n\n", i, x, y, z, iso_map.points[i].x, iso_map.points[i].y);
