/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:28 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:36:29 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"

static void	init_opts(t_trace *t)
{
	t->host = 0;
	t->opts.help = 0;
	t->opts.max_hops = DEFAULT_MAX_HOPS;
	t->opts.nqueries = DEFAULT_NQUERIES;
	t->opts.interface = 0;
	t->opts.port = DEFAULT_PORT;
	t->opts.source_addr = 0;
	t->opts.tos = DEFAULT_TOS;
}

static int	fail_usage(void)
{
	print_usage();
	return (1);
}

static int	finalize_parse(t_trace *t)
{
	if (t->opts.help)
	{
		print_usage();
		return (0);
	}
	if (!t->host)
		return (fail_usage());
	return (0);
}

int	parse_args(int argc, char **argv, t_trace *t)
{
	int	i;

	i = 1;
	init_opts(t);
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] != '\0')
		{
			if (dispatch_opt(argc, argv, &i, t) != 0)
				return (fail_usage());
		}
		else if (!t->host)
			t->host = argv[i];
		else
			return (fail_usage());
		i++;
	}
	return (finalize_parse(t));
}
