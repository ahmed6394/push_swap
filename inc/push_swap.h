/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:51 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/18 17:21:13 by gahmed           ###   ########.fr       */
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

// void 	parse_data(int ac, char *av[], t_stack *stack_a, int **nums, int count);
// void 	initialize_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int count);
// void 	sort(t_stack *stack_a, t_stack *stack_b, int *nums, int count);
// void 	free_stack(t_stack *stack);
void parse_data(int ac, char *av[], int **nums, int *count);
void 	initialize_stack(t_stack *stack_a, t_stack *stack_b, int *nums, int count);
void	handle_error(const char *message);
int		index_of(int n, int *arr);
void handle_error(const char *message);
void parse_and_initialize(int argc, char *argv[], t_stack *stack_a, t_stack *stack_b);
int valid_num(const char *str);
int is_duplicate(int num, const int *nums, int count);
 
#endif