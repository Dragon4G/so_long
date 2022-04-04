/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:16:36 by bantunes          #+#    #+#             */
/*   Updated: 2022/03/10 11:29:17 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	char			*shield;
	long unsigned	i;

	i = 0;
	shield = (char *)(s);
	while (shield && *shield)
	{
		shield++;
		i++;
	}
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*a;
	const char	*b;

	a = (char *)dst;
	b = (char *)src;
	if (!dst && !src)
		return (NULL);
	while (n-- > 0)
	{
		*a++ = *b++;
	}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	s1len;
	size_t	s2len;
	char	*ptr;

	i = 0;
	ptr = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (s1 && !s2)
		return (ft_strdup(s1));
	else if (!s1 && s2)
		return (ft_strdup(s2));
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!ptr)
		return (NULL);
	while (i < (s1len + s2len + 1))
		ptr[i++] = 0;
	ft_memcpy(ptr, s1, s1len);
	ft_memcpy(ptr + s1len, s2, s2len);
	ptr[s1len + s2len] = '\0';
	return (ptr);
}

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;

	if (s)
	{
		len = ft_strlen(s);
		if (!len)
			return (NULL);
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (!str)
			return (NULL);
		ft_memcpy(str, s, len);
		*(str + len) = '\0';
		return (str);
	}
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	if (s)
	{
		tmp = (char *)(s);
		while (*tmp)
		{
			if (*tmp == (char)c)
				return (tmp);
			tmp++;
		}
		if (*tmp == c)
			return (tmp);
	}
	return (NULL);
}
