/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 13:56:05 by gahmed            #+#    #+#             */
/*   Updated: 2024/10/25 12:14:04 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

int	ft_printf(const char *formate, ...);
int	ft_check_type(char chr, va_list args);
int	ft_put_char(char c);
int	ft_put_str(char *str);
int	ft_put_ptr(size_t n);
int	ft_put_nbr(int n);
int	ft_put_unint(unsigned int n);
int	ft_base_16(unsigned long n, char *hex);
int	ft_put_hex(unsigned int n, int chr);

#endif