# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aborges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/24 14:20:45 by aborges           #+#    #+#              #
#    Updated: 2024/07/24 14:59:29 by aborges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

NAME = fractol
OTHER_EXECS = includes/ft_printf/libftprintf.a includes/libft/libft.a


SRCS_DIR = srcs
SRCS = $(wildcard $(SRCS_DIR)/*.c)
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(SRCS_DIR)/%.o)

SRCS_DIR1 = includes/ft_printf
SRCS1 = $(wildcard $(SRCS_DIR1)/*.c)
OBJS1 = $(SRCS1:$(SRCS_DIR1)/%.c=$(SRCS_DIR1)/%.o)

SRCS_DIR3 = includes/libft
SRCS3 = $(wildcard $(SRCS_DIR3)/*.c)
OBJS3 = $(SRCS3:$(SRCS_DIR3)/%.c=$(SRCS_DIR3)/%.o)


LIB_DIR = ./includes/libft
LIB_DIR1 = ./includes/ft_printf
LIB_DIR2 = ./minilibx

LIBFT = $(LIB_DIR)/libft.a
PRINTF = $(LIB_DIR1)/libftprintf.a
MINILIBX = $(LIB_DIR2)/libmlx_Linux.a

RM = rm -f


all: $(NAME)


$(NAME): $(OBJS) $(OBJS1) $(OBJS3) $(LIBFT) $(PRINTF) $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJS) $(OBJS1) $(OBJS3) $(LIBFT) $(PRINTF) $(MINILIBX) -o $(NAME) -lXext -lX11 -lm


$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCS_DIR1)/%.o: $(SRCS_DIR1)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(SRCS_DIR3)/%.o: $(SRCS_DIR3)/%.c
	$(CC) $(CFLAGS) -c $< -o $@


$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(PRINTF):
	$(MAKE) -C $(LIB_DIR1)

$(MINILIBX):
	$(MAKE) -C $(LIB_DIR2)

clean:
	$(MAKE) clean -C $(LIB_DIR)
	$(MAKE) clean -C $(LIB_DIR1)
	$(MAKE) clean -C $(LIB_DIR2)
	$(RM) $(OBJS)
	$(RM) $(OBJS1)
	$(RM) $(OBJS3)

fclean: clean
	$(RM) $(NAME) $(OTHER_EXECS)

re: fclean all

.PHONY: all clean fclean re