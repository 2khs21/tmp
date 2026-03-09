/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:24 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:37:30 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <limits.h>

int	parse_u32(const char *s, int *out)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	if (!s || !s[0])
		return (1);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (1);
		n = (n * 10) + (s[i] - '0');
		if (n > INT_MAX)
			return (1);
		i++;
	}
	*out = (int)n;
	return (0);
}
