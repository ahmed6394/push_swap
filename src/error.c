/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:02:26 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/18 17:33:03 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	handle_error(const char *message)
{
	// ft_putstr_fd("FdF: ", 2);
	ft_putendl_fd((char *)message, 2);
	exit(1);
}

int valid_num(const char *str)
{
	int  i;

	i = 0;
	if(*str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if(str[i] == '\0')
		return (0);
	while(str[i])
	{
		if (!ft_isdigit((unsigned char)str[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_duplicate(int num, const int *nums, int count)
{
	int i;

	i = 0;
	while(i < count)
	{
		if (nums[i] == num)
			return (1);
		i++;
	}
	return 0;
}