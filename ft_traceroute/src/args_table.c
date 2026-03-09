/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:26 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:40:50 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_traceroute.h"

static const t_opt_entry		g_opt_tab[] = {{'m', opt_max_hops},\
	{'q', opt_nqueries},\
	{'i', opt_interface},\
	{'p', opt_port},\
	{'s', opt_source},\
	{'t', opt_tos},\
	{0, 0}\
};

static const t_long_opt_entry	g_long_opt_tab[] = {{"help", opt_help},\
	{0, 0}\
};

static int	dispatch_long_opt(int argc, char **argv, int *i, t_trace *t)
{
	int			j;
	const char	*name;

	name = argv[*i] + 2;
	j = 0;
	while (g_long_opt_tab[j].name)
	{
		if (ft_strncmp(name, g_long_opt_tab[j].name,
				ft_strlen(g_long_opt_tab[j].name) + 1) == 0)
			return (g_long_opt_tab[j].fn(argc, argv, i, t));
		j++;
	}
	return (1);
}

static int	dispatch_short_opt(int argc, char **argv, int *i, t_trace *t)
{
	int	j;

	j = 0;
	while (g_opt_tab[j].opt)
	{
		if (argv[*i][1] == g_opt_tab[j].opt && argv[*i][2] == '\0')
			return (g_opt_tab[j].fn(argc, argv, i, t));
		j++;
	}
	return (1);
}

int	dispatch_opt(int argc, char **argv, int *i, t_trace *t)
{
	if (argv[*i][1] == '-')
		return (dispatch_long_opt(argc, argv, i, t));
	return (dispatch_short_opt(argc, argv, i, t));
}
