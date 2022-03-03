/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:13:36 by teusebio          #+#    #+#             */
/*   Updated: 2021/10/15 19:13:47 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*list;

	list = *lst;
	if (list)
	{
		while (list->next)
		{
			tmp = list->next;
			(*del)(list->content);
			free(list);
			list = tmp;
		}
		(*del)(list->content);
		free(list);
	}
	*lst = NULL;
}
