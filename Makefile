# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:07:05 by yobougre          #+#    #+#              #
#    Updated: 2022/06/06 15:58:43 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c\
			srcs/parsing/parse_color.c\
			srcs/parsing/parse_texture.c\
			srcs/parsing/parse.c\
			srcs/utils.c

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

.PHONY: bonus all clean fclean re
