/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:12:25 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/22 17:33:43 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(char c)
{
	if (write (1, &c, 1) < 0)
		return (-1);
	return (1);
}

int	ft_put_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	else
	{
		while (str[i])
			i++;
	}
	if (write (1, str, i) < 0)
		return (-1);
	return (i);
}

int	ft_put_ptr(size_t n)
{
	int	count;

	count = 0;
	if (n < 0)
		return (-1);
	if (n >= 16)
		count += ft_put_ptr(n / 16);
	count += ft_put_char("0123456789abcdef"[n % 16]);
	return (count);
}
