/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:30:58 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/18 16:50:18 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    
    printf("Stack contents: ");
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int main(int ac, char *av[])
{
    t_stack stack_a;
    t_stack stack_b;
    int *nums = NULL;
    int count = 0;

    if (ac == 1)
        exit(0);

    parse_data(ac, av, &nums, &count);
    initialize_stack(&stack_a, &stack_b, nums, count);
    // sort(&stack_a, &stack_b, nums, count);
    print_stack(&stack_a);
    free(nums);
    // free_stack(&stack_a);
    return 0;
}
