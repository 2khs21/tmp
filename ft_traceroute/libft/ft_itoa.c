/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 02:37:35 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/11/29 10:38:02 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	len;

	len = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nb;
	int		len;

	nb = n;
	len = num_len(nb);
	num = (char *)malloc((len + 1 + (n < 0)) * sizeof(char));
	if (!num)
		return (0);
	if (n == -2147483648)
	{
		ft_strlcpy(num, "-2147483648", 12);
		return (num);
	}
	if (nb < 0)
		nb *= -1;
	num[len + (n < 0)] = 0;
	num[0] = '-';
	while (len)
	{
		num[len-- - 1 + (n < 0)] = nb % 10 + '0';
		nb /= 10;
	}
	return (num);
}
