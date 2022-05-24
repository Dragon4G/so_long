/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printcolor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:52:36 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/03 15:41:50 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_soul(t_data img, int x, int y)
{
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
	mlx_put_image_to_window(img.mlx, img.win, img.collect, y, x);
}

void	print_pico(t_data img, int x, int y)
{
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
	mlx_put_image_to_window(img.mlx, img.win, img.pico, y, x);
}

void	print_speed(t_data img, int x, int y, int n)
{
	x = x * 64;
	y = y * 64;
	mlx_put_image_to_window(img.mlx, img.win, img.chao, y, x);
	if (n == 1)
		mlx_put_image_to_window(img.mlx, img.win, img.blue1, y, x);
	if (n == 2)
		mlx_put_image_to_window(img.mlx, img.win, img.blue2, y, x);
	if (n == 3)
		mlx_put_image_to_window(img.mlx, img.win, img.blue3, y, x);
	if (n == 4)
		mlx_put_image_to_window(img.mlx, img.win, img.blue4, y, x);
	if (n == 5)
		mlx_put_image_to_window(img.mlx, img.win, img.blue5, y, x);
	if (n == 6)
		mlx_put_image_to_window(img.mlx, img.win, img.blue6, y, x);
	if (n == 7)
		mlx_put_image_to_window(img.mlx, img.win, img.blue7, y, x);
	if (n == 8)
		mlx_put_image_to_window(img.mlx, img.win, img.blue8, y, x);
}

void	my_print_color2(t_data img, char **map, int x, int y)
{
	if (map[x][y] == 'X')
		print_pico(img, x, y);
	if (map[x][y] >= 'a' && map[x][y] <= 'z')
		print_portal(img, x, y, map);
	if (map[x][y] == '2')
		print_speed(img, x, y, 1);
	if (map[x][y] == '3')
		print_speed(img, x, y, 2);
	if (map[x][y] == '4')
		print_speed(img, x, y, 3);
	if (map[x][y] == '5')
		print_speed(img, x, y, 4);
	if (map[x][y] == '6')
		print_speed(img, x, y, 5);
	if (map[x][y] == '7')
		print_speed(img, x, y, 6);
	if (map[x][y] == '8')
		print_speed(img, x, y, 7);
	if (map[x][y] == '9')
		print_speed(img, x, y, 8);
}

int	my_print_color(t_data img, char **map)
{
	int		x;
	int		y;

	x = -1;
	while (map[++x] != NULL)
	{
		y = -1;
		while (map[x][++y] != '\0')
		{
			if (map[x][y] == '1')
				print_parede(img, x, y);
			else if (map[x][y] == '0')
				print_chao(img, x, y);
			else if (map[x][y] == 'P')
				print_player(img, x, y);
			else if (map[x][y] == 'E')
				print_porta(img, x, y);
			else if (map[x][y] == 'C')
				print_soul(img, x, y);
			else
				my_print_color2(img, map, x, y);
		}
	}
	return (0);
}
