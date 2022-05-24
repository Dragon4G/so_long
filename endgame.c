/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   endgame.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:21:39 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/03 15:42:11 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_black(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0' && map[i][j] != '\n')
			map[i][j] = '9';
	}
}

void	victory(char ***map)
{
	all_black(*map);
	(*img()).end = 1;
	reset_img(map);
}

void	lose(char ***map)
{
	all_black(*map);
	(*img()).end = 2;
	reset_img(map);
}

void	you_end(char ***map)
{
	if ((*map)[(*img()).x - 1][(*img()).y] == 'x')
		victory(map);
	else if ((*map)[(*img()).x][(*img()).y - 1] == 'E')
		victory(map);
	else if ((*map)[(*img()).x][(*img()).y + 1] == 'E')
		victory(map);
	else if ((*map)[(*img()).x + 1][(*img()).y] == 'E')
		victory(map);
	else
		lose(map);
}
