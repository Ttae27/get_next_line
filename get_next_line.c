/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:06:02 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/12 17:13:13 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left_str;
	int		i;
	int		rd;
	char		*buf;

	i = 0;
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

	fd = open ("lol", O_RDONLY);
	line = get_next_line(fd);
	printf("%s",line);
	free(line);
}
