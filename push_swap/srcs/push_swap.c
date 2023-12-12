#include "../headers/push_swap.h"

void print_list(t_data_a* first) {
    printf("Linked List: \n\n");
    while (first) {
        printf("adr: %p\n value: %d\n next: %p\n", first, first->val, first->next);
        first = first->next;
		printf("--------------------------------\n");
    }
}

void free_list(t_data_a* first) {
    while (first) {
        t_data_a* temp = first;
        first = first->next;
        free(temp);
    }
}

int	main(int argc, char **argv)
{
	int			i;
	t_data_a	*afirst;

	i = 1;
	if (argc < 3)
	{
		ft_printf("Error\n");
		return (1);
	}
	afirst = NULL;
	while (i < argc)
	{
		add_data(&afirst, argv[i]);
		i++;
	}
	print_list(afirst);
	free_list(afirst);
	return (0);
}
