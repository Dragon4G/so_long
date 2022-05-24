/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bantunes <bantunes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:26:07 by bantunes          #+#    #+#             */
/*   Updated: 2022/04/27 11:39:54 by bantunes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new || !lst)
		return (NULL);
	if (*lst)
	{
		tmp = *lst;
		while (tmp -> next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
	return (lst);
}
