# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyunkim2 <hyunkim2@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 07:03:55 by hyunkim2          #+#    #+#              #
#    Updated: 2023/05/19 03:36:49 by hyunkim2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INC = libft.h

M_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		 ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c\
		 ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
		 ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c\
		 ft_strnstr.c ft_atoi.c ft_strdup.c ft_substr.c ft_strjoin.c \
		 ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		 ft_calloc.c

M_OBJS = ${M_SRCS:.c=.o}

B_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		 ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

B_OBJS = ${B_SRCS:.c=.o}

NAME = libft.a 
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

ifdef BONUS
	OBJS = ${M_OBJS} ${B_OBJS}
else
	OBJS = ${M_OBJS}

endif

all: $(NAME)

$(NAME): ${OBJS} ${INC}
	ar rsc $(NAME) ${OBJS}

bonus:
	make BONUS=1 $(NAME)

${M_OBJS}: ${M_SRCS}
	${CC} -c ${CFLAGS} ${M_SRCS}

${B_OBJS}: ${B_SRCS}
	${CC} -c ${CFLAGS} ${B_SRCS}

clean:
	${RM} ${B_OBJS} ${M_OBJS}

fclean: clean
	${RM} $(NAME)

re: 
	make fclean
	make all

.PHONY: all clean fclean re bonus
