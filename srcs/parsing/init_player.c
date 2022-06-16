/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:49:56 by ajung             #+#    #+#             */
/*   Updated: 2022/06/16 17:06:54 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (SUCCESS);
	return (FAILURE);
}

static void	init_player_position(void)
{
	int			i;
	int			j;
	t_data		*data;
	t_player	*player;

	data = _data();
	player = _player();
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (is_player(data->map.map[i][j]) == SUCCESS)
			{
				player->pos.x = j + 0.5;
				player->pos.y = i + 0.5;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	init_direction(float dir_x, float dir_y, float plan_x, float plan_y)
{
	t_player	*player;
	t_rc		*rc;

	player = _player();
	rc = _rc();
	player->dir.x = dir_x;
	player->dir.y = dir_y;
	rc->plan.x = plan_x;
	rc->plan.y = plan_y;
}

void	init_player_direction(void)
{
	t_data		*data;
	t_player	*player;

	player = _player();
	data = _data();
	if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'N')
		init_direction(0, -1, 0.66, 0);
	else if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'S')
		init_direction(0, 1, 0.66, 0);
	else if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'W')
		init_direction(-1, 0, 0, 0.66);
	else if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'E')
		init_direction(1, 0, 0, 0.66);
}

static void	init_speed(void) //tester les valeurs de rotation
{
	t_player	*player;

	player = _player();
	player->ms = 0.07;
	player->rot_speed = -M_PI /80;
}

void	init_player(void)
{
	init_player_position();
	init_player_direction();
	init_speed();
}
