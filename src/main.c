/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:39:10 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/21 18:37:59 by gahmed           ###   ########.fr       */
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

int main(int ac, char *av[])
{
    t_stack stack_a;
    t_stack stack_b;
    int *nums = NULL;
    int count = check_digits(ac, av);

    if (ac == 1)
        return (0);
    parse_data(ac, av, &nums, count);
    initialize_stack(&stack_a, &stack_b, nums, count);
	ft_printf("Before sort:");
	print_stack(&stack_a);
    sort(&stack_a, &stack_b, nums, count);
	// reverse_rotate(&stack_a, 'a', count);
	ft_printf("After sort:");
    print_stack(&stack_a);
    free(nums);
    // free_stack(&stack_a);
    return 0;
}
