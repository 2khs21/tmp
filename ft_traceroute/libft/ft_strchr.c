/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:12:21 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/11/22 15:48:49 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;
	char	*s1;

	i = 0;
	len = ft_strlen(s);
	s1 = (char *)s;
	while (i <= len)
	{
		if (s1[i] == (char)c)
			return (s1 + i);
		i++;
	}
	return (0);
}
