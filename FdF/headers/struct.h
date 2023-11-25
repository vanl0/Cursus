
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
    float           x;
    float           y;
    float           z;
    int             color;
}   t_point;

typedef struct s_map
{
    t_point *points;
    int     xlen;
    int     ylen;

    char    *str;
}   t_map;

typedef struct s_pack
{
	t_map		map;
	t_img_data	img;
	int			scale;
	int			ox;
	int			oy;
} t_pack;

#endif