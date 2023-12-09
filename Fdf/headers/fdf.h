/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 20:01:58 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/01 10:55:26 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "struct.h"
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>

//READ---------------------------
void	load_map(t_map *map, char *file_path);
char	*read_map(int fd);
void	get_map_size(t_map *map);
//READ_UTILS---------------------
void	set_points(t_map *map);
int		get_color(char *val);
void	check_point(char *val);
void	set_coords(t_map *map, int y, char *line);
//INPUT--------------------------
int		handle_input(int key, t_pack *pack);
int		end(t_pack *pack);
void	redraw(t_pack *pack);
void	move_map(int key, t_pack *pack);
void	move_map_fast(int key, t_pack *pack);
void	z_scale(int key, t_map *map);
void	zoom(int key, t_pack *pack);
//DRAW---------------------------
void	draw_pixel(t_img_data *data, int x, int y, int color);
t_line	line_set(t_point point1, t_point point2, t_map *map);
void	draw_line(t_img_data *img, t_point point1, t_point point2, t_map *map);
t_map	iso_map(t_map *map);
void	to_iso(t_map *map);
void	connect_x(t_map *map, t_img_data *img);
void	connect_y(t_map *map, t_img_data *img);
void	get_limits(t_map *map);
void	draw_map(t_map *map, t_img_data *img);
void	set_scale(t_map *map);
void	set_axis(t_map *map);
//CONTROL------------------------
void	error_end(char *str, void *buff);
void	perror_end(char	*str);
void	matrix_free(char **mat);
void	malloc_fail(char *str);
#endif
