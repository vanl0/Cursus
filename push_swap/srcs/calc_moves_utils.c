/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_moves_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:43:49 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/14 17:41:02 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

t_target	get_min_target(t_data **a_stack, t_data *b_elem)
{
	t_data		*a_elem;
	int			min;
	t_target	target;

	a_elem = *a_stack;
	min = a_elem->val;
	target.target_pos = 0;
	target.pos = 0;
	while (a_elem)
	{
		if (a_elem->val < min)
		{
			min = a_elem->val;
			target.target_pos = target.pos;
		}
		target.pos++;
		a_elem = a_elem->next;
	}
	b_elem->target = min;
	return (target);
}
