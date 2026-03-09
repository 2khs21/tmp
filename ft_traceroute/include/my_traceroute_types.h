/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_traceroute_types.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:36:13 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:36:18 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TRACEROUTE_TYPES_H
# define MY_TRACEROUTE_TYPES_H

# include <netinet/in.h>

typedef struct s_opts
{
	int		help;
	int		max_hops;
	int		nqueries;
	char	*interface;
	int		port;
	char	*source_addr;
	int		tos;
}	t_opts;

typedef struct s_trace
{
	char				*host;
	t_opts				opts;
	int					send_sock;
	int					recv_sock;
	struct sockaddr_in	dest;
	char				ip_str[INET_ADDRSTRLEN];
}	t_trace;

typedef int	(*t_opt_fn)(int argc, char **argv, int *i, t_trace *t);

typedef struct s_opt_entry
{
	char		opt;
	t_opt_fn	fn;
}	t_opt_entry;

typedef struct s_long_opt_entry
{
	char		*name;
	t_opt_fn	fn;
}	t_long_opt_entry;

typedef struct s_recv_result
{
	int		type;
	int		code;
	int		reached;
	double	rtt;
	char	from_ip[INET_ADDRSTRLEN];
}	t_recv_result;

#endif