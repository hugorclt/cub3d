/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:20:38 by ajung             #+#    #+#             */
/*   Updated: 2022/06/16 20:00:07 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_next_side_dist_x(void)
{
	t_ray		*ray;
	t_player	*player;

	ray = _ray();
	player = _player();
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->nextSideDist.x = (player->pos.x - player->map_pos.x)
			* ray->deltaSideDist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->nextSideDist.x = (player->map_pos.x + 1.0 - player->pos.x)
			* ray->deltaSideDist.x;
	}
}

static void	init_next_side_dist_y(void)
{
	t_ray		*ray;
	t_player	*player;

	ray = _ray();
	player = _player();
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->nextSideDist.y = (player->pos.y - player->map_pos.y)
			* ray->deltaSideDist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->nextSideDist.y = (player->map_pos.y + 1.0 - player->pos.y)
			* ray->deltaSideDist.y;
	}
}

void	init_next_side_dist(void)
{
	init_next_side_dist_x();
	init_next_side_dist_y();
}

void	raycasting(void)
{
	int		pixel;
	t_rc	*rc;

	rc = _rc();
	pixel = 0;
	while (pixel < WIN_WIDTH)
	{
		init_ray(pixel);
		init_ray_step();
		init_next_side_dist();
		find_hit_wall();
		what_side_was_hit();
		calculate_wall_height();
		draw_2_point(pixel, rc->wall.pixelStart, rc->wall.pixelEnd);
		pixel ++;
	}
}
