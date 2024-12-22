/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:14:24 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 19:58:38 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int count;

	count = stack_size(*stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		handle_error("Stack is sorted");
	}
	else if (count == 2)
	{
		swap(stack_a, 'a');
	}
	else if (count == 3)
	{
		//simple sort_a
	}
	else if (count > 7)
	{
		//sort using k-sort algorithm
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

// void simple_sort(t_stack *stack, int length)
// {
//     int min_index;
//     int rotations;

//     if (is_sorted(stack))
//         return;
//     min_index = get_min_index(stack);
//     rotations = count_rotations(stack->top, min_index);
//     if (is_rotation_sorted(stack, min_index))
//     {
//         if (rotations < length - rotations)
//             rotate(stack, 'a', 1);
//         else
//             reverse_rotate(stack, 'a', 1);
//     }
//     else
//     {
//         swap(stack, 'a', 1);
//         if (is_sorted(stack))
//             return;
//         if (rotations < length - rotations)
//             rotate(stack, 'a', 1);
//         else
//             reverse_rotate(stack, 'a', 1);
//     }
// }