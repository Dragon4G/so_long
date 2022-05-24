/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:41:02 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/23 18:33:09 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	size_of_matrix(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

void	reset_img(char ***map)
{
	char	*a;

	mlx_clear_window((*img()).mlx, (*img()).win);
	my_print_color((*img()), *map);
	a = ft_itoa((*img()).moves);
	mlx_string_put((*img()).mlx, (*img()).win, 10, 10, 16777215, a);
	free(a);
	if ((*img()).end == 1)
	{
		mlx_string_put((*img()).mlx, (*img()).win, (strlen(**map) * 32 - 64),
			((*img()).size * 32), 0x0000FF00, "You Win");
	}
	else if ((*img()).end == 2)
		mlx_string_put((*img()).mlx, (*img()).win, (strlen(**map) * 32 - 64),
			((*img()).size * 32), 0x00FF0000, "You Lose");
}

int	key_press(int keycode, char ***map)
{
	if ((*img()).end != 0)
		ft_free(*map);
	else if (keycode == 53)
		ft_free(*map);
	else if (keycode == 0)
	{
		move_left(map);
		(*img()).side = 0;
	}
	else if (keycode == 1)
		move_down(map);
	else if (keycode == 2)
	{
		move_right(map);
		(*img()).side = 1;
	}
	else if (keycode == 13)
		move_up(map);
	else
		return (0);
	reset_img(map);
	return (0);
}

void	start_window_2(void)
{
	(*img()).blue3 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue3.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue4 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue4.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue5 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue5.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue6 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue6.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue7 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue7.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue8 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue8.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).pico = mlx_xpm_file_to_image((*img()).mlx,
			"./src/pico.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue1 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue1.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue2 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/blue2.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).player2 = mlx_xpm_file_to_image((*img()).mlx,
			"./src/samurai2.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).image_open = 1;
}

void	start_window(char ***map)
{
	points(map);
	(*img()).moves = 0;
	(*img()).size = size_of_matrix(*map);
	(*img()).mlx = mlx_init();
	(*img()).win = mlx_new_window((*img()).mlx, (strlen(**map) * 64 - 64),
			((*img()).size * 64), "./so_long");
	(*img()).chao = mlx_xpm_file_to_image((*img()).mlx,
			"./src/chao.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).parede = mlx_xpm_file_to_image((*img()).mlx,
			"./src/parede.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).player = mlx_xpm_file_to_image((*img()).mlx,
			"./src/samurai1.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).porta = mlx_xpm_file_to_image((*img()).mlx,
			"./src/porta.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).portal = mlx_xpm_file_to_image((*img()).mlx,
			"./src/portal.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).collect = mlx_xpm_file_to_image((*img()).mlx,
			"./src/collect.xpm", &(*img()).img_width, &(*img()).img_height);
	start_window_2();
	my_print_color((*img()), *map);
	mlx_hook((*img()).win, 17, 0, ft_free, *map);
	mlx_key_hook((*img()).win, key_press, map);
	mlx_loop_hook((*img()).mlx, reset_num2, map);
	mlx_loop((*img()).mlx);
}
