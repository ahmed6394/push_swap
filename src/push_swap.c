/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:30:58 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 12:52:56 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void print_stack(t_stack *stack)
{
    t_stack *current = stack;
    
    ft_printf("Stack contents: ");
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    ft_printf("\n");
}

int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		parsing_result;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (1);
	parsing_result = start_parsing(ac, av, &stack_a);
	
	// sort(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (1);
}
