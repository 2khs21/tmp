NAME	=	ft_traceroute

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror
DEPFLAGS=	-MMD -MP

INC_DIR	=	include
SRC_DIR	=	src
OBJ_DIR	=	obj
LIBFT_DIR=	libft

INCLUDES =	-I$(INC_DIR) -I$(LIBFT_DIR)
LIBFT	=	$(LIBFT_DIR)/libft.a

SRCS	=	$(SRC_DIR)/args.c \
			$(SRC_DIR)/args_num.c \
			$(SRC_DIR)/args_table.c \
			$(SRC_DIR)/main.c \
			$(SRC_DIR)/opt_basic.c \
			$(SRC_DIR)/opt_numeric.c \
			$(SRC_DIR)/recv.c \
			$(SRC_DIR)/resolve.c \
			$(SRC_DIR)/send.c \
			$(SRC_DIR)/socket.c \
			$(SRC_DIR)/socket_opts.c \
			$(SRC_DIR)/traceroute.c \
			$(SRC_DIR)/usage.c

OBJS	=	$(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS	=	$(OBJS:.o=.d)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEPFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re