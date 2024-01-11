/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 calc_moves.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/28 09:44:59 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/28 09:44:59 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	calc_moves_b(int i, int b_len, t_data *b_elem)
{
	if (i <= b_len / 2)
	{
		b_elem->rb = i;
		return (i + 1);
	}
	else
	{
		b_elem->rrb = b_len - i;
		return (b_len - i + 1);
	}
}

t_target	set_target(t_data **a_stack, t_data *b_elem)
{
	t_target	target;
	t_data		*a_elem;

	a_elem = *a_stack;
	target.pos = 0;
	target.target_set = 0;
	while (a_elem)
	{
		if (a_elem->val > b_elem->val)
		{
			if (!target.target_set || a_elem->val < b_elem->target)
			{
				b_elem->target = a_elem->val;
				target.target_pos = target.pos;
				target.target_set = 1;
			}
		}
		a_elem = a_elem->next;
		target.pos++;
	}
	return (target);
}

int	calc_moves_a(t_data **a_stack, t_data *b_elem)
{
	t_target	target;

	target = set_target(a_stack, b_elem);
	if (!target.target_set)
		target = get_min(a_stack, b_elem);
	if (target.target_pos <= target.pos / 2)
	{
		b_elem->ra = target.target_pos;
		return (target.target_pos);
	}
	else
	{
		b_elem->rra = target.pos - target.target_pos;
		return (target.pos - target.target_pos);
	}
}

int	calc_rr(t_data *elem)
{
	if (elem->ra > 0 && elem->rb > 0)
	{
		if (elem->ra >= elem->rb)
			elem->rr = elem->rb;
		else if (elem->ra < elem->rb)
			elem->rr = elem->ra;
		elem->ra -= elem->rr;
		elem->rb -= elem->rr;
		return (elem->rr);
	}
	if (elem->rra > 0 && elem->rrb > 0)
	{
		if (elem->rra >= elem->rrb)
			elem->rrr = elem->rrb;
		else if (elem->rra < elem->rrb)
			elem->rrr = elem->rra;
		elem->rra -= elem->rrr;
		elem->rrb -= elem->rrr;
		return (elem->rrr);
	}
	return (0);
}

void	set_moves(t_data **a_stack, t_data **b_stack)
{
	int		b_len;
	int		a_len;
	int		i;
	t_data	*b_elem;

	a_len = get_stack_len(a_stack);
	b_len = get_stack_len(b_stack);
	b_elem = *b_stack;
	i = 0;
	while (b_elem)
	{
		b_elem->moves = calc_moves_b(i, b_len, b_elem) + \
		calc_moves_a(a_stack, b_elem) - calc_rr(b_elem);
		b_elem = b_elem->next;
		i++;
	}
}
