/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:22:48 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/14 17:40:12 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	pa(t_data **afirst, t_data **bfirst)
{
	t_data	*tmp;

	if (bfirst && (*bfirst))
	{
		tmp = (*bfirst)->next;
		(*bfirst)->next = *afirst;
		*afirst = *bfirst;
		*bfirst = tmp;
	}
}

void	pb(t_data **afirst, t_data **bfirst)
{
	t_data	*tmp;

	if (afirst && (*afirst))
	{
		tmp = (*afirst)->next;
		(*afirst)->next = *bfirst;
		*bfirst = *afirst;
		*afirst = tmp;
	}
}
