/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 18:19:41 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/21 18:27:12 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack *stack, char stack_name)
{
	int	temp;

	if (ft_lstsize_ps(stack) <= 1)
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