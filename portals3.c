/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portals3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:23:02 by bantunes          #+#    #+#             */
/*   Updated: 2022/04/27 15:42:56 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_left(char ***map, int n)
{
	if ((*map)[(*img()).teleport2x[n]][(*img()).teleport2y[n] - 1] != '1')
	{
		if ((*map)[(*img()).teleport2x[n]][(*img()).teleport2y[n] - 1] == 'C')
			(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport2y[n] - 1;
		(*img()).x = (*img()).teleport2x[n];
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_left(map);
	}
}

void	find_left2(char ***map, int n)
{
	if ((*map)[(*img()).teleport1x[n]][(*img()).teleport1y[n] - 1] != '1')
	{
		if ((*map)[(*img()).teleport1x[n]][(*img()).teleport1y[n] - 1] == 'C')
			(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport1y[n] - 1;
		(*img()).x = (*img()).teleport1x[n];
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_left(map);
	}
}

void	find_portals_left(char ***map, int n)
{
	while (++n < 26)
	{
		if ((*map)[(*img()).x][(*img()).y - 1] == (*img()).teleport[n])
		{
			if ((*img()).y - 1 == (*img()).teleport1y[n])
				if ((*img()).x == (*img()).teleport1x[n])
					find_left(map, n);
			if ((*img()).y - 1 == (*img()).teleport2y[n])
				if ((*img()).x == (*img()).teleport2x[n])
					find_left2(map, n);
		}
	}
}

void	find_right(char ***map, int n)
{
	if ((*map)[(*img()).teleport2x[n]][(*img()).teleport2y[n] + 1] != '1')
	{
		if ((*map)[(*img()).teleport2x[n]][(*img()).teleport2y[n] + 1] == 'C')
			(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport2y[n] + 1;
		(*img()).x = (*img()).teleport2x[n];
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_right(map);
	}
}
