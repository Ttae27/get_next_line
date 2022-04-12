/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:06:51 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/12 17:10:21 by phongpai         ###   ########.fr       */
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
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)));
	if (!out)
		return (NULL);
	while (s1[j])
	{
		out[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		out[i] = s2[j];
		i++;
		j++;
	}
	out[i] = '\0';
	return (out);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
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
	while (str[i] && str[i] != '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		tmp[i++] = '\n';
	tmp[i] = '\0';
	free(str);
	return (tmp);
}
