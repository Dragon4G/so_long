/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:44:56 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/16 15:45:50 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*img(void)
{
	static t_data	img;

	return (&img);
}

void	free_all(void)
{
	mlx_destroy_image((*img()).mlx, (*img()).chao);
	mlx_destroy_image((*img()).mlx, (*img()).parede);
	mlx_destroy_image((*img()).mlx, (*img()).player);
	mlx_destroy_image((*img()).mlx, (*img()).player2);
	mlx_destroy_image((*img()).mlx, (*img()).porta);
	mlx_destroy_image((*img()).mlx, (*img()).pico);
	mlx_destroy_image((*img()).mlx, (*img()).blue1);
	mlx_destroy_image((*img()).mlx, (*img()).blue2);
	mlx_destroy_image((*img()).mlx, (*img()).blue3);
	mlx_destroy_image((*img()).mlx, (*img()).blue4);
	mlx_destroy_image((*img()).mlx, (*img()).blue5);
	mlx_destroy_image((*img()).mlx, (*img()).blue6);
	mlx_destroy_image((*img()).mlx, (*img()).blue7);
	mlx_destroy_image((*img()).mlx, (*img()).blue8);
	mlx_destroy_image((*img()).mlx, (*img()).collect);
	mlx_destroy_image((*img()).mlx, (*img()).portal);
	mlx_destroy_window((*img()).mlx, (*img()).win);
}

int	ft_free(char **map)
{
	int	i;

	if ((*img()).image_open == 1)
		free_all();
	i = -1;
	while (!++map[i])
		free(map[i]);
	free(map);
	exit(1);
}

int	portal_fill(char **map, int n)
{
	char	a;

	a = 'a';
	while (a <= 'z')
	{
		(*img()).teleport[n] = a;
		n++;
		a++;
	}
	(*img()).i = -1;
	while (map[++(*img()).i] != NULL)
	{
		(*img()).j = -1;
		while (map[(*img()).i][++(*img()).j] != '\0')
		{
			if (map[(*img()).i][(*img()).j] == 'P')
			{
				(*img()).x = (*img()).i;
				(*img()).y = (*img()).j;
				return (0);
			}
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	**map;
	int		n;

	n = 0;
	map = NULL;
	if (ac != 2)
		return (ft_printf("Error\nYou need to put a file\n"));
	if (ft_strncmp(ft_strrchr(av[1], '.'), ".ber", 4) != 0)
	{
		ft_printf("Error\nYOU STUPIOD, YOU NEED A FILE WITH .ber\n");
		exit (1);
	}
	map = map_construct(av[1]);
	portal_fill(map, n);
	check_portals(map);
	start_window(&map);
}
