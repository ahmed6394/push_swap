/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:30:58 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/17 17:07:42 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main (int ac, char *av[])
{
	t_stack stack_a;
	t_stack stack_b;
	int nums;
	int count;
	
	if (ac == 1)
		exit(0);
	initialize_stack(&stack_a, &stack_b, nums, count);
	return (0);
}

void intialize_stack(t_stack *stack_a, t_stack *stack_b, int nums, int count)
{
	t_node *temp;

	stack_a->top = NULL;
	stack_b->top = NULL;
	stack_a->size = 0;
	stack_b->size = 0;
	temp = stack_a->top;
}
