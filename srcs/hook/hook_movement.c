/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_movement.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:06:00 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/16 16:21:11 by hrecolet         ###   ########.fr       */
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

void	go_left(void) //tester la formule en comms
{
	t_player	*player;
	t_rc		*rc;
	double		futur_pos_x;
	double		futur_pos_y;

	player = _player();
	rc = _rc();
	// futur_pos_x = player->pos.x + player->dir.x * player->ms;
	// futur_pos_y = player->pos.y - player->dir.y * player->ms;
	futur_pos_x = player->pos.x - rc->plan.x * player->ms;
	futur_pos_y = player->pos.y - rc->plan.y * player->ms;
	if (wall_check(futur_pos_x, futur_pos_y) == FAILURE)
		return ;
	player->pos.x = futur_pos_x;
	player->pos.y = futur_pos_y;
}

void	go_right(void) //tester la formule en comms
{
	t_player	*player;
	t_rc		*rc;
	double		futur_pos_x;
	double		futur_pos_y;

	rc = _rc();
	player = _player();
	// futur_pos_x = player->pos.x - player->dir.x * player->ms;
	// futur_pos_y = player->pos.y + player->dir.y * player->ms;
	futur_pos_x = player->pos.x + rc->plan.x * player->ms;
	futur_pos_y = player->pos.y + rc->plan.y * player->ms;
	if (wall_check(futur_pos_x, futur_pos_y) == FAILURE)
		return ;
	player->pos.x = futur_pos_x;
	player->pos.y = futur_pos_y;
}
