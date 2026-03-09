/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:59:16 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:17:06 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ping_proto.h"
#include <stdio.h>

void	print_usage(void)
{
	fprintf(stderr, "Usage: my_ping [-v] [-?] [-c count] [-i interval] \
[-p pattern] [-s size] [-T ttl] <host>\n");
}
