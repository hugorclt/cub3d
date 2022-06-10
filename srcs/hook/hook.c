/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:03:47 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/10 19:58:32 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mouse_hook(int keycode, int x, int y)
{
	t_mlx	*mlx;

	mlx = _mlx();
	(void)keycode;
	(void) mlx;
	(void) x;
	(void) y;
	return (SUCCESS);
}

int	key_hook(int keycode)
{
	t_data	*data;

	data = _data();
	if (keycode == KEY_ESC)
		hasta_la_vista_baby(NULL);
	printf("%d\n", keycode);
	if (keycode == KEY_W)
	{
		if (data->map.map[(int)(data->player.y + data->player.dir_y * MOVE_SPEED)][(int)data->player.x] != '1')
			data->player.y += data->player.dir_y * MOVE_SPEED;
		if (data->map.map[(int)data->player.y][(int)(data->player.x + data->player.dir_x * MOVE_SPEED)] != '1')
			data->player.x += data->player.dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_S)
	{
		if (data->map.map[(int)(data->player.y - data->player.dir_y * MOVE_SPEED)][(int)data->player.x] != '1')
			data->player.y -= data->player.dir_y * MOVE_SPEED;
		if (data->map.map[(int)data->player.y][(int)(data->player.x - data->player.dir_x * MOVE_SPEED)] != '1')
			data->player.x -= data->player.dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_A)
	{
		if (data->map.map[(int)(data->player.y - data->player.dir_x * MOVE_SPEED)][(int)data->player.x] != '1')
			data->player.y -= data->player.dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_D)
	{
		if (data->map.map[(int)(data->player.y + data->player.dir_x * MOVE_SPEED)][(int)data->player.x] != '1')
			data->player.y += data->player.dir_x * MOVE_SPEED;
	}
	else if (keycode == KEY_E)
	{
		data->player.old_dir_x = data->player.dir_x;
		data->player.dir_x = data->player.dir_x * cos(-ROT_SPEED) - data->player.dir_y * sin(-ROT_SPEED);
		data->player.dir_y = data->player.old_dir_x * sin(-ROT_SPEED) + data->player.dir_y * cos(-ROT_SPEED);
		data->player.old_plane_x = data->player.plane_x;
		data->player.plane_x = data->player.plane_x * cos(-ROT_SPEED) - data->player.plane_y * sin(-ROT_SPEED);
		data->player.plane_y = data->player.old_plane_x * sin(-ROT_SPEED) + data->player.plane_y * cos(-ROT_SPEED);
	}
	return (SUCCESS);
}

static int	close_window(void)
{
	hasta_la_vista_baby(NULL);
	return (SUCCESS);
}

int	refresh_image(void)
{
	reload_image();
	return (0);
}

int	hook(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx_hook(mlx->var.win, ON_DESTROY, 0, close_window, NULL);
	mlx_hook(mlx->var.win, ON_KEYDOWN, 1L << 0, key_hook, NULL);
	mlx_mouse_hook(mlx->var.win, mouse_hook, NULL);
	//mlx_loop_hook(mlx->var.mlx, refresh_image, NULL);
	return (SUCCESS);
}
