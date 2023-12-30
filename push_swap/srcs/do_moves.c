/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 do_moves.c											:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: ilorenzo <ilorenzo@student.42barcel>		+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2023/12/28 09:44:18 by ilorenzo		   #+#	  #+#			  */
/*	 Updated: 2023/12/28 09:44:18 by ilorenzo		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void    reset_moves(t_data **b_stack)
{
    t_data *elem;

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
	while (b_elem->ra)
	{
		ra(a_stack);
		b_elem->ra--;
		printf("ra\n");
	}
	while (b_elem->rb)
	{
		rb(b_stack);
		b_elem->rb--;
		printf("rb\n");
	}
	while (b_elem->rr)
	{
		rr(a_stack, b_stack);
		b_elem->rr--;
		printf("rr\n");
	}
	while (b_elem->rra)
	{
		rra(a_stack);
		b_elem->rra--;
		printf("rra\n");
	}
	while (b_elem->rrb)
	{
		rrb(b_stack);
		b_elem->rrb--;
		printf("rrb\n");
	}
	while (b_elem->rrr)
	{
		rrr(a_stack, b_stack);
		b_elem->rrr--;
		printf("rrr\n");
	}
	pa(a_stack, b_stack);
	printf("pa\n");
}
void	do_moves(t_data **a_stack, t_data **b_stack)
{
	t_data	*min_elem;
	t_data	*elem;
	elem = *a_stack;
	min_elem = get_cheapest(b_stack);

	//print_parallel_lists(*a_stack, *b_stack);
	//printf("min: %d\n", min_elem->val);
	//print_simple(*a_stack, *b_stack);
	read_moves(min_elem, a_stack, b_stack);
	reset_moves(b_stack);
}
