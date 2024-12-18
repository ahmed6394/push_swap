/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:10 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/18 15:45:01 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void handle_error(const char *message)
{
    if (message)
        ft_printf("Error: %s\n", message);
    else
        ft_printf("Error: An unknown error occurred.\n");
    exit(EXIT_FAILURE);
}

static void print_stack(t_stack *stack)
{
    t_node *current = stack->top;
    printf("Stack contents: ");
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

void parse_and_initialize(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b)
{
    int *nums = NULL;
    int count = 0;

    if (argc == 2)
    {
        // Single string input: "./push_swap '3 2 1'"
        char **split_args = ft_split(argv[1], ' ');
        if (!split_args)
            handle_error("Failed to split input string");

        // Count the number of split arguments
        while (split_args[count])
            count++;

        // Allocate memory for numbers
        nums = malloc(count * sizeof(int));
        if (!nums)
            handle_error("Failed to allocate memory for numbers");

        // Convert split strings to integers
        for (int i = 0; i < count; i++)
        {
            nums[i] = ft_atoi(split_args[i]);
            free(split_args[i]); // Free each split string after conversion
        }
        free(split_args); // Free the array of strings
    }
    else if (argc > 2)
    {
        // Multiple arguments: "./push_swap 3 2 1"
        count = argc - 1;
        nums = malloc(count * sizeof(int));
        if (!nums)
            handle_error("Failed to allocate memory for numbers");

        // Convert arguments to integers
        for (int i = 0; i < count; i++)
        {
            nums[i] = ft_atoi(argv[i + 1]);
        }
    }
    else
    {
        // No input provided
        handle_error("No input provided");
    }

    // Initialize stacks
    stack_a->top = NULL;
    stack_b->top = NULL;
    stack_a->size = 0;
    stack_b->size = 0;

    // Populate stack_a with numbers
    for (int i = count - 1; i >= 0; i--)
    {
        t_node *new_node = malloc(sizeof(t_node));
        if (!new_node)
            handle_error("Failed to allocate memory for stack node");

        new_node->value = nums[i];
        new_node->s_index = 0; // Initialize as needed
        new_node->next = stack_a->top;
        stack_a->top = new_node;
        stack_a->size++;
    }

    free(nums);
}

int main(int argc, char *argv[])
{
    t_stack stack_a;
    t_stack stack_b;

    if (argc == 1)
        handle_error("No input provided");

    parse_and_initialize(argc, argv, &stack_a, &stack_b);
    print_stack(&stack_a);

    // Free the stack after usage
    // free_stack(&stack_a);

    return 0;
}
