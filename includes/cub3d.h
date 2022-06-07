/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:57:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/07 17:07:04 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define SUCCESS 0
# define FAILURE -1
# define TRUE 0
# define FALSE 1

typedef struct s_trgb
{
    unsigned char b; // IMPORTANT que les valeurs soient ecrites a l'envers
    unsigned char g; // pour l'emplacement dans la memoire
    unsigned char r;
    unsigned char t;
}	t_trgb;

typedef union u_color
{
	int		hexa;
    t_trgb	trgb;
}	t_color;

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	t_color	floor;
	t_color	ceiling;
}	t_texture;

typedef struct s_player
{
	int	x;
	int	y;
}	t_player;

typedef	struct	s_map
{
	int			max_x;
	int			max_y;
	char		**map;
	int			fd;
	char		*line;
}	t_map;

typedef struct s_data
{
	t_player	player;
	t_texture	texture;
	t_map		map;
	
}	t_data;


//SINGLETON
t_data	*_data(void);

//UTILS
int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **tab);
char 	*skip_space(char *line);
void	skip_space_new(char *str, int *i);
int		is_num(char *line);
int		len_number(char *line);
void	hasta_la_vista_baby(char *str);
void	print_struct(void);
void	ft_print_map(void);

//PARSING
void	parsing(int argc, char **argv);
void	open_map(char **argv);
int		parse_data_map(char *line);
int		parse_select(char *line);
void	parse_map(char **argv);
int		parse_insert_color(char *line, t_color *color);

//CHECK MAP
void	check_map();
void	check_line_size();

//PARSING TEXTURE
int	parse_texture_north(char *line);
int	parse_texture_west(char *line);
int	parse_texture_east(char *line);
int	parse_texture_south(char *line);

//PARSING COLOR
int	parse_color_floor(char *line);
int	parse_color_ceiling(char *line);


#endif
