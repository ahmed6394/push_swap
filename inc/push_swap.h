/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:51 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/23 16:19:26 by gahmed           ###   ########.fr       */
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
void	parse_data(int ac, char *av[], t_stack **stack_a, int *count);



//operations
void	push(t_stack **src, t_stack **dest, char stack_name);
void	reverse_rotate(t_stack **stack, char stack_name);
void	reverse_rotate_both(t_stack **a, t_stack **b, int print);
void	rotate(t_stack **stack, char stack_name);
void	rotate_both(t_stack **a, t_stack **b, int print);
void	swap(t_stack *stack, char stack_name);
void	swap_both(t_stack *a, t_stack *b, int print);
t_stack	*last_node(t_stack *stack);

//sort
void	sort(t_stack **stack_a, t_stack **stack_b);
int		is_sorted(t_stack *stack);
void 	simple_sort(t_stack **stack);
void	long_sort(t_stack **stack_a, t_stack **stack_b);

//init
void	init_stack_basics(t_stack *stack, char stack_name);
void	init_stack(t_stack *from, t_stack *to, char name_from, char name_to);

//utiles
int		stack_size(t_stack *stack);
int		get_stack_size(t_stack *stack);
t_stack	*get_max(t_stack *stack);
t_stack	*get_min(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);
void	move_to_top(t_stack *node1, t_stack *node2, t_stack **stack1, t_stack **stack2);
void	push_to_target_stack(t_stack **current, t_stack **target);
void	check_min_on_top(t_stack **a);

//error
void	free_stack(t_stack *stack);
void	handle_error(const char *message);
int		valid_num(const char *str);
int		is_duplicate(int num, t_stack *stack_a);

#endif