# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoaik <akoaik@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/26 21:04:28 by akoaik            #+#    #+#              #
#    Updated: 2025/08/27 12:57:04 by akoaik           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = srcs
GNL_DIR = get_next_line
MLX_DIR = mlx
PRINTF_DIR = ft_printf

SRCS = $(SRC_DIR)/main.c \
       $(SRC_DIR)/render_map.c \
       $(SRC_DIR)/exit.c \
       $(SRC_DIR)/images.c \
       $(SRC_DIR)/mini_helper.c \
       $(SRC_DIR)/ft_memset.c \
       $(SRC_DIR)/free.c \
       $(SRC_DIR)/helper.c \
       $(SRC_DIR)/draw.c \
       $(SRC_DIR)/mouvments.c \
       $(SRC_DIR)/duplication.c \
       $(SRC_DIR)/path.c \
       $(SRC_DIR)/read.c \
       $(SRC_DIR)/ft_itoa.c \
       $(SRC_DIR)/ft_strjoin.c


GNL_SRCS = $(GNL_DIR)/get_next_line.c \
           $(GNL_DIR)/get_next_line_utils.c

PRINTF_SRCS = $(PRINTF_DIR)/ft_printf.c \
              $(PRINTF_DIR)/ft_putchar.c \
              $(PRINTF_DIR)/ft_putstr.c \
              $(PRINTF_DIR)/ft_putnbr.c \
              $(PRINTF_DIR)/ft_hexa.c \
              $(PRINTF_DIR)/ft_print_pointer.c \
              $(PRINTF_DIR)/ft_putnbr_hex.c \
              $(PRINTF_DIR)/ft_putnbr_unsigned.c


OBJS = $(SRCS:.c=.o) $(GNL_SRCS:.c=.o) $(PRINTF_SRCS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -I$(MLX_DIR) -I$(GNL_DIR) -I$(PRINTF_DIR)
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_FLAGS = -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(MLX_LIB)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(MLX_LIB) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
