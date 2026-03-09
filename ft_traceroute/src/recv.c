/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:38 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:36:38 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/time.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

static int	wait_for_reply(t_trace *t)
{
	fd_set			fds;
	struct timeval	tv;

	FD_ZERO(&fds);
	FD_SET(t->recv_sock, &fds);
	tv.tv_sec = RECV_TIMEOUT_SEC;
	tv.tv_usec = RECV_TIMEOUT_USEC;
	return (select(t->recv_sock + 1, &fds, NULL, NULL, &tv));
}

static int	parse_icmp(unsigned char *buf, ssize_t len, t_recv_result *res)
{
	struct ip		*ip_hdr;
	struct icmp		*icmp_hdr;
	int				ip_len;

	(void)len;
	ip_hdr = (struct ip *)buf;
	ip_len = ip_hdr->ip_hl << 2;
	icmp_hdr = (struct icmp *)(buf + ip_len);
	res->type = icmp_hdr->icmp_type;
	res->code = icmp_hdr->icmp_code;
	ft_strlcpy(res->from_ip, inet_ntoa(ip_hdr->ip_src), INET_ADDRSTRLEN);
	if (res->type == ICMP_TIME_EXCEEDED)
		res->reached = 0;
	else if (res->type == ICMP_DEST_UNREACH)
		res->reached = 1;
	else
		return (0);
	return (1);
}

int	recv_probe(t_trace *t, t_recv_result *res)
{
	unsigned char	buf[RECV_BUF_SIZE];
	ssize_t			len;
	int				ret;

	ft_bzero(res, sizeof(*res));
	ret = wait_for_reply(t);
	if (ret <= 0)
		return (-1);
	len = recvfrom(t->recv_sock, buf, RECV_BUF_SIZE, 0, NULL, NULL);
	if (len < 0)
		return (-1);
	if (!parse_icmp(buf, len, res))
		return (-1);
	return (0);
}
