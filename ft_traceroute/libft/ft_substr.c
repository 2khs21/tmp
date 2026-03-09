/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:15:08 by hyunkim2          #+#    #+#             */
/*   Updated: 2023/01/27 04:43:56 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substr2(char *d, char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && s[start + i])
	{
		d[i] = s[start + i];
		i++;
	}
	d[i] = 0;
	return (d);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (s_len <= start)
	{
		d = (char *)malloc(sizeof(char));
		if (!d)
			return (0);
		d[0] = 0;
		return (d);
	}
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (0);
	d = ft_substr2(d, s, start, len);
	return (d);
}
