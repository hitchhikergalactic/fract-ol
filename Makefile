SRCS = main.c \
       fractol.c \
       rendering_fractol.c \
       events.c \
       utils.c \
       utils_hooks.c \
       utils_math.c 

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror  -fsanitize=address -fsanitize=leak  -g3
RM_RF = rm -rf
NAME = fractol
MLX_PATH = minilibx-linux
LDFLAGS = -L$(MLX_PATH) -lmlx -lGL -lX11 -lXext -lm
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)/$(MLX_NAME)

all: $(MLX) $(NAME)

$(MLX):
	@make -C $(MLX_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	@if [ -e "$(OBJS)" -o -e "$(MLX_PATH)/$(OBJS)" ]; then \
		$(RM_RF) $(OBJS); \
		@make -C $(MLX_PATH) clean; \
	else \
		echo "\033[3;32m....Nothing to clean\033[0m"; \
	fi

fclean:
	@if [ -e "$(NAME)" -o -e "$(MLX)" ]; then \
		$(RM_RF) $(NAME) $(OBJS); \
		make -C $(MLX_PATH) clean; \
		$(RM_RF) $(MLX); \
	else \
		echo "\033[3;31m....Nothing to fclean\033[0m";\
	fi

re: fclean all

.PHONY: clean fclean all re

