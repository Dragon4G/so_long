/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:51:13 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/18 14:14:56 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexalink(unsigned long stone, int i)
{
	char	hexa[100];
	int		temp;
	int		y;

	while (stone != 0)
	{
		temp = stone % 16;
		if (temp < 10)
			hexa[i++] = temp + 48;
		else
			hexa[i++] = temp + 87;
		stone = stone / 16;
	}
	y = i - 1;
	print_putstr_fd("0x", 1);
	i += 2;
	while (y >= 0)
		print_putchar_fd(hexa[y--], 1);
	if (i == 2)
	{
		print_putchar_fd('0', 1);
		return (3);
	}
	return (i);
}

int	ft_putu(unsigned int n, int fd)
{
	if (n == 0)
		return (print_putchar_fd('0', 1));
	if (n / 10 > 0)
		return (print_putnbr_fd(n / 10, fd)
			+ print_putchar_fd((n % 10) + '0', fd));
	else
		return (print_putchar_fd((n % 10) + '0', fd));
	return (0);
}

int	identify(const char pillar, va_list stone)
{
	int	i;

	i = 0;
	if (pillar == 'c')
		i += print_putchar_fd(va_arg(stone, int), 1);
	else if (pillar == 's')
		i += print_putstr_fd(va_arg(stone, char *), 1);
	else if (pillar == 'p')
		i += hexalink(va_arg(stone, unsigned long), i);
	else if (pillar == 'd')
		i += print_putnbr_fd(va_arg(stone, int), 1);
	else if (pillar == 'i')
		i += print_putnbr_fd(va_arg(stone, int), 1);
	else if (pillar == 'u')
		i += ft_putu(va_arg(stone, unsigned int), 1);
	else if (pillar == 'x')
		i += ft_putnbr_base(va_arg(stone, unsigned int),
				"0123456789abcdef", 16);
	else if (pillar == 'X')
		i += ft_putnbr_base(va_arg(stone, unsigned int),
				"0123456789ABCDEF", 16);
	else if (pillar == '%')
		i += print_putchar_fd('%', 1);
	return (i);
}

int	process(const char *pillar, va_list stone)
{
	int	i;
	int	a;

	i = 0;
	a = 0;
	while (pillar[i] != '\0')
	{
		if (pillar[i] != '%')
		{
			print_putchar_fd(pillar[i], 1);
			a++;
		}
		else if (pillar[i] == '%')
		{
			a += identify(pillar[i++ + 1], stone);
		}
		i++;
	}
	return (a);
}
