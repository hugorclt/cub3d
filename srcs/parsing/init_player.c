/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:49:56 by ajung             #+#    #+#             */
/*   Updated: 2022/06/15 00:10:25 by oryzon           ###   ########.fr       */
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

static void	init_player_direction(void)
{
	t_data		*data;
	t_player	*player;

	data = _data();
	player =_player();
	if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'N')
	{
		player->dir.x = 0;
		player->dir.y = -1; 
	}
	else if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'S')
	{
		player->dir.x = 0;
		player->dir.y = 1;
	}
	else if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'W')
	{
		player->dir.x = -1;
		player->dir.y = 0;
	}
	else if (data->map.map[(int)player->pos.y][(int)player->pos.x] == 'E')
	{
		player->dir.x = 1;
		player->dir.y = 0;
	}
}

static void	init_plan(void)
{
	t_rc	*rc;

	rc = _rc();
	rc->plan.x = 0;
	rc->plan.y = 0.66;
}

static void	init_speed(void) //tester les valeurs de rotation
{
	t_player	*player;

	player = _player();
	player->ms = 1;
	player->rot_speed = 1;
}

void	init_player(void)
{
	init_player_position();
	init_player_direction();
	init_plan();
	init_speed();
}
