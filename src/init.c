/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:24:53 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/23 15:24:14 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_stack_basics(t_stack *stack, char stack_name)
{
	int	i;
	int	median;

	if (stack == NULL)
		return ;
	i = 0;
	median = ft_lstsize_ps(stack) / 2;
	while (stack)
	{
		stack->name = stack_name;
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		i++;
		stack = stack->next;
	}
}

static void	find_target_in_b(t_stack *a, t_stack *b)
{
	t_stack	*temp_b;
	t_stack	*closest;
	int		min_diff;

	while (a)
	{
		closest = NULL;
		min_diff = INT_MAX;
		temp_b = b;
		while (temp_b)
		{
			if (temp_b->data < a->data && (a->data - temp_b->data) < min_diff)
			{
				closest = temp_b;
				min_diff = a->data - temp_b->data;
			}
			temp_b = temp_b->next;
		}
		if (!closest)
		{
			closest = get_max(b);
		}
		a->target = closest;
		a = a->next;
	}
}

static void	calc_push_cost(t_stack *a, t_stack *b)
{
	int	cost_a;
	int	cost_b;

	while (a)
	{
		if (a->above_median)
			cost_a = a->index;
		else
			cost_a = get_stack_size(a) - a->index;
		if (a->target->above_median)
			cost_b = a->target->index;
		else
			cost_b = get_stack_size(b) - a->target->index;
		if (a->above_median == a->target->above_median)
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

static void	find_target_in_a(t_stack *b, t_stack *a)
{
	t_stack	*closest;
	t_stack	*temp_a;
	int		min_diff;

	temp_a = a;
	closest = NULL;
	min_diff = INT_MAX;
	while (temp_a)
	{
		if (temp_a->data > b->data && (temp_a->data - b->data) < min_diff)
		{
			closest = temp_a;
			min_diff = temp_a->data - b->data;
		}
		temp_a = temp_a->next;
	}
	if (!closest)
	{
		closest = get_min(a);
	}
	b->target = closest;
}

void	init_stack(t_stack *from, t_stack *to, char name_from, char name_to)
{
	init_stack_basics(from, name_from);
	init_stack_basics(to, name_to);
	if (name_from == 'a')
	{
		find_target_in_b(from, to);
		calc_push_cost(from, to);
	}
	else
	{
		find_target_in_a(from, to);
	}
}