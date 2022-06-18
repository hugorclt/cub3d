/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:03:47 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/18 16:34:00 by hrecolet         ###   ########.fr       */
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
	(void) keycode;
	return (SUCCESS);
}

int	key_hook(int keycode)
{
	t_data	*data;

	data = _data();
	(void)data;
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		hasta_la_vista_baby(NULL);
	else if (keycode == KEY_W_MAC)
		go_forward();
	else if (keycode == KEY_S_MAC)
		go_back();
	else if (keycode == KEY_A_MAC)
		go_left();
	else if (keycode == KEY_D_MAC)
		go_right();
	else if (keycode == KEY_LEFT_MAC)
		rotate_left();
	else if (keycode == KEY_RIGHT_MAC)
		rotate_right();
	return (SUCCESS);
}

static int	close_window(void)
{
	hasta_la_vista_baby(NULL);
	return (SUCCESS);
}

int	loop_function(void)
{
	t_mlx	*mlx;

	reload_image();
	raycasting();
	mlx = _mlx();
	mlx_put_image_to_window(mlx->var.mlx, mlx->var.win,
		mlx->image.img_ptr, 0, 0);
	return (SUCCESS);
}

int	hook(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx_hook(mlx->var.win, ON_DESTROY, 0, close_window, NULL);
	mlx_hook(mlx->var.win, ON_KEYDOWN, 1L << 0, key_hook, NULL);
	mlx_mouse_hook(mlx->var.win, mouse_hook, NULL);
	mlx_loop_hook(mlx->var.mlx, &loop_function, NULL);
	return (SUCCESS);
}
