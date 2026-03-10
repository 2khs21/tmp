/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 13:59:16 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/10 11:37:50 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_ping_proto.h"
#include <stdio.h>

void	print_usage(void)
{
	fprintf(stderr, "Usage: my_ping [-v] [-?] [-c count] [-i interval] \
[-p pattern] [-s size] [-T ttl] <host>\n");
}

void	print_help(void)
{
	fprintf(stderr,
		"Usage: my_ping [OPTION...] HOST\n"
		"Send ICMP ECHO_REQUEST packets to network hosts.\n"
		"\n"
		" Options valid for echo requests:\n"
		"\n"
		"  -c NUMBER		stop after sending NUMBER packets\n"
		"  -i NUMBER		wait NUMBER seconds between sending each packet\n"
		"      --ttl N		specify N as time-to-live\n"
		"  -T NUMBER		set type of service (TOS) to NUM\n"
		"  -v				verbose output\n"
		"  -p PATTERN		fill ICMP packet with given pattern (hex)\n"
		"  -s NUMBER		send NUMBER data octets\n"
		"\n"
		"  -?, --help		give this help list\n"
		"\n");
}
