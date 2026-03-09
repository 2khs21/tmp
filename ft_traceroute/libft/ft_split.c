/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:11:43 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/12/01 10:44:13 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	spl_free(char **spl)
{
	size_t	i;

	i = 0;
	while (spl[i])
	{
		free(spl[i]);
		i++;
	}
	free(spl);
}

static char	**spl_dup(char const *s, char c, char **spl, size_t cnt)
{
	size_t	k;
	size_t	i;
	size_t	j;

	k = 0;
	i = 0;
	j = 0;
	if (spl == 0)
		return (0);
	while (j < cnt)
	{
		while (s[i] == c && s[i])
			i++;
		k = 0;
		while (s[i] != c && s[i])
		{
			spl[j][k] = s[i];
			k++;
			i++;
		}
		spl[j][k] = 0;
		j++;
	}
	spl[j] = 0;
	return (spl);
}

static char	**spl_malloc(char const *s, char c, char **spl, size_t cnt)
{
	size_t	i;
	size_t	j;
	size_t	tem;

	i = 0;
	j = 0;
	while (j < cnt)
	{
		tem = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			i++;
			tem++;
		}
		spl[j] = (char *)malloc(sizeof(char) * (tem + 1));
		if (!spl[j])
		{
			spl_free(spl);
			return (0);
		}
		j++;
	}
	return (spl);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	cnt;
	char	**spl;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			cnt++;
		while (s[i] != c && s[i])
			i++;
	}
	spl = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!spl)
		return (0);
	spl[cnt] = 0;
	if (cnt == 0)
		return (spl);
	spl = spl_malloc(s, c, spl, cnt);
	spl = spl_dup(s, c, spl, cnt);
	return (spl);
}
