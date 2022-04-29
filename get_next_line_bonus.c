/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:19:36 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/29 22:18:49 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line_bonus.h"

int	check_nl(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*read_bufsize(int fd, char *left)
{
	int		rd;
	char	*buf;

	buf = malloc(sizeof(char) * 2);
	if (!buf)
		return (NULL);
	rd = 1;
	while (rd != 0 && check_nl(left) == 0)
	{
		rd = read(fd, buf, 1);
		if (rd < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[rd] = '\0';
		left = ft_strjoin(left, buf);
	}
	free(buf);
	return (left);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*left;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left = read_bufsize(fd, left);
	if (!left)
		return (NULL);
	line = get_line(left);
	left = next_left(left, 0, 0);
	return (line);
}