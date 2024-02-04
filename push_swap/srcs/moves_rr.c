/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:25:17 by ilorenzo          #+#    #+#             */
/*   Updated: 2024/01/14 17:40:23 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	rra(t_data **afirst)
{
	t_data	*tmp;
	t_data	*tmp2;

	tmp = *afirst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *afirst;
	*afirst = tmp2;
}

void	rrb(t_data **bfirst)
{
	t_data	*tmp;
	t_data	*tmp2;

	tmp = *bfirst;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *bfirst;
	*bfirst = tmp2;
}

void	rrr(t_data **afirst, t_data **bfirst)
{
	rra(afirst);
	rrb(bfirst);
}
