/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:49 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:58 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <stdio.h>

void	print_usage(void)
{
	printf("Usage: my_traceroute [--help] [-m max_hops] [-q nqueries]\n");
	printf("       [-i interface] [-p port] [-s source] [-t tos] <host>\n");
}
