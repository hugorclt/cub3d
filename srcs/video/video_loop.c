/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:40:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 19:13:34 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* 	all->vars.win = mlx_new_window(all->vars.mlx, 1920, 1080, "My window");
	all->image_data.img_ptr = mlx_new_image(all->vars.mlx, 1920, 1080);
	all->image_data.addr = mlx_get_data_addr(all->image_data.img_ptr,
			&all->image_data.bits_per_pixel, &all->image_data.line_length,
			&all->image_data.endian);
	return (0); */


void	reload_image(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx_destroy_image(mlx->var.mlx, mlx->image.img_ptr);
	mlx->image.img_ptr = mlx_new_image(mlx->var.mlx, 1920, 1080);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img_ptr,
			&mlx->image.bits_per_pixel, &mlx->image.line_len,
			&mlx->image.endian);
	
	//put_image_text(mlx);
	//afficher image
}

void	create_window(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx->var.mlx = mlx_init();
	if (!mlx->var.mlx)
		hasta_la_vista_baby("mlx fail");
	mlx->var.win = mlx_new_window(mlx->var.mlx, WIN_WIDTH, WIN_HEIGHT, "el raycasting de la mama");
	mlx->image.img_ptr = mlx_new_image(mlx->var.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img_ptr,
			&mlx->image.bits_per_pixel, &mlx->image.line_len,
			&mlx->image.endian);
}

void	video_loop(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	create_window();
	mlx_loop(mlx->var.mlx);
}
