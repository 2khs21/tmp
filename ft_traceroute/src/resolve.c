/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:40 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:43 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <stdio.h>

int	resolve_host(t_trace *t)
{
	struct addrinfo	hints;
	struct addrinfo	*res;
	int				ret;

	ft_bzero(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_DGRAM;
	ret = getaddrinfo(t->host, NULL, &hints, &res);
	if (ret != 0)
	{
		fprintf(stderr, "traceroute: %s: %s\n", t->host, gai_strerror(ret));
		return (1);
	}
	t->dest = *(struct sockaddr_in *)res->ai_addr;
	t->dest.sin_port = htons(t->opts.port);
	ft_strlcpy(t->ip_str, inet_ntoa(t->dest.sin_addr), INET_ADDRSTRLEN);
	freeaddrinfo(res);
	return (0);
}
