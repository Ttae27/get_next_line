/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phongpai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 22:18:02 by phongpai          #+#    #+#             */
/*   Updated: 2022/04/27 21:31:20 by phongpai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define BUFFER_SIZE 1

int		ft_strlen(char *str);
char	*ft_strjoin(char *left, char *buf);
char	*read_bufsize(int fd, char *left);
int		check_nl(char *str);
char	*get_line(char *left);
char	*next_left(char *left, int i, int j);
char	*get_next_line(int fd);

#endif