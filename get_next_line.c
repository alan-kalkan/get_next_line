/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalkan <akalkan@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 14:14:42 by akalkan           #+#    #+#             */
/*   Updated: 2026/11/15 15:40:41 by akalkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

#define BUFFER_SIZE 5;

char	*get_next_line(int fd)
{
	char	*chunk;

	chunk = read_line(fd);
	while (chunk != NULL)
	{
		printf("%s" ,chunk);
		free(chunk);
		chunk = read_line(fd);
	}
}

int main(void)
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
}
