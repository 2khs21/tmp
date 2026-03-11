NAME	=	ft_ping

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -fsanitize=address
DEPFLAGS=	-MMD -MP

INC_DIR	=	include
SRC_DIR	=	src
OBJ_DIR	=	obj

INCLUDES =	-I$(INC_DIR)

SRCS	=	$(SRC_DIR)/main.c \
			$(SRC_DIR)/args.c \
			$(SRC_DIR)/args_num.c \
			$(SRC_DIR)/args_table.c \
			$(SRC_DIR)/icmp_build.c \
			$(SRC_DIR)/icmp_util.c \
			$(SRC_DIR)/opt_basic.c \
			$(SRC_DIR)/opt_numeric.c \
			$(SRC_DIR)/opt_pattern.c \
			$(SRC_DIR)/ping.c \
			$(SRC_DIR)/ping_print.c \
			$(SRC_DIR)/recv.c \
			$(SRC_DIR)/resolve.c \
			$(SRC_DIR)/send.c \
			$(SRC_DIR)/signal.c \
			$(SRC_DIR)/socket.c \
			$(SRC_DIR)/stats.c \
			$(SRC_DIR)/usage.c \
			$(SRC_DIR)/verbose.c
OBJS	=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS	=	$(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -lm

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re