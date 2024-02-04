/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_moves_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 19:01:30 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/14 17:42:00 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	do_r(t_data *b_elem, t_data **a_stack, t_data **b_stack)
{
	while (b_elem->ra)
	{
		ra(a_stack);
		b_elem->ra--;
		ft_printf("ra\n");
	}
	while (b_elem->rb)
	{
		rb(b_stack);
		b_elem->rb--;
		ft_printf("rb\n");
	}
	while (b_elem->rr)
	{
		rr(a_stack, b_stack);
		b_elem->rr--;
		ft_printf("rr\n");
	}
}

void	do_rr(t_data *b_elem, t_data **a_stack, t_data **b_stack)
{
	while (b_elem->rra)
	{
		rra(a_stack);
		b_elem->rra--;
		ft_printf("rra\n");
	}
	while (b_elem->rrb)
	{
		rrb(b_stack);
		b_elem->rrb--;
		ft_printf("rrb\n");
	}
	while (b_elem->rrr)
	{
		rrr(a_stack, b_stack);
		b_elem->rrr--;
		ft_printf("rrr\n");
	}
}
