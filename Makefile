# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:07:05 by yobougre          #+#    #+#              #
#    Updated: 2022/06/07 14:59:40 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c\
			srcs/parsing/parse_texture.c\
			srcs/parsing/parse_color.c\
			srcs/parsing/parsing.c\
			srcs/utils/utils2.c\
			srcs/utils/utils1.c\
			srcs/utils/singleton.c\
			srcs/parsing/parse_map.c\
			srcs/check_map/check_map.c\
			srcs/check_map/check_map2.c

INC		=	includes/cub3d.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g3

MLX		=	mlx_Linux

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

NAME	=	cub3d

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(INC) 
		 @$(MAKE) -C libft
		 @echo "cub3d : libft compiled"
		 @$(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "cub3d : compiled"

$(MLX):
		cd mlx && ./configure
		@echo "cub3d : minilibx compiled" 
clean:
		@$(MAKE) -C libft clean
		@$(RM) $(OBJS)
		cd mlx && ./configure clean
		@echo "cub3d : objects has been erased"

fclean:	clean
		@$(MAKE) -C libft fclean
		@$(RM) $(NAME)
		@echo "cub3d : objects and name has been erased"

re: fclean all

test_leaks:
	valgrind $(NAME)

.PHONY: bonus all clean fclean re test_leaks
