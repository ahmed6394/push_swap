/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:14:31 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/23 12:59:38 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int stack_size(t_stack *stack)
{
	int i;

	i = 0;
	while(stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	get_stack_size(t_stack *stack)
{
	int	size;

	while (stack)
	{
		size = stack->index;
		stack = stack->next;
	}
	return (size + 1);
}

t_stack	*get_max(t_stack *stack)
{
	t_stack	*max;

	max = stack;
	while (stack)
	{
		if (max->data < stack->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack	*get_min(t_stack *stack)
{
	t_stack	*min;

	min = stack;
	while (stack)
	{
		if (min->data > stack->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*cheapest;

	cheapest = stack;
	while (stack)
	{
		if (stack->push_cost < cheapest->push_cost)
		{
			cheapest = stack;
		}
		stack = stack->next;
	}
	return (cheapest);
}
