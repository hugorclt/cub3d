/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:21:23 by ajung             #+#    #+#             */
/*   Updated: 2022/06/18 20:18:27 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

/*
NORTH = Orange
South = Green
WEST = purple
EAST = yellow
BUG= white
*/

int	get_wall_color(void)
{
	t_rc	*rc;

	rc = _rc();
	if (rc->ray.side_hit == NORTH)
		return (0xFF5733);
	else if (rc->ray.side_hit == SOUTH)
		return (0xB0F2B6);
	else if (rc->ray.side_hit == WEST)
		return (0x7F00FF);
	else if (rc->ray.side_hit == EAST)
		return (0xFAFD0F);
	else
		return (0xFFFFFF);
}

void	draw_no_pixel_put(int x, int i, int color)
{
	t_mlx	*mlx;
	
	mlx = _mlx();
	mlx->image.addr[i * mlx->image.width / 4 + x] = color;
}


void	calculate_texture_y(void)
{
	t_tex	*tex;

	tex = _tex();
	tex->tex_y = (int)(tex->coor) & (tex->img[tex->side_hit].height - 1); //essayer sans
	
}

void	increase_texture_step(void)
{
	t_tex	*tex;

	tex = _tex();
	tex->coor += tex->step;
}

int	pick_color(void)
{
    t_tex	*tex;

    tex = _tex();
    tex->color = tex->img[tex->side_hit].addr[tex->tex_y * tex->img[tex->side_hit].width / 4 + tex->tex_x];
	return (tex->color);
}

/* void	draw_2_point(int x, int start_pts, int end_pts)
{
	int		i;
	t_data	*data;

	data = _data();
	i = 0;
	while (i < start_pts)
	{
		my_mlx_pixel_put(x, i, create_rgb(data->tex.ceiling.trgb.r,
				data->tex.ceiling.trgb.g, data->tex.ceiling.trgb.b));
		i++;
	}
	while (i < end_pts)
	{
		calculate_texture_y();
		my_mlx_pixel_put(x, i, pick_color());
		increase_texture_step();
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(x, i, create_rgb(data->tex.floor.trgb.r,
				data->tex.floor.trgb.g, data->tex.floor.trgb.b));
		i++;
	}
} */

void    draw_2_point(int x, int start_pts, int end_pts)
{
    int            i;
    t_data        *data;
    t_mlx        *mlx;
    t_tex		*tex;

    data = _data();
    mlx    = _mlx();
    tex = _tex();
    i = 0;
    while (i < start_pts)
    {
        mlx->image.addr[i * mlx->image.width / 4 + x] = create_rgb(data->tex.ceiling.trgb.r,
                data->tex.ceiling.trgb.g, data->tex.ceiling.trgb.b);
        i++;
    }
    while (i < end_pts)
    {
        calculate_texture_y();
        pick_color();
        mlx->image.addr[i * mlx->image.width / 4 + x] = tex->color;
		increase_texture_step();
        i++;
    }
    while (i < WIN_HEIGHT)
    {
        mlx->image.addr[i * mlx->image.width / 4 + x] = create_rgb(data->tex.floor.trgb.r,
                data->tex.floor.trgb.g, data->tex.floor.trgb.b);
        i++;
    }
}
