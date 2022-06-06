/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:57:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 18:07:09 by hrecolet         ###   ########.fr       */
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

typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_rgb	f;
	t_rgb	c;
}			t_texture;

typedef struct s_player
{
	int	x;
	int	y;
}			t_player;

typedef struct s_data
{
	t_player	player;
	t_texture	texture;
	int			width;
	int			height;
	char		**map;
}			t_data;

t_data	*_data(void);

/* parsing function */
int		parse_launch(int fd);
int		parse_select_color(char *line, int i);
int		parse_data_map(char *line);
int		parse_select_color(char *line, int i);

/* utils function */
void	free_tab(char **tab);
int		ft_strcmp(char *s1, char *s2);
void	skip_space(char *line);
int		len_number(char *line);
int		is_num(char *line);



#endif
