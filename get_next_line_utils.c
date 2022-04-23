/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:06:51 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/23 15:41:41 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*out;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	while (s1[j])
		out[i++] = s1[j++];
	j = 0;
	while (s2[j])
		out[i++] = s2[j++];
	out[i] = '\0';
	free(s1);
	return (out);
}

int	check_space(char *left)
{
	int		i;

	i = 0;
	while (left[i] != '\0')
	{
		if (left[i] == 10)
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*next_left_str(char *left)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	if (left == NULL)
		return (NULL);
	if (left[0] == '\0')
	{
		free(left);
		return ("\0");
	}
	while (left[i] && left[i] != '\n')
		i++;
	next = (char *)malloc(sizeof(char) * (ft_strlen(&left[i]) + 1));
	if (!next)
		return (NULL);
	if (!ft_strlen(&left[i]))
	{
		free(left);
		next[0] = '\0';
		return (next);
	}
	j = 0;
	i++;
	while (left[i])
		next[j++] = left[i++];
	if (left[i] == '\n')
		next[j++] = '\n';
	next[j] = '\0';
	free(left);
	return (next);
}