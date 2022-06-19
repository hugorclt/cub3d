/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tranlate_tex_coor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:47:36 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/19 15:55:06 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_x(void)
{
	t_ray		*ray;
	t_player	*player;

	ray = _ray();
	player = _player();
	if (ray->side == NORTH_SOUTH)
		ray->wall_x = player->pos.y + (ray->wall_dist * ray->dir.y);
	else
		ray->wall_x = player->pos.x + (ray->wall_dist * ray->dir.x);
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_texture_x(void)
{
	t_tex	*tex;
	t_ray	*ray;

	tex = _tex();
	ray = _ray();
	tex->tex_x = (int)(ray->wall_x
			* (double)tex->img[ray->side_hit].width);
	if (ray->side == NORTH_SOUTH && ray->dir.x > 0)
		tex->tex_x = tex->img[tex->side_hit].width - tex->tex_x - 1;
	if (ray->side == WEST_EAST && ray->dir.y < 0)
		tex->tex_x = tex->img[tex->side_hit].width - tex->tex_x - 1;
	tex->tex_x /= 4;
}

void	calculate_step_texture(void)
{
	t_tex	*tex;
	t_rc	*rc;

	tex = _tex();
	rc = _rc();
	tex->step = 1.0
		* tex->img[tex->side_hit].width / rc->wall.line_height;
	tex->step /= 4;
}

void	calculate_texture_coor(void)
{
	t_tex	*tex;
	t_rc	*rc;

	tex = _tex();
	rc = _rc();
	tex->coor = tex->step
		* (rc->wall.pixel_start - WIN_HEIGHT / 2 + rc->wall.line_height / 2);
}

void	translate_texture_coor(void)
{
	init_side_hit_in_texture();
	calculate_wall_x();
	calculate_texture_x();
	calculate_step_texture();
	calculate_texture_coor();
}
