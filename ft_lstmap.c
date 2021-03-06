/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukarape <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 14:15:11 by lukarape          #+#    #+#             */
/*   Updated: 2021/01/30 18:13:10 by lukarape         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new_lst;
	t_list		*position_new;
	t_list		*position_old;

	if (!lst || !(new_lst = ft_lstnew((*f)(lst->content))))
		return (NULL);
	position_new = new_lst;
	position_old = lst->next;
	while (position_old)
	{
		if (!(position_new->next = ft_lstnew((*f)(position_old->content))))
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		position_new = position_new->next;
		position_old = position_old->next;
	}
	return (new_lst);
}
