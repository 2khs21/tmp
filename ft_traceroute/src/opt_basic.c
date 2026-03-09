/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:34 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:39:38 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"

int	opt_help(int argc, char **argv, int *i, t_trace *t)
{
	(void)argc;
	(void)argv;
	(void)i;
	t->opts.help = 1;
	return (0);
}

int	opt_interface(int argc, char **argv, int *i, t_trace *t)
{
	if ((*i + 1) >= argc)
		return (1);
	t->opts.interface = argv[*i + 1];
	*i = *i + 1;
	return (0);
}

int	opt_source(int argc, char **argv, int *i, t_trace *t)
{
	if ((*i + 1) >= argc)
		return (1);
	t->opts.source_addr = argv[*i + 1];
	*i = *i + 1;
	return (0);
}
