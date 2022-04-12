/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:06:02 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/12 22:34:24 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	int		rd;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (!ft_strchr(left_str, '\n') && rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		left_str = ft_strjoin(left_str, buf);
	}
	free(buf);
	line = get_line(left_str);
	return (line);
}
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	char	*line;
	int	fd2;
	int	fd3;
	int	i;

	fd = open("test/test.txt", O_RDONLY);
	fd2 = open("test/test2.txt", O_RDONLY);
	fd3 = open("test/test3.txt", O_RDONLY);
	i = 1;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("line [%02d] : %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d] : %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d] : %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	close(fd2);
	close(fd3);
	return (0);
}
