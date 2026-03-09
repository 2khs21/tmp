/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:43 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:40:07 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

static int	set_tos(t_trace *t)
{
	if (t->opts.tos == 0)
		return (0);
	if (setsockopt(t->send_sock, IPPROTO_IP, IP_TOS,
			&t->opts.tos, sizeof(t->opts.tos)) < 0)
	{
		fprintf(stderr, "traceroute: setsockopt TOS: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}

static int	set_interface(t_trace *t)
{
	struct ifreq	ifr;

	if (!t->opts.interface)
		return (0);
	ft_bzero(&ifr, sizeof(ifr));
	ft_strlcpy(ifr.ifr_name, t->opts.interface, IFNAMSIZ);
	if (setsockopt(t->send_sock, SOL_SOCKET, SO_BINDTODEVICE,
			&ifr, sizeof(ifr)) < 0)
	{
		fprintf(stderr, "traceroute: setsockopt SO_BINDTODEVICE: %s\n",
			strerror(errno));
		return (1);
	}
	return (0);
}

static int	bind_source(t_trace *t)
{
	struct sockaddr_in	src;

	if (!t->opts.source_addr)
		return (0);
	ft_bzero(&src, sizeof(src));
	src.sin_family = AF_INET;
	if (inet_pton(AF_INET, t->opts.source_addr, &src.sin_addr) != 1)
	{
		fprintf(stderr, "traceroute: invalid source address\n");
		return (1);
	}
	if (bind(t->send_sock, (struct sockaddr *)&src, sizeof(src)) < 0)
	{
		fprintf(stderr, "traceroute: bind: %s\n", strerror(errno));
		return (1);
	}
	return (0);
}

int	set_socket_options(t_trace *t)
{
	if (set_tos(t) != 0)
		return (1);
	if (set_interface(t) != 0)
		return (1);
	if (bind_source(t) != 0)
		return (1);
	return (0);
}
