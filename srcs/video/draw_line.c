/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:30:33 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/10 11:24:55 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_2_point(t_float pts)
{
	while (pts.y1 < pts.y2)
	{
		my_mlx_pixel_put(pts.x1, pts.y1, 0xFF5733);
		pts.y1++;
	}
}
