/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:57:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/08 18:32:48 by ajung            ###   ########.fr       */
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

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define MOUSE_LEFT 1
# define MOUSE_RIGHT 3
# define MOUSE_MID 2
# define MOUSE_SCROLL_DOWN 5
# define MOUSE_SCROLL_UP 4

# define ON_KEYDOWN 2
# define ON_KEYUP 3
# define ON_MOUSEDOWN 4
# define ON_MOUSEUP 5
# define ON_MOUSEMOVE 6
# define ON_EXPOSE 12
# define ON_DESTROY 17

# define WALL '1'
# define VOID ' '

typedef struct s_trgb
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	t;
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

typedef struct s_map
{
	int			max_x;
	int			max_y;
	char		**map;
	int			fd;
	char		*line;
}	t_map;

typedef struct s_image
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}	t_image;

typedef struct s_var
{
	void	*mlx;
	void	*win;
}	t_var;
	
typedef struct s_mlx
{
	t_var	var;
	t_image	image;
}	t_mlx;

typedef struct s_data
{
	t_player	player;
	t_texture	texture;
	t_map		map;
	t_mlx		mlx;
}	t_data;

//SINGLETON
t_data	*_data(void);
t_mlx	*_mlx(void);

//HAST_LA_VISTA
void	hasta_la_vista_baby(char *str);

//VIDEO
void	video_loop(void);

//VIDEO UTILS
void	my_mlx_pixel_put(int x, int y, int color);
void	reload_image(void);
void	create_window(void);

//HOOK
int		hook(void);

//UTILS PARSING
int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **tab);
char	*skip_space(char *line);
void	skip_space_new(char *str, int *i);
int		is_num(char *line);
int		len_number(char *line);
void	print_struct(void);
void	ft_print_map(void);
void	parse_get_max_y(void);
void	parse_get_max_x(char *line);
void	skip_newline(void);

//PARSING
void	parsing(char **argv);
void	open_map(char **argv);
int		parse_data_map(char *line);
int		parse_select(char *line);
void	parse_map(char **argv);
int		parse_insert_color(char *line, t_color *color);

//CHECK MAP
void	check_map(void);
void	check_line_size(void);
void	check_player_in_map(void);
void	check_char_in_map(void);

//PARSING TEXTURE
int		parse_texture_north(char *line);
int		parse_texture_west(char *line);
int		parse_texture_east(char *line);
int		parse_texture_south(char *line);

//PARSING COLOR
int		parse_color_floor(char *line);
int		parse_color_ceiling(char *line);

#endif
