/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:51 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/19 16:46:35 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../gnl/get_next_line.h"

# define MALLOC				"faild to allocate mem"
# define INVALID_IN			"Input is not valid"
# define FILE_ERROR			"Can not to open the file"
typedef struct s_node
{
	int	value;
	int s_index;
	struct s_node *next;
} t_node;

typedef struct s_stack
{
	t_node *top;
	int size;
}t_stack;

void	parse_data(int ac, char *av[], int **nums, int *count);
void 	initialize_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int count);
void	handle_error(const char *message);
int		index_of(int n, int *arr);
void	handle_error(const char *message);
int		valid_num(const char *str);
int		is_duplicate(int num, const int *nums, int count);
void	push_stack(t_stack *stack, int index, int data);
int		pop_stack(t_stack *stack);
void	push(t_stack *stack1, t_stack *stack2, char identifier, int should_print);
void	swap(t_stack *stack, char identifier, int should_print);
void	rotate(t_stack *stack, char identifier, int should_print);
void	reverse_rotate(t_stack *stack, char identifier, int should_print);
void 	sort(t_stack *stack_a, t_stack *stack_b, int *nums, int count);
int		is_sorted(t_stack *stack);

#endif