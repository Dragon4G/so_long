/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:09:43 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/18 14:12:36 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (print_putstr_fd("(null)", 1));
	while (s[i])
	{
		print_putchar_fd(s[i], fd);
		i++;
	}
	return (i);
}
