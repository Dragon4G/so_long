/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:09:35 by bantunes          #+#    #+#             */
/*   Updated: 2022/05/23 11:45:38 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**linked_to_2dstring(t_list *n, int a)
{
	t_list	*tmp;
	char	**mape;
	int		i;

	(void)a;
	i = 0;
	tmp = n;
	mape = malloc(sizeof(char *) * (a + 1));
	if (!mape)
	{
		ft_printf("Erro\nNULL\n");
		ft_lstclear(&n, NULL);
		exit (1);
	}
	while (tmp != NULL)
	{
		mape[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	mape[i] = NULL;
	return (mape);
}

int	check_map(char ***mape, int size, unsigned int m)
{
	(*img()).i = -1;
	while (++(*img()).i < size - 1)
	{
		(*img()).j = -1;
		while ((*mape)[(*img()).i][++(*img()).j] != '\n' )
		{
			if (strlen((*mape)[(*img()).i]) != m)
				return (1);
			else if ((*mape)[(*img()).i][0] != '1' ||
			((*mape)[(*img()).i][strlen(*mape[0]) - 2] != '1'))
				return (1);
			else if ((*mape)[0][(*img()).j] != '1' ||
			(*mape)[size - 1][(*img()).j] != '1')
				return (1);
			else if ((*mape)[(*img()).i][(*img()).j] == 'P' && (*img()).n++ > 0)
				(*mape)[(*img()).i][(*img()).j] = '0';
			else if ((*mape)[(*img()).i][(*img()).j] == 'P')
				(*img()).pla++;
			else if ((*mape)[(*img()).i][(*img()).j] == 'E')
				(*img()).exit++;
			else if ((*mape)[(*img()).i][(*img()).j] == 'C')
				(*img()).colle++;
		}
	}
	return (0);
}

int	check_map_3(char ***mape)
{
	if ((*mape)[(*img()).i][(*img()).j] != '0' &&
	(*mape)[(*img()).i][(*img()).j] != '1')
		if ((*mape)[(*img()).i][(*img()).j] != 'P' &&
		(*mape)[(*img()).i][(*img()).j] != 'E')
			if ((*mape)[(*img()).i][(*img()).j] != 'C' &&
			(*mape)[(*img()).i][(*img()).j] != 'X')
				if ((*mape)[(*img()).i][(*img()).j] < 'a' ||
				(*mape)[(*img()).i][(*img()).j] > 'z')
					return (1);
	return (0);
}

int	check_map_2(char ***mape, int n, char a)
{
	if ((*mape)[(*img()).i + 1][0] == '\n')
		return (1);
	if ((*mape)[(*img()).i][(*img()).j] == a)
	{
		++(*img()).holo[n];
		if ((*mape)[(*img()).i - 1][(*img()).j] >= 'a' &&
		(*mape)[(*img()).i - 1][(*img()).j] <= 'z')
			return (1);
		else if ((*mape)[(*img()).i + 1][(*img()).j] >= 'a' &&
		(*mape)[(*img()).i + 1][(*img()).j] <= 'z')
			return (1);
		else if ((*mape)[(*img()).i][(*img()).j - 1] >= 'a' &&
		(*mape)[(*img()).i][(*img()).j - 1] <= 'z')
			return (1);
		else if ((*mape)[(*img()).i][(*img()).j + 1] >= 'a' &&
		(*mape)[(*img()).i][(*img()).j + 1] <= 'z')
			return (1);
	}
	return (0);
}

int	check_map2(char ***mape, int size)
{
	int		n;
	char	a;
	int		b;

	b = 0;
	n = -1;
	a = 'a';
	while (++n <= 25)
	{
		(*img()).i = 0;
		while (++(*img()).i < size - 1)
		{
			(*img()).j = 0;
			while ((*mape)[(*img()).i][++(*img()).j] != '\n' )
			{
				b = check_map_2(mape, n, a);
				if (b == 1 || check_map_3(mape))
					return (1);
			}
		}
		a++;
		if ((*img()).holo[n] > 2 || (*img()).holo[n] == 1)
			return (1);
	}
	return (0);
}
