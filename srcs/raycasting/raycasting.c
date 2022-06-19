/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:20:38 by ajung             #+#    #+#             */
/*   Updated: 2022/06/19 16:17:01 by oryzon           ###   ########.fr       */
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
		ray->next_side_dist.x = (player->pos.x - player->map_pos.x)
			* ray->delta_side_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->next_side_dist.x = (player->map_pos.x + 1.0 - player->pos.x)
			* ray->delta_side_dist.x;
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
		ray->next_side_dist.y = (player->pos.y - player->map_pos.y)
			* ray->delta_side_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->next_side_dist.y = (player->map_pos.y + 1.0 - player->pos.y)
			* ray->delta_side_dist.y;
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
		translate_texture_coor();
		draw_ceiling_wall_floor(pixel,
			rc->wall.pixel_start, rc->wall.pixel_end);
		pixel ++;
	}
}
