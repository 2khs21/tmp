/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:32 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:36:33 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"

static int	init_trace(t_trace *t, int argc, char **argv)
{
	ft_bzero(t, sizeof(*t));
	t->send_sock = -1;
	t->recv_sock = -1;
	if (parse_args(argc, argv, t) != 0)
		return (1);
	if (t->opts.help)
		return (1);
	if (resolve_host(t) != 0)
		return (1);
	if (create_sockets(t) != 0)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_trace	t;
	int		ret;

	if (init_trace(&t, argc, argv) != 0)
		return (1);
	ret = traceroute_loop(&t);
	close_sockets(&t);
	return (ret);
}
