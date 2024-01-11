/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:40:13 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/10 11:13:27 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	reset_moves(t_data **b_stack)
{
	t_data	*elem;

	elem = *b_stack;
	while (elem)
	{
		elem->rb = 0;
		elem->rrb = 0;
		elem->ra = 0;
		elem->rra = 0;
		elem->rr = 0;
		elem->rrr = 0;
		elem->target = 0;
		elem->moves = 0;
		elem = elem->next;
	}
}

t_data	*get_cheapest(t_data **b_stack)
{
	t_data	*elem;
	t_data	*min_elem;

	elem = *b_stack;
	min_elem = elem;
	while (elem)
	{
		if (min_elem->moves > elem->moves)
			min_elem = elem;
		elem = elem->next;
	}
	return (min_elem);
}

void	read_moves(t_data *b_elem, t_data **a_stack, t_data **b_stack)
{
	do_r(b_elem, a_stack, b_stack);
	do_rr(b_elem, a_stack, b_stack);
	pa(a_stack, b_stack);
	ft_printf("pa\n");
}

void	do_moves(t_data **a_stack, t_data **b_stack)
{
	t_data	*min_elem;
	t_data	*elem;

	elem = *a_stack;
	min_elem = get_cheapest(b_stack);
	read_moves(min_elem, a_stack, b_stack);
	reset_moves(b_stack);
}
