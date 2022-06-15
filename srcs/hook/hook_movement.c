/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:06:00 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/15 22:17:35 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	wall_check(double x, double y)
{
	t_data	*data;

	data = _data();
	if (data->map.map[(int) y][(int) x] == WALL)
		return (FAILURE);
	else
		return (SUCCESS);
}

void	go_forward(void)
{
	t_player	*player;
	double		futur_pos_x;
	double		futur_pos_y;

	player = _player();
	futur_pos_x = player->pos.x + player->dir.x * player->ms;
	futur_pos_y = player->pos.y + player->dir.y * player->ms;
	if (wall_check(futur_pos_x, futur_pos_y) == FAILURE)
		return ;
	player->pos.x = futur_pos_x;
	player->pos.y = futur_pos_y;
}

void	go_back(void)
{
	t_player	*player;
	double		futur_pos_x;
	double		futur_pos_y;

	player = _player();
	futur_pos_x = player->pos.x - player->dir.x * player->ms;
	futur_pos_y = player->pos.y - player->dir.y * player->ms;
	if (wall_check(futur_pos_x, futur_pos_y) == FAILURE)
		return ;
	player->pos.x = futur_pos_x;
	player->pos.y = futur_pos_y;
}

void	go_left(void) //peut etre inverser le + et -
{
	t_player	*player;
	double		futur_pos_x;
	double		futur_pos_y;

	player = _player();
	futur_pos_x = player->pos.x + player->dir.x * player->ms;
	futur_pos_y = player->pos.y - player->dir.y * player->ms;
	if (wall_check(futur_pos_x, futur_pos_y) == FAILURE)
		return ;
	player->pos.x = futur_pos_x;
	player->pos.y = futur_pos_y;
}

void	go_right(void) //peut etre inverser le + et -
{
	t_player	*player;
	double		futur_pos_x;
	double		futur_pos_y;

	player = _player();
	futur_pos_x = player->pos.x - player->dir.x * player->ms;
	futur_pos_y = player->pos.y + player->dir.y * player->ms;
	if (wall_check(futur_pos_x, futur_pos_y) == FAILURE)
		return ;
	player->pos.x = futur_pos_x;
	player->pos.y = futur_pos_y;
}
