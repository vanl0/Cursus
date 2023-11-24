
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
	int				x0;
	int				y0;
	int				xf;
	int				yf;
	int				dx;
	int				dy;
	int				p;
	unsigned int	color;
}	t_line;
//-MAP--------------------
typedef struct s_point
{
    int             x;
    int             y;
    int             z;
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
	t_map	map;
	t_img_data img;
} t_pack;

#endif