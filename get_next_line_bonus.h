/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:19:38 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/29 22:17:28 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strjoin(char *left, char *buf);
char	*read_bufsize(int fd, char *left);
int		check_nl(char *str);
char	*get_line(char *left);
char	*next_left(char *left, int i, int j);
char	*get_next_line(int fd);

#endif