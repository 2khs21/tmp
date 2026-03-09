/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:17:43 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/11/15 03:18:27 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(s);
	d = (char *)malloc((len + 1) * sizeof(char));
	if (!d)
		return (0);
	i = 0;
	while (i < len)
	{
		d[i] = f(i, s[i]);
		i++;
	}
	d[i] = 0;
	return (d);
}
