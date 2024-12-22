/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:59 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 19:45:00 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// Helper function to handle node creation and insertion into the stack
static void add_to_stack(t_stack **stack_a, int num)
{
    t_stack *new_node;

    if (is_duplicate(num, *stack_a))
        handle_error("Duplicate number detected");
    new_node = malloc(sizeof(t_stack));
    if (!new_node)
        handle_error("Failed to allocate memory for stack node");
    new_node->data = num;
    new_node->index = 0;            // We'll set index later
    new_node->push_cost = 0;        // Initial cost is 0
    new_node->above_median = 0;     // Default value
    new_node->name = 'A';           // Assuming name for stack 'A'
    new_node->target = NULL;        // Target pointer can be set later
    new_node->next = *stack_a;
    *stack_a = new_node;
}

// Function to handle parsing for a single string input
static void parse_str(char *str, t_stack **stack_a, int *count)
{
    int i;
    int num;
    char **split_args;

    i = -1;
    split_args = ft_split(str, ' ');
    if (!split_args)
        handle_error("Failed to split input string");
    *count = 0;
    while (split_args[*count])
        (*count)++;
    while (++i < *count)
    {
        if (!valid_num(split_args[i]))
            handle_error("Invalid number format");

        num = ft_atoi(split_args[i]);
        add_to_stack(stack_a, num);
        free(split_args[i]);
    }
    free(split_args);  // Don't forget to free the array
}

// Function to parse multiple arguments
void parse_data(int ac, char *av[], t_stack **stack_a, int *count)
{
    if (ac > 2)
    {
        int num;

        *count = ac - 1;
        while (*count > 0)
        {
            if (!valid_num(av[*count]))
                handle_error("Invalid number format");
            num = ft_atoi(av[*count]);
            add_to_stack(stack_a, num);

            (*count)--;
        }
    }
    else if (ac == 2)
        parse_str(av[1], stack_a, count);
}



