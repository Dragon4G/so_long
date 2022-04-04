/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:28:18 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/18 13:57:07 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putnbr_fd(int n, int fd)
{
	if (n == 0)
		return (print_putchar_fd('0', 1));
	if (n == -2147483648)
		return (print_putstr_fd("-2147483648", fd));
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			return (print_putnbr_fd(n * -1, fd) + 1);
		}
		else if (n / 10 > 0)
			return (print_putnbr_fd(n / 10, fd)
				+ print_putchar_fd((n % 10) + '0', fd));
		else
			return (print_putchar_fd((n % 10) + '0', fd));
	}
	return (0);
}
