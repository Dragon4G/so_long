/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:16:39 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/10 11:26:28 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*verif_buffer(char **x, char **buffer, size_t buffer_len)
{
	char	*axe;
	char	*tmp;
	size_t	i;

	i = ft_strlen(*x);
	axe = (char *)malloc(sizeof(char) * (buffer_len + i + 1));
	if (!axe)
		return (NULL);
	ft_memcpy(axe, *x, i);
	ft_memcpy(axe + i, *buffer, buffer_len);
	axe[i + buffer_len] = '\0';
	tmp = ft_strdup((*buffer) + buffer_len);
	if (*x)
		free (*x);
	*x = tmp;
	return (axe);
}

static char	*put_storage(char **x, char **buffer, size_t i)
{
	char	*tmp;
	char	*axe;

	axe = NULL;
	if (i <= 0)
	{
		if (i == 0 && *x)
		{
			axe = (*x);
			*x = NULL;
		}
		return (axe);
	}
	(*buffer)[i] = '\0';
	tmp = ft_strchr(*buffer, '\n');
	if (tmp)
		axe = verif_buffer(x, buffer, (tmp - *buffer) + 1);
	else
	{
		tmp = ft_strjoin(*x, *buffer);
		if (*x)
			free (*x);
		*x = tmp;
	}
	return (axe);
}

static char	*verif_storage(char **x, size_t size)
{
	char	*tmp;
	char	*axe;
	size_t	i;

	if (size < 0)
		return (NULL);
	axe = (char *)malloc(sizeof(char) * size + 1);
	if (!axe)
		return (NULL);
	i = -1;
	while (++i != size)
		axe[i] = (*x)[i];
	axe[i] = '\0';
	tmp = ft_strdup(*x + i);
	free (*x);
	*x = tmp;
	return (axe);
}

char	*get_next_line(int fd)
{
	static char	*x;
	char		*buffer;
	char		*axe;
	size_t		i;

	if ((read(fd, 0, 0) == -1) || (fd < 0 || fd > 1024) || BUFFER_SIZE <= 0)
		return (0);
	i = 1;
	axe = NULL;
	buffer = ft_strchr(x, '\n');
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (0);
		while (axe == NULL && i > 0)
		{
			i = read(fd, buffer, BUFFER_SIZE);
			axe = put_storage(&x, &buffer, i);
		}
		free (buffer);
		return (axe);
	}
	axe = verif_storage(&x, (buffer - x) + 1);
	return (axe);
}
