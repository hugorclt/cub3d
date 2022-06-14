/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:09:19 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/15 00:31:21 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(void)
{
	double		old_dir_x;
	double		old_plan_x;
	t_player	*player;
	t_rc		*rc;

	player = _player();
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(-player->rot_speed)
		- player->dir.y * sin(-player->rot_speed);
	player->dir.y = old_dir_x * sin(-player->rot_speed)
		+ player->dir.y * cos(-player->rot_speed);
	rc = _rc();
	old_plan_x = rc->plan.x;
	rc->plan.x = rc->plan.x * cos(-player->rot_speed)
		- rc->plan.y * sin(-player->rot_speed);
	rc->plan.y = old_plan_x * sin(-player->rot_speed)
		+ rc->plan.y * cos(-player->rot_speed);
}

void	rotate_left(void)
{
	double		old_dir_x;
	double		old_plan_x;
	t_player	*player;
	t_rc		*rc;

	player = _player();
	old_dir_x = player->dir.x;
	player->dir.x = player->dir.x * cos(player->rot_speed)
		- player->dir.y * sin(player->rot_speed);
	player->dir.y = old_dir_x * sin(player->rot_speed)
		+ player->dir.y * cos(player->rot_speed);
	rc = _rc();
	old_plan_x = rc->plan.x;
	rc->plan.x = rc->plan.x * cos(player->rot_speed)
		- rc->plan.y * sin(player->rot_speed);
	rc->plan.y = old_plan_x * sin(player->rot_speed)
		+ rc->plan.y * cos(player->rot_speed);
}
