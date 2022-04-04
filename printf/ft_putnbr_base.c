/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:42:58 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/18 14:40:09 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base, unsigned int nbase)
{
	int	counter;

	counter = 0;
	if (nbr < 0)
	{
		nbr = nbr * -1;
		counter += print_putchar_fd('-', 1);
	}
	if (nbr >= nbase)
	{
		counter += ft_putnbr_base(nbr / nbase, base, nbase);
	}
	counter += print_putchar_fd(base[nbr % nbase], 1);
	return (counter);
}
