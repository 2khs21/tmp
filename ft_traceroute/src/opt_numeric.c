/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_numeric.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:36 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:32 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"

int	opt_max_hops(int argc, char **argv, int *i, t_trace *t)
{
	int	n;

	if ((*i + 1) >= argc)
		return (1);
	if (parse_u32(argv[*i + 1], &n) != 0)
		return (1);
	if (n < 1 || n > 255)
		return (1);
	t->opts.max_hops = n;
	*i = *i + 1;
	return (0);
}

int	opt_nqueries(int argc, char **argv, int *i, t_trace *t)
{
	int	n;

	if ((*i + 1) >= argc)
		return (1);
	if (parse_u32(argv[*i + 1], &n) != 0)
		return (1);
	if (n < 1 || n > 10)
		return (1);
	t->opts.nqueries = n;
	*i = *i + 1;
	return (0);
}

int	opt_port(int argc, char **argv, int *i, t_trace *t)
{
	int	n;

	if ((*i + 1) >= argc)
		return (1);
	if (parse_u32(argv[*i + 1], &n) != 0)
		return (1);
	if (n < 1 || n > 65535)
		return (1);
	t->opts.port = n;
	*i = *i + 1;
	return (0);
}

int	opt_tos(int argc, char **argv, int *i, t_trace *t)
{
	int	n;

	if ((*i + 1) >= argc)
		return (1);
	if (parse_u32(argv[*i + 1], &n) != 0)
		return (1);
	if (n < 0 || n > 255)
		return (1);
	t->opts.tos = n;
	*i = *i + 1;
	return (0);
}
