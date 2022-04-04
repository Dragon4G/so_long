/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:16:43 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/18 14:21:52 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char *s1);

char	*ft_strjoin(char const *s1, char const *s2);

void	*ft_memcpy(void *dst, const void *src, size_t n);

size_t	ft_strlen(const char *s);

#endif