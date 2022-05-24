/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   portals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:00:03 by bantunes          #+#    #+#             */
/*   Updated: 2022/04/27 16:08:00 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ifs(char **map, int m, int n)
{
	if (map[(*img()).i][(*img()).j] == (*img()).teleport[n] && m == 0)
	{
		(*img()).teleport1x[n] = (*img()).i;
		(*img()).teleport1y[n] = (*img()).j;
		(*img()).j++;
		m++;
	}
	if (map[(*img()).i][(*img()).j] == (*img()).teleport[n] && m == 1)
	{
		(*img()).teleport2x[n] = (*img()).i;
		(*img()).teleport2y[n] = (*img()).j;
		(*img()).j++;
		m++;
	}
	return (m);
}

void	check_portals(char **map)
{
	int	n;
	int	m;

	n = -1;
	while (++n < 26)
	{
		(*img()).i = -1;
		m = 0;
		while (map[++(*img()).i] != NULL)
		{
			(*img()).j = -1;
			while (map[(*img()).i][++(*img()).j] != '\0')
				m = check_ifs(map, m, n);
		}
	}
}

void	find_up(char ***map, int n)
{
	if ((*map)[(*img()).teleport2x[n] - 1][(*img()).teleport2y[n]] != '1')
	{
		if ((*map)[(*img()).teleport2x[n] - 1][(*img()).teleport2y[n]] == 'C')
			(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport2y[n];
		(*img()).x = (*img()).teleport2x[n] - 1;
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_up(map);
	}
}

void	find_up2(char ***map, int n)
{
	if ((*map)[(*img()).teleport1x[n] - 1][(*img()).teleport1y[n]] != '1')
	{
		if ((*map)[(*img()).teleport1x[n] - 1][(*img()).teleport1y[n]] == 'C')
			(*img()).points--;
		(*map)[(*img()).x][(*img()).y] = '2';
		(*img()).y = (*img()).teleport1y[n];
		(*img()).x = (*img()).teleport1x[n] - 1;
		(*map)[(*img()).x][(*img()).y] = 'P';
		(*img()).moves--;
		move_up(map);
	}
}

void	find_portals_up(char ***map, int n)
{
	while (++n < 26)
	{
		if ((*map)[(*img()).x - 1][(*img()).y] == (*img()).teleport[n])
		{
			if ((*img()).y == (*img()).teleport1y[n])
				if ((*img()).x - 1 == (*img()).teleport1x[n])
					find_up(map, n);
			if ((*img()).y == (*img()).teleport2y[n])
				if ((*img()).x - 1 == (*img()).teleport2x[n])
					find_up2(map, n);
		}
	}
}
