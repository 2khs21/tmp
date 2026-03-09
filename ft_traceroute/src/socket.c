/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   socket.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:45 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:53 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

static int	create_send_socket(t_trace *t)
{
	int	sockfd;

	sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sockfd < 0)
	{
		fprintf(stderr, "traceroute: socket (UDP): %s\n", strerror(errno));
		return (1);
	}
	t->send_sock = sockfd;
	return (0);
}

static int	create_recv_socket(t_trace *t)
{
	int	sockfd;

	sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
	if (sockfd < 0)
	{
		fprintf(stderr, "traceroute: socket (ICMP): %s\n", strerror(errno));
		return (1);
	}
	t->recv_sock = sockfd;
	return (0);
}

int	create_sockets(t_trace *t)
{
	if (create_send_socket(t) != 0)
		return (1);
	if (create_recv_socket(t) != 0)
	{
		close(t->send_sock);
		return (1);
	}
	if (set_socket_options(t) != 0)
	{
		close_sockets(t);
		return (1);
	}
	return (0);
}

void	close_sockets(t_trace *t)
{
	if (t->send_sock >= 0)
		close(t->send_sock);
	if (t->recv_sock >= 0)
		close(t->recv_sock);
}
