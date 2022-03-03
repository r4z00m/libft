/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teusebio <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 15:15:01 by teusebio          #+#    #+#             */
/*   Updated: 2021/10/16 09:40:31 by teusebio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*my_listnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (NULL == new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

static void	my_listadd_back(t_list **lst, t_list *new)
{
	t_list	*list;

	list = *lst;
	if (NULL == list)
	{
		*lst = new;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;
	void	*content;

	res = NULL;
	if (lst && f)
	{
		while (lst)
		{
			content = (*f)(lst->content);
			tmp = my_listnew(content);
			if (NULL == tmp)
			{
				ft_lstclear(&res, del);
				return (NULL);
			}
			else
				my_listadd_back(&res, tmp);
			lst = lst->next;
		}
	}
	return (res);
}
