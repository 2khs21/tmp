/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:16:01 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/11/23 13:30:19 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	int		i;	
	char	*s1;

	len = ft_strlen(s);
	i = 0;
	s1 = (char *)s;
	if ((char)c == 0)
		return (s1 + len);
	while (i <= len)
	{
		if (s1[len - i] == (char)c)
			return (s1 + len - i);
		i++;
	}
	return (0);
}
