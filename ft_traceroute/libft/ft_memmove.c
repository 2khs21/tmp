/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:07:45 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/12/01 15:14:59 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s;
	size_t			i;

	s = (unsigned char *)src;
	i = 0;
	if ((unsigned char *)dst == src)
		return (dst);
	if ((unsigned char *)dst < s)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = s[i];
			i++;
		}
	}
	else
	{
		while (len)
		{
			((unsigned char *)dst)[i + len - 1] = s[i + len - 1];
			len--;
		}
	}
	return (dst);
}
