/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:25:25 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/10 17:10:01 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 10240
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_mod(char *str);
char	*ft_strchr_mod(const char *s, int c);
char	*ft_strdup_mod(const char *s);
char	*ft_strjoin_mod(char *s1, char *s2);
char	*get_next_line(int fd);
char	*extract_line(char *leftover);
char	*update_leftover(char *leftover);
void	*ft_calloc_mod(size_t count, size_t size);

#endif