/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:57:39 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/19 15:40:52 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	num;
	int			sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if ((sign * num) >= -2147483648 && (sign * num) <= 2147483647)
		return (sign * num);
	write(2, "Error\n", 6);
	exit(1);
}

// #include <stdlib.h>
// #include <stdio.h>
// int main(void)
// {
//    int val;
//    int val2;
//    char *str; 
//    str = "--+1509.10E";
//    val = atoi(str); 
//    val2 = ft_atoi(str); 
//    printf("integral number an lib = %d\n", val);
//    printf("integral number as fn = %d\n", val2);
// }