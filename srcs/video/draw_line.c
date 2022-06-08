/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:30:33 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/08 12:13:38 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_writeline_x(t_draw *draw)
{
	while (draw->x < draw->xe)
	{
		draw->x++;
		if (draw->px < 0)
			draw->px = draw->px + 2 * draw->dy1;
		else
		{
			if ((draw->dx < 0 && draw->dy < 0) || (draw->dx > 0 && draw->dy > 0))
				draw->y++;
			else
				draw->y--;
			draw->px = draw->px + 2 * (draw->dy1 - draw->dx1);
		}
		my_mlx_pixel_put(draw->x, draw->y, 0x00FF0000);
	}
}

static void	ft_writeline_y(t_draw *draw)
{
	while (draw->y < draw->ye)
	{
		draw->y++;
		if (draw->py <= 0)
			draw->py = draw->py + 2 * draw->dx1;
		else
		{
			if ((draw->dx < 0 && draw->dy < 0) || (draw->dx > 0 && draw->dy > 0))
				draw->x++;
			else
				draw->x--;
			draw->py = draw->py + 2 * (draw->dx1 - draw->dy1);
		}
		my_mlx_pixel_put(draw->x, draw->y, 0x00FF0000);
	}
}

static void	ft_draw_v(t_float pts, t_draw *draw)
{
	if (draw->dy >= 0)
	{
		draw->x = pts.x1;
		draw->y = pts.y1;
		draw->xe = pts.y2;
	}
	else
	{
		draw->x = pts.x2;
		draw->y = pts.y2;
		draw->xe = pts.y1;
	}
	my_mlx_pixel_put(draw->x, draw->y, 0x00FF0000);
	ft_writeline_y(draw);
}

static void	ft_draw_h(t_float pts, t_draw *draw)
{
	if (draw->dx >= 0)
	{
		draw->x = pts.x1;
		draw->y = pts.y1;
		draw->xe = pts.x2;
	}
	else
	{
		draw->x = pts.x2;
		draw->y = pts.y2;
		draw->xe = pts.x1;
	}
	my_mlx_pixel_put(draw->x, draw->y, 0x00FF0000);
	ft_writeline_x(draw);
}


void	draw_2_point(t_float pts)
{
	t_draw draw;

	draw.dx = pts.x2 - pts.x1;
	draw.dy = pts.y2 - pts.y1;
	draw.dx1 = fabs(draw.dx);
	draw.dy1 = fabs(draw.dy);
	draw.px = 2 * draw.dy1 - draw.dx1;
	draw.py = 2 * draw.dx1 - draw.dy1;
	if (draw.dy1 <= draw.dx1)
		ft_draw_h(pts, &draw);
	else
		ft_draw_v(pts, &draw);
}
