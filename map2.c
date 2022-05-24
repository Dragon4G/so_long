/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:13:30 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/16 15:24:49 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_construct_2(char **mape, t_list *list, int i, int fd)
{
	unsigned int	m;

	mape = linked_to_2dstring(list, i);
	m = strlen(mape[0]);
	ft_lstclear(&list, NULL);
	close(fd);
	if (check_map(&mape, i, m) == 1 || check_map2(&mape, i) == 1)
	{
		ft_printf("Erro\nCan't read correctly this map\n");
		ft_free(mape);
	}
	if ((*img()).colle == 0 || (*img()).pla == 0 || (*img()).exit == 0)
	{
		ft_printf("Erro\ndidn't you miss something ?\n");
		ft_free(mape);
	}
	return (mape);
}

char	**map_construct(char *name)
{
	int				fd;
	t_list			*list;
	int				i;
	char			**mape;

	mape = NULL;
	list = NULL;
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCan't read\n");
		exit(1);
	}
	i = 0;
	while (ft_lstadd_back(&list, ft_lstnew(get_next_line(fd))))
		i++;
	if (!i)
	{
		ft_printf("Erro\nnothing on the map\n");
		exit(1);
	}
	mape = map_construct_2(mape, list, i, fd);
	return (mape);
}

void	reset_num_2(char ***map, int i, int j)
{
	if ((*map)[i][j] == '9')
		(*map)[i][j] = '0';
	if ((*map)[i][j] == '8')
		(*map)[i][j] = '9';
	if ((*map)[i][j] == '7')
		(*map)[i][j] = '8';
	if ((*map)[i][j] == '6')
		(*map)[i][j] = '7';
	if ((*map)[i][j] == '5')
		(*map)[i][j] = '6';
	if ((*map)[i][j] == '4')
		(*map)[i][j] = '5';
	if ((*map)[i][j] == '3')
		(*map)[i][j] = '4';
	if ((*map)[i][j] == '2')
		(*map)[i][j] = '3';
}

int	reset_num2(char ***map)
{
	int		i;
	int		j;

	if ((*img()).end == 0)
	{
		i = -1;
		while ((*map)[++i] != NULL)
		{
			j = -1;
			while ((*map)[i][++j] != '\0')
				reset_num_2(map, i, j);
		}
	}
	reset_img(map);
	return (0);
}
