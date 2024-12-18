/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:42:40 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/10 17:09:47 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup_mod(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	dup = (char *)malloc(sizeof(*dup) * len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[len] = '\0';
	return (dup);
}

int	ft_strlen_mod(char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

char	*ft_strjoin_mod(char *s1, char *s2)
{
	int		len1;
	int		len2;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len1 = ft_strlen_mod(s1);
	len2 = ft_strlen_mod(s2);
	str = malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < len1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr_mod(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char )c)
		return ((char *)(s + i));
	return (0);
}

void	*ft_calloc_mod(size_t count, size_t size)
{
	size_t	total_size;
	size_t	i;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (!ptr)
		return (0);
	i = 0;
	while (i < total_size)
	{
		((unsigned char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
