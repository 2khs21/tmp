/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 02:28:48 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/12/01 15:15:44 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	find_p(char const *s1, char const *set, size_t	len, size_t i)
{
	if (i == 0)
	{
		while (is_charset(s1[i], set))
		{
			i++;
		}
		return (i);
	}
	else
	{
		i = 0;
		while (len - 1 > i && is_charset(s1[len - i - 1], set))
		{
			i++;
		}
		return (len - i - 1);
	}
}

static char	*trim(char const *s1, char *dest, size_t start, size_t end)
{
	size_t	i;

	dest = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!dest)
		return (0);
	i = 0;
	while (start + i <= end)
	{
		dest[i] = s1[start + i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;
	char	*dest;

	len = ft_strlen(s1);
	start = find_p(s1, set, len, 0);
	end = find_p(s1, set, len, len);
	dest = 0;
	if (start == len || start > end)
	{
		dest = (char *)malloc(sizeof(char));
		if (!dest)
			return (0);
		dest[0] = 0;
		return (dest);
	}
	dest = trim(s1, dest, start, end);
	return (dest);
}
