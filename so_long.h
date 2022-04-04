#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "./get_next_line.h"
# include "./libft/libft.h"
# include "./printf/ft_printf.h"

typedef struct	s_data {
	void	*img;
	void	*chao;
	void	*parede;
	void	*player;
	void	*porta;
	void	*collect;
	void	*blue1;
	void	*blue2;
	void	*blue3;
	void	*blue4;
	void	*blue5;
	void	*blue6;
	void	*blue7;
	void	*blue8;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		points;
	int		img_width;
	int		img_height;
}				t_data;

t_data	*img(void);

void points(char ***map);

char	**map_construct(char *name);

void start_window(char ***map);

void	reset_img(char ***map);

int	reset_num2(char ***map);

int	my_print_color(t_data img, char **map);

int	move_up(char ***map);

int	move_left(char ***map);

int	move_right(char ***map);

int	move_down(char ***map);

#endif