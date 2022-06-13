/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:40:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/13 07:51:43 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	video_loop(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	create_window();
	raycasting();
	mlx_put_image_to_window(mlx->var.mlx, mlx->var.win, mlx->image.img_ptr, 0, 0);
	hook();
	mlx_loop(mlx->var.mlx);
}
