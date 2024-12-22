/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:51 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 19:57:12 by gahmed           ###   ########.fr       */
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
typedef struct s_stack
{
	int				data;
	int				index;
	int				push_cost;
	int				above_median;
	char			name;
	struct s_stack	*target;
	struct s_stack	*next;
}	t_stack;

//parse
void parse_data(int ac, char *av[], t_stack **stack_a, int *count);

int		index_of(int n, int *arr);
void	handle_error(const char *message);
int		valid_num(const char *str);
int is_duplicate(int num, t_stack *stack_a);

//operations
void	push(t_stack **src, t_stack **dest, char stack_name);
void	reverse_rotate(t_stack **stack, char stack_name);
void	reverse_rotate_both(t_stack **a, t_stack **b, int print);
void	rotate(t_stack **stack, char stack_name);
void	rotate_both(t_stack **a, t_stack **b, int print);
void	swap(t_stack *stack, char stack_name);
void	swap_both(t_stack *a, t_stack *b, int print);
t_stack *last_node(t_stack *stack);
int stack_size(t_stack *stack);

//sort
void	sort(t_stack **stack_a, t_stack **stack_b);
int	is_sorted(t_stack *stack);
//utiles
void free_stack(t_stack *stack);

#endif