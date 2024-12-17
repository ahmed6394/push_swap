/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:21:51 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/17 17:02:53 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include "../libft/libft.h"

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
 
#endif