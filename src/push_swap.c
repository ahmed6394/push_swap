/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:30:58 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/24 14:13:09 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// static void print_stack(t_stack *stack)
// {
//     t_stack	*current;
// 	current = stack;
//     ft_printf("Stack contents: ");
//     while (current) {
//         ft_printf("%d ", current->data);
//         current = current->next;
//     }
//     ft_printf("\n");
// }
int	main(int ac, char *av[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		count;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	parse_data(ac, av, &stack_a, &count);
	if (!stack_a || stack_size(stack_a) < 2)
		return (0);
	sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
