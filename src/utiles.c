/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:14:31 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 18:56:33 by gahmed           ###   ########.fr       */
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

void free_stack(t_stack *stack)
{
    t_stack *temp;

    while (stack)
    {
        temp = stack->next;
        free(stack);
        stack = temp;
    }
}
