# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 11:07:05 by yobougre          #+#    #+#              #
#    Updated: 2022/06/18 17:57:33 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	srcs/main.c\
			srcs/parsing/parse_texture.c\
			srcs/parsing/parse_color.c\
			srcs/parsing/parsing.c\
			srcs/parsing/parse_map.c\
			srcs/parsing/init_player.c \
			srcs/parsing/utils_parsing/utils_parsing1.c\
			srcs/parsing/utils_parsing/utils_parsing2.c\
			srcs/parsing/utils_parsing/utils_max_x_y.c \
			srcs/parsing/check_map/check_map.c \
			srcs/parsing/check_map/check_map2.c \
			srcs/tools/singleton.c\
			srcs/tools/singleton_2.c \
			srcs/tools/hasta_la_vista.c \
			srcs/hook/hook.c \
			srcs/hook/hook_movement.c \
			srcs/hook/hook_rotate.c \
			srcs/video/video_loop.c \
			srcs/video/video_utils.c \
			srcs/raycasting/raycasting.c \
			srcs/raycasting/raycasting_2.c \
			srcs/raycasting/rc_utils.c \
			srcs/texture/utils_texture/init_texture.c \

INC		=	includes/cub3d.h

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -g3 -I includes/

MLX		=	mlx_Linux

OBJS	=	$(SRCS:.c=.o)

RM		=	rm -f

NAME	=	cub3d

MLX_MACOS =  -Lmlx -framework OpenGL -framework AppKit

#.c.o:
#	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


all: $(NAME)

$(NAME): $(MLX) $(OBJS) $(INC) 
		 @$(MAKE) -C libft
		 @echo "cub3d : libft compiled"
		 $(CC) -g $(CFLAGS) -o $(NAME) $(OBJS) $(INC) libft/libft.a -Lmlx -lmlx_Linux -lXext -lX11 -lm -lz
		 @echo "cub3d : compiled"

$(MLX):
		cd mlx && ./configure
		@echo "cub3d : minilibx compiled" 

macos:  $(OBJS)
		$(MAKE) -C libft
		@echo "cub3d : libft compiled"
		@$(CC) $(MLX_MACOS) $(CFLAGS) $^ minilibx_macos/libmlx.a libft/libft.a -o $(NAME)
		@echo "cub3d : compiled"
	
libft: 
		

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
