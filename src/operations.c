/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:13:41 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/19 16:02:26 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack *stack1, t_stack *stack2, char identifier, int should_print)
{
	int	index;

	if (stack2->size == NULL)
		return ;
	index = stack2->top->s_index;
	push_stack(stack1, index, pop_stack(stack2));
	if (should_print)
		ft_printf("p%c\n", identifier);
}

void swap(t_stack *stack, char identifier, int should_print)
{
    t_node *first_node;
    t_node *second_node;

    if (!stack || !stack->top || !stack->top->next)
        return;
    first_node = stack->top;
    second_node = first_node->next;
    first_node->next = second_node->next;
    second_node->next = first_node;
    stack->top = second_node;
    if (should_print)
        ft_printf("s%c\n", identifier);
}


void rotate(t_stack *stack, char identifier, int should_print)
{
	t_node *first_node;
	t_node *last_node;

    if (!stack || !stack->top || !stack->top->next)
        return;
	first_node = stack->top;
    last_node = stack->top;
    while (last_node->next)
        last_node = last_node->next;
    stack->top = first_node->next;
    last_node->next = first_node;
    first_node->next = NULL;
    if (should_print)
        ft_printf("r%c\n", identifier);
}
void reverse_rotate(t_stack *stack, char identifier, int should_print)
{
    t_node *last_node;
    t_node *second_last_node;

    if (!stack || !stack->top || !stack->top->next)
        return;
    last_node = stack->top;
    while (last_node->next)
        last_node = last_node->next;
    second_last_node = stack->top;
    while (second_last_node->next != last_node)
        second_last_node = second_last_node->next;
    second_last_node->next = NULL;
    last_node->next = stack->top;
    stack->top = last_node;
    if (should_print)
        ft_printf("rr%c\n", identifier);
}
