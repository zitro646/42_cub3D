# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: potero-d <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 11:07:15 by potero-d          #+#    #+#              #
#    Updated: 2022/09/24 18:43:58 by potero           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = cub.c matrix_size.c map.c matrix.c\
	   screen.c key_hook.c angle.c ray.c dda_ray.c dda_horizontal_check.c dda_vertical_check.c\
	   gnl/get_next_line_utils.c gnl/get_next_line.c\

LIBFT_PATH = libft/

OBJS = $(SRCS:.c=.o)

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

%.o:%.c
		$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o) -I$(LIBFT_PATH)
RM = rm -f

$(NAME): $(OBJS)
		@make -C $(LIBFT_PATH) --silent
		$(CC) $(CFLAGS) $(OBJS) -Imlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) -I./libft -L./libft -lft
	#	$(CC) $(CFLAGS) $(OBJS) -lmlx -L/usr/X11/lib -lXext -lX11 -lm -o $(NAME)  -I./libft -L./libft -lft

all: $(NAME)  


clean:
			$(RM) $(OBJS)
			@make -C $(LIBFT_PATH) clean --silent

fclean: clean
			$(RM) $(NAME)
			@make -C $(LIBFT_PATH) fclean --silent

re: fclean $(NAME)

.PHONY: all clean fcelan re
