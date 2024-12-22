/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:19:41 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 19:38:53 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack, char stack_name)
{
	int	temp;

	if (stack_size(stack) <= 1)
	{
		return ;
	}
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	if (ft_isalpha(stack_name))
	{
		ft_printf("s%c\n", stack_name);
	}
}

// ss
void	swap_both(t_stack *a, t_stack *b, int print)
{
	swap(a, '0');
	swap(b, '0');
	if (print == 1)
	{
		ft_printf("ss\n");
	}
}

t_stack *last_node(t_stack *stack)
{
    t_stack *last_entry;

    if (stack == NULL)
        return NULL;
    last_entry = stack;
    while (last_entry->next != NULL)
    {
        last_entry = last_entry->next;
    }
    return last_entry;
}

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