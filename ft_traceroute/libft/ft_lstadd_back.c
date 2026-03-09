/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:02:59 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/11/29 13:14:38 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*curr;

	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	curr = *lst;
	while (curr->next)
	{
		curr = curr->next;
	}
	curr->next = new;
}
