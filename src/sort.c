/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:14:24 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/23 12:28:10 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int count;

	count = stack_size(*stack_a);
	if (is_sorted(*stack_a))
	{
		// free(stack_a->data);
		// free_stack(stack_a);
		handle_error("Stack is sorted");
	}
	else if (count == 2)
		swap(*stack_a, 'a');
	else if (count == 3)
		simple_sort(stack_a);
	else if (count > 7)
	{
		//turk_algoritham;
	}
	else
		handle_error("");
}

int	is_sorted(t_stack *stack)
{
	t_stack	*temp;
	
	 if (!stack || !stack->next)
        return (1);
	temp = stack;
	while(temp->next)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void simple_sort(t_stack **stack)
{
    int a, b, c;

    if (is_sorted(*stack))
        return;
    a = (*stack)->data;
    b = (*stack)->next->data;
    c = (*stack)->next->next->data;
    if (a > b && b < c && a < c)
        swap(*stack, 'a');
    else if (a > b && b > c && a > c)
	{
        swap(*stack, 'a');
        reverse_rotate(stack, 'a');
    }
    else if (a > b && b < c && a > c)
        rotate(stack, 'a');
    else if (a < b && b > c && a < c)
	{
        swap(*stack, 'a');
        rotate(stack, 'a');
    }
    else if (a < b && b > c && a > c)
        reverse_rotate(stack, 'a');
}

