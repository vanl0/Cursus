/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:25:59 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/13 13:26:34 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	sa(t_data **afirst)
{
	t_data	temp;

	temp = **afirst;
	if ((*afirst)->next)
	{
		(*afirst)->val = (*afirst)->next->val;
		(*afirst)->pos = 0;
		(*afirst)->next->val = temp.val;
		(*afirst)->next->pos = 1;
	}
}

void	sb(t_data **bfirst)
{
	t_data	temp;

	temp = **bfirst;
	if ((*bfirst)->next)
	{
		(*bfirst)->val = (*bfirst)->next->val;
		(*bfirst)->pos = 0;
		(*bfirst)->next->val = temp.val;
		(*bfirst)->next->pos = 1;
	}
}

void	ss(t_data **afirst, t_data **bfirst)
{
	sa(afirst);
	sb(bfirst);
}
