/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcolor2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:52:42 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/02 16:19:28 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_chao(t_data img, int x, int y)
{
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
}

void	print_parede(t_data img, int x, int y)
{
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.parede, y, x);
}

void	print_player(t_data img, int x, int y)
{
	x = x * 64;
	y = y * 64;
	if (img.side == 0)
	{
		mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
		mlx_put_image_to_window(img.mlx, img.win, img.player, y, x);
	}
	else
	{
		mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
		mlx_put_image_to_window(img.mlx, img.win, img.player2, y, x);
	}
}

void	print_porta(t_data img, int x, int y)
{
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
	mlx_put_image_to_window(img.mlx, img.win, img.porta, y, x);
}

void	print_portal(t_data img, int x, int y, char **map)
{
	char	a[2];

	a[0] = map[x][y];
	a[1] = '\0';
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
	mlx_put_image_to_window(img.mlx, img.win, img.portal, y, x);
	mlx_string_put(img.mlx, img.win, y, x, 0x66FFFFFF, a);
}
