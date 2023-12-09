/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:58:57 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/29 10:10:41 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"

long	hex_to_long(const char *hex_string)
{
	long	result;
	int		val;
	int		i;

	result = 0;
	i = 0;
	if (hex_string[0] == '0' && (hex_string[1] == 'x' || hex_string[1] == 'X'))
		i = 2;
	while (hex_string[i])
	{
		if (hex_string[i] >= '0' && hex_string[i] <= '9')
			val = hex_string[i] - '0';
		else if (hex_string[i] >= 'a' && hex_string[i] <= 'f')
			val = 10 + hex_string[i] - 'a';
		else if (hex_string[i] >= 'A' && hex_string[i] <= 'F')
			val = 10 + hex_string[i] - 'A';
		else
			error_end("Hexadecimal invalido\n", NULL);
		result = result * 16 + val;
		i++;
	}
	return (result);
}

void	check_point(char *val)
{
	int	i;

	i = 0;
	if (*val == '-' || *val == '+' || ft_isdigit(val[i]))
		i++;
	while (ft_isdigit(val[i]))
		i++;
	if (val[i] != ',' && val[i] != '\0')
		error_end("Puntos invalidos", NULL);
}

int	get_color(char *val)
{
	char	**split_val;
	int		color;

	if (ft_strchr(val, ','))
	{
		split_val = ft_split(val, ',');
		color = hex_to_long(split_val[1]);
		matrix_free(split_val);
		return (color);
	}
	else
	{
		if (val[0] > '0')
			return (0xffffff);
	}
	return (0xffffff);
}

/*	else
	{
		if (ft_atoi(&val[0]) > 0)
			return (0x00ff00);
	}
		return (0x00ccff);
}*/

void	set_coords(t_map *map, int y, char	*line)
{
	int		i;
	int		j;
	char	**split_line;

	i = y * map->xlen;
	j = 0;
	split_line = ft_split(line, ' ');
	while (split_line[j])
	{
		check_point(split_line[j]);
		map->points[i].x = j;
		map->points[i].y = y;
		map->points[i].z = ft_atoi(split_line[j]);
		map->points[i].color = get_color(split_line[j]);
		i++;
		j++;
	}
	matrix_free(split_line);
}
