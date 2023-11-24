/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:00:29 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/11/22 09:01:04 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/Libft/libft.h"
#include "../libs/minilibx_macos/mlx.h"
#include "../headers/fdf.h"
#include <errno.h>

void	error_end(char	*str)
{
	perror(str);
	exit(1);
}

void	matrix_free(char	**mat)
{
	int	j;

	j = 0;
	while (mat[j])
	{
		free(mat[j]);
		j++;
	}
	free(mat);
}
