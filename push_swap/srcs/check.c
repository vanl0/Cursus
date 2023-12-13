/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilorenzo <ilorenzo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:21:46 by ilorenzo          #+#    #+#             */
/*   Updated: 2023/12/13 13:22:26 by ilorenzo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	sorted(t_data **afirst)
{
	int		maxval;
	t_data	*elem;

	if (!afirst || !*afirst)
		return (0);
	elem = *afirst;
	maxval = elem->val;
	elem = elem->next;
	while (elem)
	{
		if (elem->val < maxval)
			return (0);
		maxval = elem->val;
		elem = elem->next;
	}
	return (1);
}
