/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:20:38 by ajung             #+#    #+#             */
/*   Updated: 2022/06/13 07:55:31 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	init_ray(int pixel)
{
	t_rc		*rc;
	t_player	*player;

	rc = _rc();
	player = _player();
	rc->ray.cam_X = 2 * pixel / (double)WIN_WIDTH - 1;
	rc->ray.dir.x = player->dir.x + rc->plan.x * rc->ray.cam_X;
	rc->ray.dir.y = player->dir.y + rc->plan.y * rc->ray.cam_X;

	if (pixel == 0 || pixel == WIN_WIDTH / 2 || pixel == WIN_WIDTH - 1)
	{
		dprintf(2, "ray dir x = %f // ray dir y = %f\n", rc->ray.dir.x, rc->ray.dir.y);
		dprintf(2, "camera x = %f\n", rc->ray.cam_X);
		dprintf(2, "plan x = %f // plan y = %f\n", rc->plan.x, rc->plan.y);
		dprintf(2, "player dir x = %f // player dir y = %f\n\n", player->dir.x, player->dir.y);
	}
}

void	init_ray_step(void)
{
	t_player	*player;
	t_rc		*rc;

	player = _player();
	rc = _rc();
	player->map_pos.x = (int)player->pos.x;
	player->map_pos.y = (int)player->pos.y;
	// dprintf(2, "ray dir x = %f\n", rc->ray.dir.x);
	/////////
	if (rc->ray.dir.x == 0)
		rc->ray.deltaSideDist.x = 1e30;
	else
		rc->ray.deltaSideDist.x = fabs(1 / rc->ray.dir.x);
	if (rc->ray.dir.y == 0)
		rc->ray.deltaSideDist.y = 1e30;
	else
		rc->ray.deltaSideDist.y = fabs(1 / rc->ray.dir.y);
	//////////
	rc->ray.hit = FALSE;
}

void	init_next_side_dist(void)
{
	t_ray		*ray;
	t_player	*player;

	ray = _ray();
	player = _player();
	//dprintf(2, "delta x = %f // delta y = %f\n", ray->deltaSideDist.x, ray->deltaSideDist.y);
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
			if (player->pos.y < ray->nextSideDist.y)
				ray->side_hit = NORTH;
			else
				ray->side_hit = SOUTH;
			player->map_pos.x += ray->step.x;
			ray->nextSideDist.x += ray->deltaSideDist.x;
		}
		else
		{
			if (player->pos.x < ray->nextSideDist.x)
				ray->side_hit = WEST;
			else
				ray->side_hit = EAST;
			player->map_pos.y += ray->step.y;
			ray->nextSideDist.y += ray->deltaSideDist.y;		
		}
		if (data->map.map[player->map_pos.y][player->map_pos.x] == WALL)
			ray->hit = TRUE;
	}
}

void	calculate_wall_height(int pixel)
{
	t_ray	*ray;
	t_rc	*rc;
	t_wall	*wall;
	
	ray = _ray();
	rc = _rc();
	wall = &(rc->wall);
	if (ray->side_hit == NORTH || ray->side_hit == SOUTH)
		ray->wallDist = (ray->nextSideDist.x - ray->deltaSideDist.x);
	else if (ray->side_hit == EAST || ray->side_hit == WEST)
		ray->wallDist = (ray->nextSideDist.y - ray->deltaSideDist.y);
	///////////////////////////////////////////////////////////////////////////
	wall->lineHeight = (int)(WIN_HEIGHT / ray->wallDist);
	//dprintf(2, "wall distance = %f\n", ray->wallDist);
	// printf("lineheight = %d\n", wall->lineHeight);
	wall->pixelStart = -wall->lineHeight / 2 + WIN_HEIGHT / 2;
	//printf("pixelstart = %d\n", wall->pixelStart);
	if (wall->pixelStart < 0)
		wall->pixelStart = 0;
	wall->pixelEnd = wall->lineHeight / 2 + WIN_HEIGHT / 2;
	if (wall->pixelEnd >= WIN_HEIGHT)
		wall->pixelEnd = WIN_HEIGHT - 1;
	if (pixel == 0 || pixel == WIN_WIDTH / 2 || pixel == WIN_WIDTH - 1)
		printf("start : %d, end : %d\n", wall->pixelStart, wall->pixelEnd);
}

void	raycasting(void)
{
	int		pixel;
	t_rc	*rc;
	
	rc = _rc();
	init_player();
	pixel = 0;
	while (pixel < WIN_WIDTH)
	{
		init_ray(pixel);
		init_ray_step();
		init_next_side_dist();
		find_hit_wall();
		calculate_wall_height(pixel);
		draw_2_point(pixel, rc->wall.pixelStart, rc->wall.pixelEnd);
		pixel ++;
	}
}
