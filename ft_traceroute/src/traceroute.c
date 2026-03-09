/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traceroute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:47 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:23 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"
#include <sys/time.h>
#include <stdio.h>

static double	calc_rtt(struct timeval *start, struct timeval *end)
{
	double	rtt;

	rtt = (end->tv_sec - start->tv_sec) * 1000.0;
	rtt += (end->tv_usec - start->tv_usec) / 1000.0;
	return (rtt);
}

static void	print_probe_result(t_recv_result *res, double rtt)
{
	if (res->from_ip[0])
		printf("  %s  %.3f ms", res->from_ip, rtt);
	else
		printf("  *");
}

static int	do_probe(t_trace *t, int ttl, int probe, t_recv_result *res)
{
	struct timeval	start;
	struct timeval	end;

	gettimeofday(&start, NULL);
	if (send_probe(t, ttl, probe) != 0)
		return (1);
	if (recv_probe(t, res) == 0)
	{
		gettimeofday(&end, NULL);
		res->rtt = calc_rtt(&start, &end);
	}
	return (0);
}

static int	do_hop(t_trace *t, int ttl)
{
	t_recv_result	res;
	int				probe;
	int				reached;

	reached = 0;
	printf("%2d", ttl);
	probe = 0;
	while (probe < t->opts.nqueries)
	{
		if (do_probe(t, ttl, probe, &res) != 0)
			return (-1);
		print_probe_result(&res, res.rtt);
		if (res.reached)
			reached = 1;
		probe++;
	}
	printf("\n");
	return (reached);
}

int	traceroute_loop(t_trace *t)
{
	int	ttl;
	int	ret;

	printf("traceroute to %s (%s), %d hops max\n",
		t->host, t->ip_str, t->opts.max_hops);
	ttl = 1;
	while (ttl <= t->opts.max_hops)
	{
		ret = do_hop(t, ttl);
		if (ret < 0)
			return (1);
		if (ret == 1)
			break ;
		ttl++;
	}
	return (0);
}
