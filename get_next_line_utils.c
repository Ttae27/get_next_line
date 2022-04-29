/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:18:04 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/29 20:08:10 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *left, char *buf)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	if (left == NULL)
	{
		left = malloc(sizeof(char));
		left[0] = '\0';
	}
	out = malloc(sizeof(char) * (ft_strlen(left) + ft_strlen(buf) + 1));
	if (!out)
		return (NULL);
	j = 0;
	while (left[i] != '\0')
		out[j++] = left[i++];
	i = 0;
	while (buf[i] != '\0')
		out[j++] = buf[i++];
	out[j] = '\0';
	free(left);
	return (out);
}

char	*get_line(char *left)
{
	int		i;
	char	*line;

	if (left[0] == '\0' || left == NULL)
		return (NULL);
	i = 0;
	while (left[i] != '\n' && left[i] != '\0')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (left[i] != '\n' && left[i] != '\0')
	{
		line[i] = left[i];
		i++;
	}
	if (left[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*next_left(char *left, int i, int j)
{
	char	*next;

	if (left[0] == '\0')
	{
		free(left);
		return (NULL);
	}
	while (left[i] != '\n' && left[i] != '\0')
		i++;
	next = malloc(sizeof(char) * ft_strlen(&left[i]) + 1);
	if (!next)
		return (NULL);
	if (left[i] == '\0')
	{
		free(left);
		next[0] = '\0';
		return (next);
	}
	i++;
	while (left[i] != '\0')
		next[j++] = left[i++];
	next[j] = '\0';
	free(left);
	return (next);
}