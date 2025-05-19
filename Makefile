NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft -I. -Iminilibx-linux
SRCS = src/main.c \
	   src/check_map.c \
	   src/camin_ok.c \
	   src/check_correct_map.c \
	   src/find_player.c \
       src/map.c \
       src/validation_ber.c \
	   src/load_map.c \
	   src/close_window.c \
	   src/free_map.c \
	   src/assigned_keys.c \
	   src/movements.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx.a
LFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LFLAGS) -o $(NAME)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean
		rm -f $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re