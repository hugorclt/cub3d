/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:04:03 by ajung             #+#    #+#             */
/*   Updated: 2022/06/10 11:32:15 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;
	t_mlx	*mlx;

	mlx = _mlx();
	if (((0 < x) && (x < WIN_WIDTH)) && ((0 < y) && (y < WIN_HEIGHT)))
	{
		dst = mlx->image.addr + (y * mlx->image.line_len
				+ x * (mlx->image.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	reload_image(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx_destroy_image(mlx->var.mlx, mlx->image.img_ptr);
	mlx->image.img_ptr = mlx_new_image(mlx->var.mlx, 1920, 1080);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img_ptr,
			&mlx->image.bits_per_pixel, &mlx->image.line_len,
			&mlx->image.endian);
	init_ray();
	mlx_put_image_to_window(mlx->var.mlx, mlx->var.win, mlx->image.img_ptr, 0, 0);
	//put image to window
}

void	create_window(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx->var.mlx = mlx_init();
	if (!mlx->var.mlx)
		hasta_la_vista_baby("mlx fail");
	mlx->var.win = mlx_new_window(mlx->var.mlx, WIN_WIDTH, WIN_HEIGHT,
			"el raycasting de la mama");
	mlx->image.img_ptr = mlx_new_image(mlx->var.mlx, WIN_WIDTH, WIN_HEIGHT);
	mlx->image.addr = mlx_get_data_addr(mlx->image.img_ptr,
			&mlx->image.bits_per_pixel, &mlx->image.line_len,
			&mlx->image.endian);
}
