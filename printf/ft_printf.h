/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:36:48 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/18 14:15:33 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);

int		ft_printf(const char *pillar, ...);

int		process(const char *pillar, va_list stone);

int		print_putchar_fd(char c, int fd);

int		print_putstr_fd(char *s, int fd);

int		print_putnbr_fd(int n, int fd);

int		ft_putnbr_base(unsigned int nbr, char *base, unsigned int nbase);

#endif
