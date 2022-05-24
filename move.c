/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:23:40 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/02 17:41:51 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	points(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
		{
			if ((*map)[i][j] == 'C')
				(*img()).points++;
		}
	}
	(*img()).end = 0;
}

void	move_up(char ***map)
{
	if ((*map)[(*img()).x - 1][(*img()).y] != '1')
		(*img()).moves++;
	while ((*map)[(*img()).x - 1][(*img()).y] == '0' ||
		((*map)[(*img()).x - 1][(*img()).y] == '2' &&
		(*map)[(*img()).x - 1][(*img()).y] == '9'))
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x - 1][(*img()).y] = 'P';
		(*img()).x--;
	}
	if (((*map)[(*img()).x - 1][(*img()).y] == 'E'
		&& (*img()).points == 0) || (*map)[(*img()).x - 1][(*img()).y] == 'X')
		you_end(map);
	if ((*map)[(*img()).x - 1][(*img()).y] >= 'a'
	&& (*map)[(*img()).x - 1][(*img()).y] <= 'z')
		find_portals_up(map, -1);
	if ((*map)[(*img()).x - 1][(*img()).y] == 'C')
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x - 1][(*img()).y] = 'P';
		(*img()).points--;
		(*img()).x--;
	}
}

void	move_left(char ***map)
{
	if ((*map)[(*img()).x][(*img()).y - 1] != '1')
		(*img()).moves++;
	while ((*map)[(*img()).x][(*img()).y - 1] == '0'
	|| ((*map)[(*img()).x][(*img()).y - 1] == '2' &&
	(*map)[(*img()).x][(*img()).y - 1] == '9'))
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x][(*img()).y - 1] = 'P';
		(*img()).y--;
	}
	if (((*map)[(*img()).x][(*img()).y - 1] == 'E'
		&& (*img()).points == 0) || (*map)[(*img()).x][(*img()).y - 1] == 'X')
		you_end(map);
	if ((*map)[(*img()).x][(*img()).y - 1] >= 'a'
	&& (*map)[(*img()).x][(*img()).y - 1] <= 'z')
		find_portals_left(map, -1);
	if ((*map)[(*img()).x][(*img()).y - 1] == 'C')
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x][(*img()).y - 1] = 'P';
		(*img()).points--;
		(*img()).y--;
	}
}

void	move_right(char ***map)
{
	if ((*map)[(*img()).x][(*img()).y + 1] != '1')
		(*img()).moves++;
	while ((*map)[(*img()).x][(*img()).y + 1] == '0' ||
	((*map)[(*img()).x][(*img()).y + 1] == '2' &&
	(*map)[(*img()).x][(*img()).y + 1] == '9'))
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x][(*img()).y + 1] = 'P';
		(*img()).y++;
	}
	if (((*map)[(*img()).x][(*img()).y + 1] == 'E' &&
	(*img()).points == 0) || (*map)[(*img()).x][(*img()).y + 1] == 'X')
		you_end(map);
	if ((*map)[(*img()).x][(*img()).y + 1] >= 'a'
	&& (*map)[(*img()).x][(*img()).y + 1] <= 'z')
		find_portals_right(map, -1);
	if ((*map)[(*img()).x][(*img()).y + 1] == 'C')
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x][(*img()).y + 1] = 'P';
		(*img()).points--;
		(*img()).y++;
	}
}

void	move_down(char ***map)
{
	if ((*map)[(*img()).x + 1][(*img()).y] != '1')
		(*img()).moves++;
	while ((*map)[(*img()).x + 1][(*img()).y] == '0' ||
	((*map)[(*img()).x + 1][(*img()).y] == '2' &&
	(*map)[(*img()).x + 1][(*img()).y] == '9'))
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x + 1][(*img()).y] = 'P';
		(*img()).x++;
	}
	if (((*map)[(*img()).x + 1][(*img()).y] == 'E' &&
	(*img()).points == 0) || (*map)[(*img()).x + 1][(*img()).y] == 'X')
		you_end(map);
	if ((*map)[(*img()).x + 1][(*img()).y] >= 'a' &&
	(*map)[(*img()).x + 1][(*img()).y] <= 'z')
		find_portals_down(map, -1);
	if ((*map)[(*img()).x + 1][(*img()).y] == 'C')
	{
		(*map)[(*img()).x][(*img()).y] = '2';
		(*map)[(*img()).x + 1][(*img()).y] = 'P';
		(*img()).points--;
		(*img()).x++;
	}
}
