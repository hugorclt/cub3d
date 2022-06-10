/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:40:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/10 19:34:56 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	video_loop(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	create_window();
	raycasting();
	mlx_put_image_to_window(mlx->var.mlx, mlx->var.win, mlx->image.addr, 0, 0);
	hook();
	mlx_loop(mlx->var.mlx);
}
