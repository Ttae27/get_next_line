/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:06:02 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/23 15:42:21 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	int		rd;
	char		*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd != 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		if (buf[0] == '\0')
			break;
	//	printf("rd = %d",rd);
		left_str = ft_strjoin(left_str, buf);
	//	printf(" : left = %s\n", left_str);
	//	printf("check_space = %d\n",check_space(left_str));
		if (check_space(left_str) == 1 || rd < BUFFER_SIZE)
			break;
	}
	free(buf);
	line = get_line(left_str);
	left_str = next_left_str(left_str);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>

int	main()
{
	int	fd;
	char	*line;
	int	i;

	fd = open("alternate_line_nl_no_nl", O_RDONLY);
	i = 1;
	while (i <= 10)
	{
		line = get_next_line(fd);
		printf("line [%02d] : %s", i, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}*/
