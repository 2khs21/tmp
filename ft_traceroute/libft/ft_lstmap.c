/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:33:51 by hyunkim2          #+#    #+#             */
/*   Updated: 2023/01/29 08:57:53 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_node;
	void	*temp;

	if (lst == 0 || f == 0)
		return (0);
	new_lst = 0;
	new_node = 0;
	while (1)
	{
		temp = f(lst->content);
		new_node = ft_lstnew(temp);
		if (!new_node)
		{
			del(temp);
			if (new_lst)
				ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, new_node);
		lst = lst -> next;
		if (!lst)
			return (new_lst);
	}
}
