#include "../headers/push_swap.h"

void print_list(t_data* first) {
    printf("Linked List: \n\n");
    while (first) {
        printf("adr: %p\n value: %d\n next: %p\n", first, first->val, first->next);
        first = first->next;
		printf("--------------------------------\n");
    }
}

void print_parallel_lists(t_data* first1, t_data* first2) {
    printf("\n\n");
    printf("%-20s	   | %-20s\n", "Stack A", "Stack B");
    printf("--------------------------------------------------------\n");

    while (first1 && first2) {
        printf("addr: %-20p | addr: %-20p\n", (void*)first1, (void*)first2);
        printf("\033[1;34m""val:  %-20d | val:  %-20d\n", first1->val, first2->val);
		printf("\033[0m""pos:  %-20d | pos:  %-20d\n", first1->pos, first2->pos);
        printf("next: %-20p | next: %-20p\n", (void*)first1->next, (void*)first2->next);
        printf("--------------------------------------------------------\n");

        first1 = first1->next;
        first2 = first2->next;
    }

    // Check if one of the lists is longer than the other
    while (first1 || first2) {
        if (first1) {
            printf("addr: %-20p | addr: %-20p\n", (void*)first1, NULL);
            printf("\033[1;34m""val:  %-20d | val:  %-20s\n", first1->val, "");
			printf("\033[0m""pos:  %-20d | pos:  %-20s\n", first1->pos, "");
            printf("next: %-20p | next: %-20p\n", (void*)first1->next, NULL);
            printf("--------------------------------------------------------\n");
            first1 = first1->next;
        } else {
            printf("addr: %-20p | addr: %-20p\n", NULL, (void*)first2);
            printf("\033[1;34m""val:  %-20s | val:  %-20d\n", "", first2->val);
			printf("\033[0m""pos:  %-20s | pos:  %-20d\n", "", first2->pos);
            printf("next: %-20p | next: %-20p\n", NULL, (void*)first2->next);
            printf("--------------------------------------------------------\n");
            first2 = first2->next;
        }
    }
}


void free_list(t_data* first) {
    while (first) {
        t_data* temp = first;
        first = first->next;
        free(temp);
    }
}

int	main(int argc, char **argv)
{
	int			i;
	t_data	*afirst;
	t_data	*bfirst;

	i = 1;
	if (argc < 3)
	{
		ft_printf("Error\n");
		return (1);
	}
	afirst = NULL;
	bfirst = NULL;
	while (i < argc)
	{
		add_data(&afirst, argv[i]);
		i++;
	}
	/*add_data(&bfirst, "7");
	add_data(&bfirst, "8");
	add_data(&bfirst, "9");
	*/
	print_parallel_lists(afirst, bfirst);
	printf("\n");
	//pb(&afirst, &bfirst);
	//sa(&afirst);
	//sb(&bfirst);
	//ra(&afirst);
	//rb(&bfirst);
	//rr(&afirst, &bfirst);
	//rra(&afirst);
	//rrb(&bfirst);
	//rrr(&afirst, &bfirst);
	index_stack(&afirst);
	radix_sort(&afirst, &bfirst, argc);
	print_parallel_lists(afirst, bfirst);
	if (sorted(&afirst))
		printf("SORTED!!\n");
	else
		printf("NOOOOO!!\n");
	free_list(afirst);
	free_list(bfirst);
	return (0);
}
