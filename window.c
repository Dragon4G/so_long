#include "so_long.h"

int	size_of_matrix(char **map)
{
	int i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

t_data	*img(void)
{
	static t_data img;
	return (&img);
}

void	reset_img(char ***map)
{
	mlx_clear_window((*img()).mlx, (*img()).win);
	my_print_color((*img()), *map);
	// mlx_put_image_to_window((*img()).mlx, (*img()).win, (*img()).img, 0, 0);
}

int key_press(int keycode, char ***map)
{
	ft_printf("%d\n", (*img()).points);
	// ft_printf("%s\n", map[3]);
	// ft_printf("%s\n", map[1]);
	if (keycode == 53)
		exit (1);
	if (keycode == 0)
		move_left(map);
	if (keycode == 1)
		move_down(map);
	if (keycode == 2)
		move_right(map);
	if (keycode == 13)
		move_up(map);
	reset_img(map);
	return (0);
}

void start_window(char ***map)
{
	int		size;

	points(map);
	size = size_of_matrix(*map);
	(*img()).mlx = mlx_init();
	(*img()).win = mlx_new_window((*img()).mlx, (strlen(**map) * 64 - 64), (size * 64), "./so_long");
	(*img()).img = mlx_new_image((*img()).mlx, (strlen(**map) * 64 - 64), (size * 64));
	(*img()).addr = mlx_get_data_addr((*img()).img, &((*img()).bits_per_pixel), &((*img()).line_length), &((*img()).endian));
	(*img()).chao = mlx_xpm_file_to_image((*img()).mlx, "./src/chao.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).parede = mlx_xpm_file_to_image((*img()).mlx, "./src/parede.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).player = mlx_xpm_file_to_image((*img()).mlx, "./src/samurai1.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).porta = mlx_xpm_file_to_image((*img()).mlx, "./src/porta.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).collect = mlx_xpm_file_to_image((*img()).mlx, "./src/collect.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue1 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue1.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue2 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue2.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue3 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue3.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue4 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue4.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue5 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue5.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue6 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue6.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue7 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue7.xpm", &(*img()).img_width, &(*img()).img_height);
	(*img()).blue8 = mlx_xpm_file_to_image((*img()).mlx, "./src/blue8.xpm", &(*img()).img_width, &(*img()).img_height);
	my_print_color((*img()), *map);
	mlx_key_hook((*img()).win, key_press, map);
	mlx_loop_hook((*img()).mlx, reset_num2, map);
	mlx_put_image_to_window((*img()).mlx, (*img()).win, (*img()).img, 0, 0);
	mlx_loop((*img()).mlx);
}