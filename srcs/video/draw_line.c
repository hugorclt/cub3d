/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:30:33 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/10 15:49:45 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long createRGB(int r, int g, int b)
{   
    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	draw_2_point(t_float pts)
{
	int		i;
	t_data	*data;

	data= _data();
	i = 0;
	while (i < pts.y1)
	{
		my_mlx_pixel_put(pts.x1, i, createRGB(data->texture.ceiling.trgb.r, data->texture.ceiling.trgb.g, data->texture.ceiling.trgb.b));
		i++;
	}
	while (i < pts.y2)
	{
		my_mlx_pixel_put(pts.x1, i, 0xFF5733);
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(pts.x1, i, createRGB(data->texture.floor.trgb.r, data->texture.floor.trgb.g, data->texture.floor.trgb.b));
		i++;
	}
}
