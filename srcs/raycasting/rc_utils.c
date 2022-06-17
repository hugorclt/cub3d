/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:21:23 by ajung             #+#    #+#             */
/*   Updated: 2022/06/17 11:15:56 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned long	createRGB(int r, int g, int b)
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


void	get_wall_texture(int x, int y, double texpos, int texX)
{
	t_rc	*rc;
	t_data	*data;
	t_mlx	*mlx;
	int		texY;

	rc = _rc();
	data = _data();
	mlx = _mlx();
	texY = (int)texpos & (data->teximg[0].height - 1);
	if (rc->ray.side_hit == NORTH)
		mlx->image.addr[y * mlx->image.line_len / 4 + x] = data->teximg[0].addr[texY * data->teximg[0].line_len / 4 + texX];
	else if (rc->ray.side_hit == SOUTH)
		mlx->image.addr[y * mlx->image.line_len / 4 + x] = data->teximg[3].addr[texY * data->teximg[3].line_len / 4 + texX];
	else if (rc->ray.side_hit == WEST)
		mlx->image.addr[y * mlx->image.line_len / 4 + x] = data->teximg[1].addr[texY * data->teximg[1].line_len / 4 + texX];
	else if (rc->ray.side_hit == EAST)
		mlx->image.addr[y * mlx->image.line_len / 4 + x] = data->teximg[2].addr[texY * data->teximg[2].line_len / 4 + texX];
}

//data.addr[y * recup->data.line_length / 4 + x] = texture[0].addr[texy * texture[0].line_length / 4 + texx];
void	draw_2_point(int x, int start_pts, int end_pts)
{
	int		i;
	t_data	*data;
	double	texpos;
	t_rc	*rc;
	double	step;
	double	wallX;
	int			texX;
	t_player	*player;

	rc = _rc();
	player = _player();
	data = _data();
	if (rc->ray.side == 0)
		wallX = player->pos.x + rc->ray.wallDist * rc->ray.dir.y;
	else
		wallX = player->pos.y + rc->ray.wallDist * rc->ray.dir.x;
	wallX -= floor(wallX);
	texX = (int)(wallX * (double)data->teximg[0].width);
	if (rc->ray.side == 0 && rc->ray.dir.x > 0)
		texX = data->teximg[0].width - texX - 1;
	if (rc->ray.side == 1 && rc->ray.dir.y < 0)
		texX = data->teximg[0].width - texX - 1;
	i = 0;
	step = 1.0 * (data->teximg[0].height / rc->wall.lineHeight);
	texpos = (rc->wall.pixelStart - WIN_HEIGHT / 2 + rc->wall.lineHeight / 2) * step;
	while (i < start_pts)
	{
		my_mlx_pixel_put(x, i, createRGB(data->texture.ceiling.trgb.r,
				data->texture.ceiling.trgb.g, data->texture.ceiling.trgb.b));
		i++;
	}
	while (i < end_pts)
	{
		get_wall_texture(x, i, texpos, texX);
		texpos += step;
		//my_mlx_pixel_put(x, i, get_wall_color());
		i++;
	}
	while (i < WIN_HEIGHT)
	{
		my_mlx_pixel_put(x, i, createRGB(data->texture.floor.trgb.r,
				data->texture.floor.trgb.g, data->texture.floor.trgb.b));
		i++;
	}
}
