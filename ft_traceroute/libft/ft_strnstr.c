/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:16:24 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/12/02 17:44:12 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*needle == 0)
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[0])
		{
			while (i + j < len && haystack[i + j] \
== needle[j] && haystack[i + j] && needle[j])
				j++;
			if (!needle[j])
				return ((char *)haystack + i);
		}
		i++;
	}
	return (0);
}
