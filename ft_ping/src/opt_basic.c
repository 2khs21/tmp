/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_basic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:58:50 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:00:32 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ping_proto.h"

int	opt_verbose(int argc, char **argv, int *i, t_ping *p)
{
	(void)argc;
	(void)argv;
	(void)i;
	p->opts.verbose = 1;
	return (0);
}

int	opt_help(int argc, char **argv, int *i, t_ping *p)
{
	(void)argc;
	(void)argv;
	(void)i;
	p->opts.help = 1;
	return (0);
}
