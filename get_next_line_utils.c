/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalkan <akalkan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:14:45 by akalkan           #+#    #+#             */
/*   Updated: 2026/11/15 15:39:33 by akalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*sub_str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (start >= i)
		len = 0;
	else if (len > i - start)
		len = i - start;
	sub_str = (char *)malloc((len + 1) * sizeof(char));
	if (!sub_str)
		return (NULL);
	j = 0;
	while (j < len)
	{
		sub_str[j] = s[start + j];
		j++;
	}
	sub_str[j] = '\0';
	return (sub_str);
}

char	*read_line(int fd)
{
	int		line;
	char	*buffer;
	int		buffer_size;

	buffer_size = 5;
	buffer = malloc(buffer_size + 1);
	if (!buffer)
		return (NULL);
	line = read(fd, buffer, buffer_size);
	if (line <= 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[line] == '\0';
	return (buffer);
}
