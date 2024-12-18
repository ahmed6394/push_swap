/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:33:45 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/22 17:30:16 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_put_str("-2147483648");
	else if (n < 0)
	{
		if (write(1, "-", 1) < 0)
			return (-1);
		count++;
		count += ft_put_nbr(-n);
	}
	else
	{
		if (n > 9)
			count += ft_put_nbr(n / 10);
		if (count != -1)
			count += ft_put_char("0123456789"[n % 10]);
	}
	return (count);
}

int	ft_put_unint(unsigned int n)
{
	int	count;

	count = 0;
	if (n > 9)
		count += ft_put_unint(n / 10);
	if (count != -1)
		count += ft_put_char("0123456789"[n % 10]);
	return (count);
}

int	ft_base_16(unsigned long n, char *hex)
{
	int	count;

	count = 0;
	if (n > 15)
		count += ft_base_16(n / 16, hex);
	if (count != -1)
		count += ft_put_char(hex[n % 16]);
	return (count);
}

int	ft_put_hex(unsigned int n, int chr)
{
	char	*hex;

	if (chr == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	return (ft_base_16((unsigned long)n, hex));
}
