/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 15:42:51 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/19 15:58:36 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_texture_y(void)
{
	t_tex	*tex;

	tex = _tex();
	tex->tex_y = (int)(tex->coor) & (tex->img[tex->side_hit].height - 1);
}

void	increase_texture_step(void)
{
	t_tex	*tex;

	tex = _tex();
	tex->coor += tex->step;
}

int	pick_color_img_tex(void)
{
	t_tex	*tex;

	tex = _tex();
	tex->color = tex->img[tex->side_hit].addr[
		tex->tex_y * tex->img[tex->side_hit].width / 4 + tex->tex_x];
	return (tex->color);
}

void	init_side_hit_in_texture(void)
{
	t_ray		*ray;
	t_tex		*texture;

	ray = _ray();
	texture = _tex();
	texture->side_hit = ray->side_hit;
}
