/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 23:03:47 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/13 07:44:09 by hrecolet         ###   ########.fr       */
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
	if (keycode == KEY_ESC)
		hasta_la_vista_baby(NULL);
	return (SUCCESS);
}

static int	close_window(void)
{
	hasta_la_vista_baby(NULL);
	return (SUCCESS);
}
/* 
int    loop_function(void)
{
	t_data	*data;

	data = _data();
	
    //update de tous les parametres necessaires aux calculs du raycasting
    if (data->player->is_jumping == 0)
        update_movements(data);
    update_stamina(data);
    if (data->player->is_jumping)
        update_jump(data);
    data->player->ms = calcul_movespeed(data);
    update_player(data);


    create_big(data);  //render de frame
    return (SUCCESS);
}
 */
int	hook(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx_hook(mlx->var.win, ON_DESTROY, 0, close_window, NULL);
	mlx_hook(mlx->var.win, ON_KEYDOWN, 1L << 0, key_hook, NULL);
	mlx_mouse_hook(mlx->var.win, mouse_hook, NULL);
	//mlx_loop_hook(mlx->var.mlx, &loop_function, NULL);
	return (SUCCESS);
}
