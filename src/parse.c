/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:59 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/18 17:38:54 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Function to parse a single string of numbers separated by spaces
static void parse_str(char *str, int **nums, int *count)
{
    int i;
	int num;
	char **split_args;
	
	i= -1;
    split_args = ft_split(str, ' ');
    if (!split_args)
        handle_error("Failed to split input string");
    *count = 0;
    while (split_args[*count])
        (*count)++;
    *nums = malloc(*count * sizeof(int));
    if (!*nums)
        handle_error("Failed to allocate memory for numbers");
    while (++i < *count)
    {
		if (!valid_num(split_args[i]))
            handle_error("Invalid number format");
        num = ft_atoi(split_args[i]);
        if (is_duplicate(num, *nums, i))
            handle_error("Duplicate number detected");
        (*nums)[i] = num;
        free(split_args[i]);
    }
    free(split_args);
}

void parse_data(int ac, char *av[], int **nums, int *count)
{
    if (ac > 2)
    {
        int i;
		int num;

        *count = ac - 1;
        *nums = malloc(*count * sizeof(int));
        if (!*nums)
        {
            handle_error("Failed to allocate memory for numbers");
        }
        i = 0;
        while (i < *count)
        {
			if (!valid_num(av[i + 1]))
                handle_error("Invalid number format");
            num = ft_atoi(av[i + 1]);
            if (is_duplicate(num, *nums, i))
                handle_error("Duplicate number detected");
            (*nums)[i] = num;
            i++;
        }
    }
    else if (ac == 2)
        parse_str(av[1], nums, count);
}

// Function to initialize stacks and populate stack_a with numbers
void initialize_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int count)
{
    int i;
    t_node *new_node;

    stack_a->top = NULL;
    stack_b->top = NULL;
    stack_a->size = 0;
    stack_b->size = 0;
    i = count - 1;
    while (i >= 0)
    {
        new_node = malloc(sizeof(t_node));
        if (!new_node)
        {
            handle_error("Failed to allocate memory for stack node");
        }
        new_node->value = nums[i];
        new_node->s_index = 0;
        new_node->next = stack_a->top;
        stack_a->top = new_node;
        stack_a->size++;
        i--;
    }
}
