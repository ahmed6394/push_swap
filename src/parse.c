/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 15:12:59 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/22 12:45:29 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	check_digits(char *str)
{
	if (!*str)
	{
		return (0);
	}
	if (ft_strchr("+-", *str))
	{
		str++;
		if (!*str)
		{
			return (0);
		}
	}
	while (*str)
	{
		if (!ft_isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

static int	check_duplicate(int num, t_stack *a)
{
	while (a != NULL)
	{
		if (a->data == num)
		{
			return (0);
		}
		a = a->next;
	}
	return (1);
}

int	*arg_parse(char **data, t_stack **a)
{
	long	current_num;
	t_stack	*created_list;

	while (*data)
	{
		if (ft_strlen(*data) > 11)
			return (0);
		if (!is_number(*data))
			return (0);
		current_num = ft_atol(*data);
		if (current_num < INT_MIN || current_num > INT_MAX)
			return (0);
		if (check_duplicate(current_num, *a) == 0)
			return (0);
		created_list = ft_lstnew_ps(current_num);
		if (!created_list)
			return (0);
		if (*a == NULL)
			*a = created_list;
		else
			ft_lstadd_back_ps(a, created_list);
		data++;
	}
	return (1);
}
int	parse_data(int argc, char **argv, t_stack **a)
{
	int		parsing_result;
	char	**split;

	if (argc == 2 && ft_strlen(argv[1]) > 0)
	{
		split = ft_split(argv[1], ' ');
		if (split == NULL)
		{
			return (1);
		}
		parsing_result = arg_parse(split, a);
		free_split(split);
		return (parsing_result);
	}
	if (argc > 2)
	{
		parsing_result = arg_parse(argv + 1, a);
		return (parsing_result);
	}
	return (0);
}