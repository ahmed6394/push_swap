/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:30:58 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/19 19:05:15 by gahmed           ###   ########.fr       */
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
        return (0);
    parse_data(ac, av, &nums, &count);
    initialize_stack(&stack_a, &stack_b, nums, count);
	ft_printf("Before sort:");
	print_stack(&stack_a);
    sort(&stack_a, &stack_b, nums, count);
	// reverse_rotate(&stack_a, 'a', count);
	ft_printf("After sort:");
    print_stack(&stack_a);
    free(nums);
    // free_stack(&stack_a);
    return 0;
}
