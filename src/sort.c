/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 16:14:24 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/19 16:56:15 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort(t_stack *stack_a, t_stack *stack_b, int *nums, int count)
{
	if (is_sorted(stack_a))
	{
		// free and retuen
	}
	else if (count == 2)
	{
		swap(stack_a, 'a', 1);
	}
	else if (count == 3)
	{
		//simple sort_a
	}
	else if (count <= 7)
	{
		//do onother sort
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
	return (0);
}