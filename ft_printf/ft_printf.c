/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 14:21:50 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/25 12:13:12 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_type(char chr, va_list args)
{
	int	count;

	count = 0;
	if (chr == 'c')
		count += ft_put_char(va_arg(args, int));
	if (chr == 's')
		count += ft_put_str(va_arg(args, char *));
	if (chr == 'p')
	{
		count = ft_put_str("0x");
		if (count != -1)
			count += ft_put_ptr(va_arg(args, size_t));
	}
	if (chr == 'd' || chr == 'i')
	{
		if (count != -1)
			count += ft_put_nbr(va_arg(args, int));
	}
	if (chr == 'u')
		count += ft_put_unint(va_arg(args, unsigned int));
	if (chr == 'x' || chr == 'X')
		count += ft_put_hex(va_arg(args, unsigned int), chr);
	if (chr == '%')
		count += ft_put_char('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, input);
	while (input[i])
	{
		if (input[i] == '%' && count != -1)
		{
			i++;
			count += ft_check_type(input[i], args);
		}
		else if (count != -1)
			count += ft_put_char (input[i]);
		i++;
	}
	va_end(args);
	return (count);
}
