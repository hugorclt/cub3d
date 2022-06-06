/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:57:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 18:40:34 by ajung            ###   ########.fr       */
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
	t_trgb	floor;
	t_trgb	ceiling;
}			t_texture;

typedef struct s_player
{
	int	x;
	int	y;
}			t_player;

typedef	struct	s_map
{
	int			max_x;
	int			max_y;
	char		**map;
}	t_map;

typedef struct s_data
{
	t_player	player;
	t_texture	texture;
	t_map		map;
	
}			t_data;


//SINGLETON
t_data	*_data(void);

//UTILS
int		ft_strcmp(char *s1, char *s2);
void	free_tab(char **tab);
void	skip_space(char *line);
int		is_num(char *line);
int		len_number(char *line);
void	hasta_la_vista_baby(void);





#endif
