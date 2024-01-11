#include "../headers/push_swap.h"

void print_parallel_lists(t_data* first1, t_data* first2) {
    printf("\n\n");
    printf("%-20s	   | %-20s\n", "Stack A", "Stack B");
    printf("--------------------------------------------------------\n");

    while (first1 && first2) {
        printf("addr: %-20p | addr: %-20p\n", (void*)first1, (void*)first2);
        printf("\033[1;34m""val:  %-20d | val:  %-20d\n", first1->val, first2->val);
        printf("\033[0m""tar:  %-20d | tar:  %-20d\n", first1->target, first2->target);
		printf("mov:  %-20d | mov:  %-20d\n", first1->moves, first2->moves);
        printf("rb :  %-20d | rb :  %-20d\n", first1->rb, first2->rb);
        printf("rrb:  %-20d | rrb:  %-20d\n", first1->rrb, first2->rrb);
        printf("ra :  %-20d | ra :  %-20d\n", first1->ra, first2->ra);
        printf("rra:  %-20d | rra:  %-20d\n", first1->rra, first2->rra);
        printf("rr:  %-20d  | rr:   %-20d\n", first1->rr, first2->rr);
        printf("rrr:  %-20d | rrr:  %-20d\n", first1->rrr, first2->rrr);
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
            printf("\033[0m""tar:  %-20d | tar:  %-20s\n", first1->target, "");
			printf("mov:  %-20d | mov:  %-20s\n", first1->moves, "");
            printf("rb :  %-20d | rb :  %-20s\n", first1->rb, "");
            printf("rrb:  %-20d | rrb:  %-20s\n", first1->rrb, "");
            printf("ra :  %-20d | ra :  %-20s\n", first1->ra, "");
            printf("rra:  %-20d | rra:  %-20s\n", first1->rra, "");
            printf("rr:  %-20d  | rr:   %-20s\n", first1->rr, "");
            printf("rrr:  %-20d | rrr:  %-20s\n", first1->rrr, "");
            printf("next: %-20p | next: %-20p\n", (void*)first1->next, NULL);
            printf("--------------------------------------------------------\n");
            first1 = first1->next;
        } else {
            printf("addr: %-20p | addr: %-20p\n", NULL, (void*)first2);
            printf("\033[1;34m""val:  %-20s | val:  %-20d\n", "", first2->val);
            printf("\033[0m""tar:  %-20s | tar:  %-20d\n", "", first2->target);
			printf("mov:  %-20s | mov:  %-20d\n", "", first2->moves);
            printf("rb :  %-20s | rb :  %-20d\n", "",  first2->rb);
            printf("rrb:  %-20s | rrb:  %-20d\n", "", first2->rrb);
            printf("ra :  %-20s | ra :  %-20d\n", "", first2->ra);
            printf("rra:  %-20s | rra:  %-20d\n", "", first2->rra);
            printf("rr:  %-20s  | rr:   %-20d\n", "", first2->rr);
            printf("rrr:  %-20s | rrr:  %-20d\n", "", first2->rrr);
            printf("next: %-20p | next: %-20p\n", NULL, (void*)first2->next);
            printf("--------------------------------------------------------\n");
            first2 = first2->next;
        }
    }
}

void print_simple(t_data* first1, t_data* first2) {
    printf("\n\n");
    printf("%-20s	   | %-20s\n", "Stack A", "Stack B");
    printf("--------------------------------------------------------\n");

    while (first1 && first2) {
        //printf("addr: %-20p | addr: %-20p\n", (void*)first1, (void*)first2);
        printf("\033[1;34m""val:  %-20d | val:  %-20d\n", first1->val, first2->val);
        printf("\033[0m""tar:  %-20d | tar:  %-20d\n", first1->target, first2->target);
		//printf("mov:  %-20d | mov:  %-20d\n", first1->moves, first2->moves);
        //printf("rb :  %-20d | rb :  %-20d\n", first1->rb, first2->rb);
        //printf("rrb:  %-20d | rrb:  %-20d\n", first1->rrb, first2->rrb);
        //printf("ra :  %-20d | ra :  %-20d\n", first1->ra, first2->ra);
        //printf("rra:  %-20d | rra:  %-20d\n", first1->rra, first2->rra);
        //printf("rr:  %-20d  | rr:   %-20d\n", first1->rr, first2->rr);
        //printf("rrr:  %-20d | rrr:  %-20d\n", first1->rrr, first2->rrr);
        //printf("next: %-20p | next: %-20p\n", (void*)first1->next, (void*)first2->next);
        printf("--------------------------------------------------------\n");

        first1 = first1->next;
        first2 = first2->next;
    }

    // Check if one of the lists is longer than the other
    while (first1 || first2) {
        if (first1) {
            //printf("addr: %-20p | addr: %-20p\n", (void*)first1, NULL);
            printf("\033[1;34m""val:  %-20d | val:  %-20s\n", first1->val, "");
            printf("\033[0m""tar:  %-20d | tar:  %-20s\n", first1->target, "");
			/*printf("mov:  %-20d | mov:  %-20s\n", first1->moves, "");
            printf("rb :  %-20d | rb :  %-20s\n", first1->rb, "");
            printf("rrb:  %-20d | rrb:  %-20s\n", first1->rrb, "");
            printf("ra :  %-20d | ra :  %-20s\n", first1->ra, "");
            printf("rra:  %-20d | rra:  %-20s\n", first1->rra, "");
            printf("rr:  %-20d  | rr:   %-20s\n", first1->rr, "");
            printf("rrr:  %-20d | rrr:  %-20s\n", first1->rrr, "");
            printf("next: %-20p | next: %-20p\n", (void*)first1->next, NULL);*/
            printf("--------------------------------------------------------\n");
            first1 = first1->next;
        } else {
            //printf("addr: %-20p | addr: %-20p\n", NULL, (void*)first2);
            printf("\033[1;34m""val:  %-20s | val:  %-20d\n", "", first2->val);
            printf("\033[0m""tar:  %-20s | tar:  %-20d\n", "", first2->target);
			/*printf("mov:  %-20s | mov:  %-20d\n", "", first2->moves);
            printf("rb :  %-20s | rb :  %-20d\n", "",  first2->rb);
            printf("rrb:  %-20s | rrb:  %-20d\n", "", first2->rrb);
            printf("ra :  %-20s | ra :  %-20d\n", "", first2->ra);
            printf("rra:  %-20s | rra:  %-20d\n", "", first2->rra);
            printf("rr:  %-20s  | rr:   %-20d\n", "", first2->rr);
            printf("rrr:  %-20s | rrr:  %-20d\n", "", first2->rrr);
            printf("next: %-20p | next: %-20p\n", NULL, (void*)first2->next);*/
            printf("--------------------------------------------------------\n");
            first2 = first2->next;
        }
    }
}