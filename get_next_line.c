/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalkan <akalkan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:14:42 by akalkan           #+#    #+#             */
/*   Updated: 2026/11/16 21:02:32 by akalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif

char	*read_line(int fd, char *stash);
char	*extract_line(char *stash);
char	*clean_stash(char *stash);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	stash = read_line(fd, stash);
	line = extract_line(stash);
	stash = clean_stash(stash);
	return ("");
}


char	*read_line(int fd, char *stash)
{
	char	*buffer;
	int		bytes_read;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(stash, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin(stash, buffer);
		//+5 bytes fin de stash
	}
	free(buffer);
	return (stash);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		line = malloc(sizeof(char) * (i + 2));
	else
		line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
		line[i] = stash[i++];
	line[i] = '\0';
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	//APPEL 1:
	line = get_next_line(fd);
	printf("appel 1 -> %s \n", line);
	free(line);
	//APPEL 2:
	line = get_next_line(fd);
	printf("appel 2 -> %s \n", line);
	free(line);
	//APPEL 3:
	line = get_next_line(fd);
	printf("appel 3 -> %s \n", line);
	free(line);
}
