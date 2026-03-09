/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_traceroute_proto.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:35:46 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:36:06 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_TRACEROUTE_PROTO_H
# define MY_TRACEROUTE_PROTO_H

# include "my_traceroute_types.h"

int		parse_args(int argc, char **argv, t_trace *t);

int		dispatch_opt(int argc, char **argv, int *i, t_trace *t);

int		parse_u32(const char *s, int *out);

int		opt_help(int argc, char **argv, int *i, t_trace *t);
int		opt_max_hops(int argc, char **argv, int *i, t_trace *t);
int		opt_nqueries(int argc, char **argv, int *i, t_trace *t);
int		opt_interface(int argc, char **argv, int *i, t_trace *t);
int		opt_port(int argc, char **argv, int *i, t_trace *t);
int		opt_source(int argc, char **argv, int *i, t_trace *t);
int		opt_tos(int argc, char **argv, int *i, t_trace *t);

void	print_usage(void);

int		create_sockets(t_trace *t);
void	close_sockets(t_trace *t);

int		set_socket_options(t_trace *t);

int		resolve_host(t_trace *t);

int		traceroute_loop(t_trace *t);

int		set_ttl(t_trace *t, int ttl);
int		send_probe(t_trace *t, int ttl, int probe);

int		recv_probe(t_trace *t, t_recv_result *res);

#endif