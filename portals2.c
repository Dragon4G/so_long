/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portals2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:00:03 by bantunes          #+#    #+#             */
/*   Updated: 2022/04/27 16:12:13 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_down(char ***map, int n)
{
	if ((*map)[(*img()).teleport2x[n] + 1][(*img()).teleport2y[n]] != '1')
	{
		if ((*map)[(*img()).teleport2x[n] + 1][(*img()).teleport2y[n]] == 'C')
				(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport2y[n];
		(*img()).x = (*img()).teleport2x[n] + 1;
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_down(map);
	}
}

void	find_down2(char ***map, int n)
{
	if ((*map)[(*img()).teleport1x[n] + 1][(*img()).teleport1y[n]] != '1')
	{
		if ((*map)[(*img()).teleport1x[n] + 1][(*img()).teleport1y[n]] == 'C')
				(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport1y[n];
		(*img()).x = (*img()).teleport1x[n] + 1;
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_down(map);
	}
}

void	find_portals_down(char ***map, int n)
{
	while (++n < 26)
	{
		if ((*map)[(*img()).x + 1][(*img()).y] == (*img()).teleport[n])
		{
			if ((*img()).y == (*img()).teleport1y[n])
				if ((*img()).x + 1 == (*img()).teleport1x[n])
					find_down(map, n);
			if ((*img()).y == (*img()).teleport2y[n])
				if ((*img()).x + 1 == (*img()).teleport2x[n])
					find_down2(map, n);
		}
	}
}

void	find_right2(char ***map, int n)
{
	if ((*map)[(*img()).teleport1x[n]][(*img()).teleport1y[n] + 1] != '1')
	{
		if ((*map)[(*img()).teleport1x[n]][(*img()).teleport1y[n] + 1] == 'C')
				(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport1y[n] + 1;
		(*img()).x = (*img()).teleport1x[n];
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_right(map);
	}
}

void	find_portals_right(char ***map, int n)
{
	while (++n < 26)
	{
		if ((*map)[(*img()).x][(*img()).y + 1] == (*img()).teleport[n])
		{
			if ((*img()).y + 1 == (*img()).teleport1y[n])
				if ((*img()).x == (*img()).teleport1x[n])
					find_right(map, n);
			if ((*img()).y + 1 == (*img()).teleport2y[n])
				if ((*img()).x == (*img()).teleport2x[n])
					find_right2(map, n);
		}
	}
}
