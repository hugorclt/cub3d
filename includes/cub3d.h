/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:57:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/18 20:10:58 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define SUCCESS 0
# define FAILURE -1
# define TRUE 0
# define FALSE 1

# ifndef M_PI
#  define M_PI 3.141592653
# endif

# define WIN_WIDTH 1080
# define WIN_HEIGHT 720

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_E 101
# define KEY_Q 113

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

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

# define NORTH_SOUTH 0
# define WEST_EAST 1

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
	int		*addr;
	int		bits_per_pixel;
	int		width;
	int		height;
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

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_player
{
	t_vector	pos;
	t_pos		map_pos;
	t_vector	dir;
	double		ms;
	double		rot_speed;

}	t_player;

typedef struct s_ray
{
	t_vector	dir;
	t_vector	delta_side_dist;
	t_vector	next_side_dist;
	t_pos		step;
	double		cam_x;
	double		wall_dist;
	double		wall_x;
	int			hit;
	int			side_hit;
	int			side;
}	t_ray;

typedef struct s_wall
{
	int	line_height;
	int	pixel_start;
	int	pixel_end;
}	t_wall;

typedef struct s_rc
{
	t_player	player;
	t_vector	plan;
	t_ray		ray;
	t_wall		wall;
}	t_rc;

typedef struct s_texture //faire une struct floor et ceiling si j'ai la deter
{
	int		tex_x;
	int		tex_y;
	char	*path[4];
	t_color	floor;
	t_color	ceiling;
	int		floor_filled;
	int		ceiling_filled;
	t_image	img[4];
	int		side_hit;
	double	step;
	double	coor;
	int		color;
}	t_tex;

typedef struct s_data
{
	t_rc		rc;
	t_tex	tex;
	t_map		map;
	t_mlx		mlx;
	t_ray		ray;
}	t_data;

//SINGLETON
t_data		*_data(void);
t_mlx		*_mlx(void);
t_rc		*_rc(void);
t_player	*_player(void);
t_ray		*_ray(void);
t_tex		*_tex(void);
//RAYCASTING
void		raycasting(void);
void		init_ray(int pixel);
void		init_ray_step(void);
void		init_next_side_dist(void);
void		calculate_wall_height(void);
void		find_hit_wall(void);
void		what_side_was_hit(void);


//TEXTURE 
void	init_texture(void);
void	translate_texture_coor(void);

//HAST_LA_VISTA
void		hasta_la_vista_baby(char *str);

//DRAW_LINE
void		draw_2_point(int x, int start_pts, int end_pts);

//VIDEO
void		video_loop(void);

//VIDEO UTILS
void		my_mlx_pixel_put(int x, int y, int color);
void		reload_image(void);
void		create_window(void);

//HOOK
int			hook(void);
void		rotate_left(void);
void		rotate_right(void);
void		go_forward(void);
void		go_back(void);
void		go_left(void);
void		go_right(void);

//UTILS PARSING
int			ft_strcmp(char *s1, char *s2);
void		free_tab(char **tab);
char		*skip_space(char *line);
void		skip_space_new(char *str, int *i);
int			is_num(char *line);
int			len_number(char *line);
void		print_struct(void);
void		ft_print_map(void);
void		parse_get_max_y(void);
void		parse_get_max_x(char *line);
void		skip_newline(void);
int			is_player(char c);

//PARSING
void		parsing(char **argv);
void		open_map(char **argv);
int			parse_data_map(char *line);
int			parse_select(char *line);
void		parse_map(char **argv);
int			parse_insert_color(char *line, t_color *color);
void		init_player(void);

//CHECK MAP
void		check_map(void);
void		check_line_size(void);
void		check_player_in_map(void);
void		check_char_in_map(void);

//PARSING TEXTURE
int			parse_texture_north(char *line);
int			parse_texture_west(char *line);
int			parse_texture_east(char *line);
int			parse_texture_south(char *line);

//PARSING COLOR
int			parse_color_floor(char *line);
int			parse_color_ceiling(char *line);

//PLAYER
void		init_player(void);

#endif
