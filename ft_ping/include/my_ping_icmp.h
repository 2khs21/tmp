/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ping_icmp.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunsoo <hyunsoo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:00:40 by hyunsoo           #+#    #+#             */
/*   Updated: 2026/03/06 14:34:53 by hyunsoo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_PING_ICMP_H
# define MY_PING_ICMP_H

# include <stdint.h>
# include <sys/time.h>

# define ICMP_ECHO_REQUEST	8
# define ICMP_ECHO_REPLY	0
# define ICMP_TIME_EXCEEDED	11
# define ICMP_DEST_UNREACH	3

# define ICMP_HDR_SIZE		8
# define IP_HDR_SIZE		20
# define TIMESTAMP_SIZE		16

typedef struct s_icmp_hdr
{
	uint8_t		type;
	uint8_t		code;
	uint16_t	checksum;
	uint16_t	id;
	uint16_t	seq;
}	t_icmp_hdr;

typedef struct s_icmp_packet
{
	t_icmp_hdr		hdr;
	struct timeval	timestamp;
	unsigned char	padding[1500];
}	t_icmp_packet;

#endif