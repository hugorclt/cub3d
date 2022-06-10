/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:21:23 by ajung             #+#    #+#             */
/*   Updated: 2022/06/10 19:24:00 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	draw_2_point(int x, int start_pts, int end_pts)
{
	int		i;
	t_data	*data;

	data= _data();
	i = 0;
	while (i < start_pts)
	{
		my_mlx_pixel_put(x, i, createRGB(data->texture.ceiling.trgb.r,
			data->texture.ceiling.trgb.g, data->texture.ceiling.trgb.b));
		i++;
	}
	while (i < end_pts)
	{
		my_mlx_pixel_put(x, i, 0xFF5733);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(x, i, createRGB(data->texture.floor.trgb.r,
			data->texture.floor.trgb.g, data->texture.floor.trgb.b));
		i++;
	}
}
