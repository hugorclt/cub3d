/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:49:56 by ajung             #+#    #+#             */
/*   Updated: 2022/06/13 08:37:02 by hrecolet         ###   ########.fr       */
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
	int		i;
	int		j;
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
				player->pos.x = j;
				player->pos.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

static void	init_direction(float dir_x, float dir_y, float plane_x, float plane_y)
{
	t_player	*player;
	t_rc		*rc;

	player = _player();
	rc = _rc();
	player->dir.x = dir_x;
	player->dir.y = dir_y;
	rc->plan.x = plane_x;
	rc->plan.y = plane_y;
}

static void	init_player_direction(void)
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

void	init_player(void)
{
	init_player_position();
	init_player_direction();
}
