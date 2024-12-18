/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gahmed <gahmed@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:02:00 by gahmed            #+#    #+#             */
/*   Updated: 2024/12/10 17:09:54 by gahmed           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *leftover)
{
	int		len;
	char	*line;
	int		i;

	len = 0;
	i = 0;
	while (leftover[len] && leftover[len] != '\n')
		len++;
	line = ft_calloc_mod(len + 2, sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = leftover[i];
		i++;
	}
	if (leftover[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*update_leftover(char *leftover)
{
	int		len;
	char	*new_leftover;

	len = 0;
	while (leftover[len] && leftover[len] != '\n')
		len++;
	if (!leftover[len] || !leftover[len + 1])
	{
		free(leftover);
		return (NULL);
	}
	new_leftover = ft_strdup_mod(leftover + len + 1);
	free(leftover);
	return (new_leftover);
}

static char	*join_leftover(int fd, char *leftover)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*temp;
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr_mod(leftover, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(leftover);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = leftover;
		leftover = ft_strjoin_mod(temp, buffer);
		free(temp);
		if (!leftover)
			return (NULL);
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*leftover[MAX_FD];
	char		*line;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (!leftover[fd])
		leftover[fd] = ft_strdup_mod("");
	if (!leftover[fd])
		return (NULL);
	leftover[fd] = join_leftover(fd, leftover[fd]);
	if (!leftover[fd] || leftover[fd][0] == '\0')
	{
		free(leftover[fd]);
		leftover[fd] = NULL;
		return (NULL);
	}
	line = extract_line(leftover[fd]);
	leftover[fd] = update_leftover(leftover[fd]);
	return (line);
}

// char	*get_next_line(int fd)
// {
// 	static char	*leftover;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	if (!leftover)
// 		leftover = ft_strdup("");
// 	if (!leftover)
// 		return (NULL);
// 	printf("Leftover before join: %s\n", leftover);
// 	leftover = join_leftover(fd, leftover);
// 	if (!leftover || leftover[0] == '\0')
// 	{
// 		free(leftover);
// 		leftover = NULL;
// 		return (NULL);
// 	}
// 	printf("Leftover after join: %s\n", leftover);
// 	line = extract_line(leftover);
// 	printf("Leftover after extract: %s\n", leftover);
// 	printf("Line after extract: %s\n", line);
// 	leftover = update_leftover(leftover);
// 	printf("Leftover after update_leftover: %s\n", leftover);
// 	return (line);
// }
// int main()
// {
//     int fd = open("test.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return 1;
//     }
//     char *line;
//     while ((line = get_next_line(fd)) != NULL)
//     {
//         printf("Line: %s", line);
//         free(line);
//     }
//     close(fd);
//     return 0;
// }