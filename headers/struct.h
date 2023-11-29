/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 11:00:05 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/29 11:02:47 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
//STRUCTS--------------------------
//-MLX-------------------
typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx_data;

typedef struct s_img_data
{
	t_mlx_data	win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	float		scale;
}	t_img_data;
//-DRAW-------------------
typedef struct s_line
{
	float			dx;
	float			dy;
	int				pixels;
	float			xstep;
	float			ystep;
	unsigned int	color;
}	t_line;
//-MAP--------------------
typedef struct s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
}	t_point;

typedef struct s_map
{
	t_point	*points;
	int		xlen;
	int		ylen;
	char	*str;
	float	x_min;
	float	y_min;
	float	x_max;
	float	y_max;
	int		iso_xlen;
	int		iso_ylen;
	int		ox;
	int		oy;
	float	scale;
	float	z_scale;
}	t_map;

typedef struct s_pack
{
	t_map		map;
	t_img_data	img;
	int			img_x;
	int			img_y;
}	t_pack;

#endif
