/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:23:30 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/13 13:25:04 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ra(t_data **afirst)
{
	t_data	*tmp;
	t_data	*elem;

	if (!afirst || !(*afirst)->next)
		return ;
	tmp = *afirst;
	elem = *afirst;
	*afirst = (*afirst)->next;
	while (elem->next)
		elem = elem->next;
	elem->next = tmp;
	tmp->next = NULL;
}

void	rb(t_data **bfirst)
{
	t_data	*tmp;
	t_data	*elem;

	tmp = *bfirst;
	elem = *bfirst;
	*bfirst = (*bfirst)->next;
	while (elem->next)
		elem = elem->next;
	elem->next = tmp;
	tmp->next = NULL;
}

void	rr(t_data **afirst, t_data **bfirst)
{
	ra(afirst);
	rb(bfirst);
}
