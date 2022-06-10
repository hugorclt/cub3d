/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:40:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/10 11:27:53 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray_direction(int i)
{
	t_data	*data;

	data = _data();
	data->ray.camera_x = 2 * i / (float)WIN_WIDTH - 1;
	data->ray.dir_x = data->player.dir_x + data->player.plane_x * data->ray.camera_x;
	data->ray.dir_y = data->player.dir_y + data->player.plane_y * data->ray.camera_x;
	data->ray.map_x = (int)data->player.x;
	data->ray.map_y = (int)data->player.y;
}

void	init_distance_ray_player(void)
{
	t_data	*data;

	data = _data();
	if (data->ray.dir_x == 0)
		data->ray.delta_dist_x = 1e30;
	else
		data->ray.delta_dist_x = fabs(1 / data->ray.dir_x);
	if (data->ray.dir_y == 0)
		data->ray.delta_dist_y = 1e30;
	else
		data->ray.delta_dist_y = fabs(1 / data->ray.dir_y);
	data->ray.hit = 0;
}

void	calculate_side_dist(void)
{
	t_data	*data;

	data = _data();
	if (data->ray.dir_x < 0)
	{
		data->ray.step_x = -1;
		data->ray.side_dist_x = (data->player.x - data->ray.map_x) * data->ray.delta_dist_x;
	}
	else
	{
		data->ray.step_x = 1;
		data->ray.side_dist_x = (data->ray.map_x + 1.0 - data->player.x) * data->ray.delta_dist_x;
	}
	if (data->ray.dir_y < 0)
	{
		data->ray.step_y = -1;
		data->ray.side_dist_y = (data->player.y - data->ray.map_y) * data->ray.delta_dist_y;
	}
	else
	{
		data->ray.step_y = 1;
		data->ray.side_dist_y = (data->ray.map_y + 1.0 - data->player.y) * data->ray.delta_dist_y;
	}
}

void	dda_casting(void) //Digital differential analysis algorithm
{
	t_data	*data;

	data = _data();
	while (data->ray.hit == 0)
	{
		if (data->ray.side_dist_x < data->ray.side_dist_y)
		{
			data->ray.side_dist_x += data->ray.delta_dist_x;
			data->ray.map_x += data->ray.step_x;
			data->ray.side = 0;
		}
		else
		{
			data->ray.side_dist_y += data->ray.delta_dist_y;
			data->ray.map_y += data->ray.step_y;
			data->ray.side = 1;
		}
		if (data->map.map[data->ray.map_y][data->ray.map_x] == '1')
				data->ray.hit = 1;
	}
}

void	print_pts(t_float *nb)
{
	printf("x1: %f", nb->x1);
	printf("y1: %f", nb->y1);
	printf("x2: %f", nb->x2);
	printf("y2: %f\n", nb->y2);
}

void	calculate_ray_points(int i)
{
	t_data	*data;

	data = _data();
	if (data->ray.side == 0)
		data->ray.wall_dist = data->ray.side_dist_x - data->ray.delta_dist_x;
	else
		data->ray.wall_dist = data->ray.side_dist_y - data->ray.delta_dist_y;
	data->ray.line_height = (int)(WIN_HEIGHT / data->ray.wall_dist);
	data->ray.draw_start = -data->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_start < 0)
		data->ray.draw_start = 0;
	data->ray.draw_end = data->ray.line_height / 2 + WIN_HEIGHT / 2;
	if (data->ray.draw_end >= WIN_HEIGHT)
		data->ray.draw_end = WIN_HEIGHT - 1;
	data->ray.pts.x1 = i;
	data->ray.pts.x2 = i;
	data->ray.pts.y1 = data->ray.draw_start;
	data->ray.pts.y2 = data->ray.draw_end;
	print_pts(&data->ray.pts);
}

void	init_ray(void)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	while (i < WIN_WIDTH)
	{
		init_ray_direction(i);
		init_distance_ray_player();
		calculate_side_dist();
		dda_casting();
		calculate_ray_points(i);
		draw_2_point(data->ray.pts);
		i++;
	}
}

void	video_loop(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	create_window();
	init_ray();
	mlx_put_image_to_window(mlx->var.mlx, mlx->var.win, mlx->image.img_ptr, 0, 0);
	hook();
	mlx_loop(mlx->var.mlx);
}
