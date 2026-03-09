/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:41 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:14 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int	set_ttl(t_trace *t, int ttl)
{
	if (setsockopt(t->send_sock, IPPROTO_IP, IP_TTL,
			&ttl, sizeof(ttl)) < 0)
	{
		fprintf(stderr, "traceroute: setsockopt TTL: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}

int	send_probe(t_trace *t, int ttl, int probe)
{
	struct sockaddr_in	dest;
	ssize_t				sent;
	char				buf[1];

	buf[0] = 0;
	dest = t->dest;
	dest.sin_port = htons\
(t->opts.port + ((ttl - 1) * t->opts.nqueries) + probe);
	if (set_ttl(t, ttl) != 0)
		return (1);
	sent = sendto(t->send_sock, buf, sizeof(buf), 0,
			(struct sockaddr *)&dest, sizeof(dest));
	if (sent < 0)
	{
		fprintf(stderr, "traceroute: sendto: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}
