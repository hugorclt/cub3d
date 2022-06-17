/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 19:52:12 by ajung             #+#    #+#             */
/*   Updated: 2022/06/16 20:00:01 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"cub3d.h"

void	init_ray(int pixel)
{
	t_rc		*rc;
	t_player	*player;

	rc = _rc();
	player = _player();
	rc->ray.cam_X = 2 * pixel / (double)WIN_WIDTH - 1;
	rc->ray.dir.x = player->dir.x + rc->plan.x * rc->ray.cam_X;
	rc->ray.dir.y = player->dir.y + rc->plan.y * rc->ray.cam_X;
}

void	init_ray_step(void)
{
	t_player	*player;
	t_rc		*rc;

	player = _player();
	rc = _rc();
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
	if (rc->ray.dir.x == 0)
		rc->ray.deltaSideDist.x = 1e30;
	else
		rc->ray.deltaSideDist.x = fabs(1 / rc->ray.dir.x);
	if (rc->ray.dir.y == 0)
		rc->ray.deltaSideDist.y = 1e30;
	else
		rc->ray.deltaSideDist.y = fabs(1 / rc->ray.dir.y);
	rc->ray.hit = FALSE;
}

void	what_side_was_hit(void)
{
	t_ray		*ray;

	ray = _ray();
	if (ray->hit != TRUE)
		return ;
	if (ray->side == WEST_EAST)
	{
		if (ray->dir.y > 0)
			ray->side_hit = NORTH;
		else
			ray->side_hit = SOUTH;
	}
	else
	{
		if (ray->dir.x > 0)
			ray->side_hit = WEST;
		else
			ray->side_hit = EAST;
	}
}

void	find_hit_wall(void)
{
	t_ray		*ray;
	t_player	*player;
	t_data		*data;

	ray = _ray();
	player = _player();
	data = _data();
	while (ray->hit == FALSE)
	{
		if (ray->nextSideDist.x < ray->nextSideDist.y)
		{
			ray->side = NORTH_SOUTH;
			player->map_pos.x += ray->step.x;
			ray->nextSideDist.x += ray->deltaSideDist.x;
		}
		else
		{
			ray->side = WEST_EAST;
			player->map_pos.y += ray->step.y;
			ray->nextSideDist.y += ray->deltaSideDist.y;
		}
		if (data->map.map[player->map_pos.y][player->map_pos.x] == WALL)
			ray->hit = TRUE;
	}
}

void	calculate_wall_height(void)
{
	t_ray	*ray;
	t_rc	*rc;
	t_wall	*wall;

	ray = _ray();
	rc = _rc();
	wall = &(rc->wall);
	if (ray->side == NORTH_SOUTH)
		ray->wallDist = (ray->nextSideDist.x - ray->deltaSideDist.x);
	else
		ray->wallDist = (ray->nextSideDist.y - ray->deltaSideDist.y);
	wall->lineHeight = (int)(WIN_HEIGHT / ray->wallDist);
	wall->pixelStart = -wall->lineHeight / 2 + WIN_HEIGHT / 2;
	if (wall->pixelStart < 0)
		wall->pixelStart = 0;
	wall->pixelEnd = wall->lineHeight / 2 + WIN_HEIGHT / 2;
	if (wall->pixelEnd >= WIN_HEIGHT)
		wall->pixelEnd = WIN_HEIGHT - 1;
}