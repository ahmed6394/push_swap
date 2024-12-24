/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:59 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/24 14:18:03 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	add_to_stack(t_stack **stack_a, int num)
{
	t_stack	*new_node;
	t_stack	*last;

	if (is_duplicate(num, *stack_a))
		handle_error();
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		handle_error();
	new_node->data = num;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = 0;
	new_node->name = 'A';
	new_node->target = NULL;
	new_node->next = NULL;
	if (*stack_a == NULL)
		*stack_a = new_node;
	else
	{
		last = *stack_a;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
}

static void	parse_str(char *str, t_stack **stack_a, int *count)
{
	int		i;
	int		num;
	char	**split_args;

	i = 0;
	split_args = ft_split(str, ' ');
	if (!split_args)
		handle_error();
	*count = 0;
	while (split_args[*count])
		(*count)++;
	while (split_args[i])
	{
		if (!valid_num(split_args[i]))
			handle_error();
		num = ft_atoi(split_args[i]);
		add_to_stack(stack_a, num);
		free(split_args[i]);
		i++;
	}
	free(split_args);
}

void	parse_data(int ac, char *av[], t_stack **stack_a, int *count)
{
	int	num;
	int	i;

	if (ac > 2)
	{
		*count = ac - 1;
		i = 1;
		while (i <= *count)
		{
			if (!valid_num(av[i]))
				handle_error();
			num = ft_atoi(av[i]);
			add_to_stack(stack_a, num);
			i++;
		}
	}
	else if (ac == 2)
		parse_str(av[1], stack_a, count);
	if (is_sorted(*stack_a))
	{
		free_stack(*stack_a);
		exit(0);
	}
}
