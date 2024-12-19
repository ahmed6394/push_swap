/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:14:31 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/18 17:54:05 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	index_of(int n, int *arr)
{
	int	i;

	i = 0;
	while (arr[i] != n)
		i++;
	return (i);
}
void	push_stack(t_stack *stack, int index, int data)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->value = data;
	tmp->s_index = index;
	tmp->next = stack->top;
	stack->top = tmp;
	stack->size++;
}

int	pop_stack(t_stack *stack)
{
	t_node	*top;
	int		value;

	if (!stack->top)
		exit(1);
	top = stack->top;
	value = top->value;
	stack->top = top->next;
	free(top);
	top = NULL;
	stack->size--;
	return (value);
}