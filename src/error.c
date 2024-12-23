/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:02:26 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/23 12:58:52 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handle_error(const char *message)
{
	ft_printf("Error: %s\n", message);
	exit(1);
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

int valid_num(const char *str)
{
	int  i;

	i = 0;
	if(*str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if(str[i] == '\0')
		return (0);
	while(str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(int num, t_stack *stack_a)
{
    t_stack *current = stack_a;
    while (current)
    {
        if (current->data == num)
            return 1;  // Duplicate found
        current = current->next;
    }
    return 0;  // No duplicates
}