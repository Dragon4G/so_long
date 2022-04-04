#include "so_long.h"

char	**linked_to_2dstring(t_list *n, int a)
{
	t_list	*tmp;
	char	**mape;
	int		i;

	i = 0;
	tmp = n;
	mape = malloc(sizeof(char *) * (a + 2));
	tmp = tmp->next;
	while (tmp != NULL) 
	{
		mape[i] = tmp->content;
		tmp = tmp->next;
		// ft_printf("%s\n", mape[i]);
		i++;
	}
	mape[i] = NULL;
	return (mape);
}

char	**map_construct(char *name)
{
	int	fd;
	t_list *list;
	int i;
	char	**mape;

	fd = open(name, O_RDONLY);
	i = 0;
	while (ft_lstadd_back(&list, ft_lstnew(get_next_line(fd))))
		i++;
	mape = linked_to_2dstring(list, i);
	ft_lstclear(&list, NULL);
	close(fd);
	return (mape);
}

int	reset_num2(char ***map)
{
	int		i;
	int		j;

	i = -1;
	while ((*map)[++i] != NULL)
	{
		j = -1;
		while ((*map)[i][++j] != '\0')
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
	}
	reset_img(map);
	return (0);
}