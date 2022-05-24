/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:49:41 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/16 15:38:50 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

//# define malloc(x) NULL

typedef struct s_data {
	void	*img;
	void	*chao;
	void	*parede;
	void	*player;
	void	*player2;
	void	*porta;
	void	*portal;
	void	*collect;
	void	*blue1;
	void	*blue2;
	void	*blue3;
	void	*blue4;
	void	*blue5;
	void	*blue6;
	void	*blue7;
	void	*blue8;
	void	*pico;
	char	*addr;
	int		size;
	int		moves;
	int		x;
	int		y;
	char	teleport[25];
	int		teleport1x[25];
	int		teleport1y[25];
	int		teleport2x[25];
	int		teleport2y[25];
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		points;
	int		img_width;
	int		img_height;
	int		i;
	int		j;
	int		n;
	int		exit;
	int		colle;
	int		pla;
	int		holo[25];
	int		side;
	int		end;
	int		image_open;
}				t_data;

t_data	*img(void);

void	print_num(void);

void	points(char ***map);

char	**map_construct(char *name);

void	start_window(char ***map);

void	reset_img(char ***map);

int		reset_num2(char ***map);

int		my_print_color(t_data img, char **map);

void	move_up(char ***map);

void	move_left(char ***map);

void	move_right(char ***map);

void	move_down(char ***map);

void	check_portals(char **map);

void	find_portals_up(char ***map, int n);

void	find_portals_down(char ***map, int n);

void	find_portals_right(char ***map, int n);

void	find_portals_left(char ***map, int n);

int		ft_free(char **map);

void	print_chao(t_data img, int x, int y);

void	print_parede(t_data img, int x, int y);

void	print_player(t_data img, int x, int y);

void	print_porta(t_data img, int x, int y);

void	print_portal(t_data img, int x, int y, char **map);

void	find_right(char ***map, int n);

int		check_map(char ***mape, int size, unsigned int m);

int		check_map2(char ***mape, int size);

char	**linked_to_2dstring(t_list *n, int a);

void	you_end(char ***map);

#endif