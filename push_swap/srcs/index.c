#include "../headers/push_swap.h"

t_data	*get_next_min(t_data **stack)
{
	t_data	*head;
	t_data	*min;

	min = NULL;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((!head->pos) && ( head->val < min->val))
			{
				min = head;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_data **stack)
{
	t_data	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->pos = index++;
		head = get_next_min(stack);
	}
}
