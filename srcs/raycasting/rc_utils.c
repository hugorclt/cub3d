/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:21:23 by ajung             #+#    #+#             */
/*   Updated: 2022/06/17 16:34:38 by ajung            ###   ########.fr       */
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

void	draw_2_point(int x, int start_pts, int end_pts)
{
	int		i;
	t_data	*data;

	data = _data();
	i = 0;
	while (i < start_pts)
	{
		my_mlx_pixel_put(x, i, create_rgb(data->texture.ceiling.trgb.r,
				data->texture.ceiling.trgb.g, data->texture.ceiling.trgb.b));
		i++;
	}
	while (i < end_pts)
	{
		my_mlx_pixel_put(x, i, get_wall_color());
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(x, i, create_rgb(data->texture.floor.trgb.r,
				data->texture.floor.trgb.g, data->texture.floor.trgb.b));
		i++;
	}
}
