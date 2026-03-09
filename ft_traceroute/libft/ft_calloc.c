/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 03:33:39 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/12/02 18:34:21 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*dest;

	if (size && (count * size) / size != count)
		return (0);
	dest = (void *)malloc(count * size);
	if (!dest)
		return (0);
	ft_memset(dest, 0, count * size);
	return (dest);
}
