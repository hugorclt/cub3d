/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:03:47 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/10 16:18:43 by hrecolet         ###   ########.fr       */
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
	if (keycode == KEY_W)
	{
		if (data->map.map[(int)(data->player.y + data->player.dir_y * MOVE_SPEED)][(int)data->player.x] != '1')
			data->player.y += data->player.dir_y * 0.1;
		else
			printf("je rentre la \n");
		if (data->map.map[(int)data->player.y][(int)(data->player.x + data->player.dir_x * MOVE_SPEED)] != '1')
			data->player.x += data->player.dir_x * 0.1;
		else
			printf("je rentre ici \n");
	}
	else if (keycode == KEY_S)
	{
		if (data->map.map[(int)(data->player.y + data->player.dir_y - MOVE_SPEED)][(int)data->player.x] != '1')
			data->player.y -= data->player.dir_y * 0.1;
		if (data->map.map[(int)data->player.y][(int)(data->player.x - data->player.dir_x * MOVE_SPEED)] != '1')
			data->player.x -= data->player.dir_x * 0.1;
	}
	//else if (keycode == KEY_A)
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
	mlx_loop_hook(mlx->var.mlx, refresh_image, NULL);
	return (SUCCESS);
}
