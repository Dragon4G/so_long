#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;

	if (ac < 2)
		return (ft_printf("Error\nYou need to put a file\n"));
	if (ac == 2)
		map = map_construct(av[1]);
	if (ac > 2)
		return (ft_printf("Error\nYou have too many spaces :)\n"));
	start_window(&map);
}

