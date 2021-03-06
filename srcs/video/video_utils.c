/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:04:03 by ajung             #+#    #+#             */
/*   Updated: 2022/06/18 19:59:50 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* void	my_mlx_pixel_put(int x, int y, int color)
{
	char	*dst;
	t_mlx	*mlx;

	mlx = _mlx();
	if (((0 < x) && (x < WIN_WIDTH)) && ((0 < y) && (y < WIN_HEIGHT)))
	{
		dst = mlx->image.addr + (y * mlx->image.width
				+ x * (mlx->image.bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
} */

void	reload_image(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	mlx_destroy_image(mlx->var.mlx, mlx->image.img_ptr);
	mlx->image.img_ptr = mlx_new_image(mlx->var.mlx, 1920, 1080);
	mlx->image.addr = (int *)mlx_get_data_addr(mlx->image.img_ptr,
			&mlx->image.bits_per_pixel, &mlx->image.width,
			&mlx->image.endian);
	mlx_put_image_to_window(mlx->var.mlx, mlx->var.win, mlx->image.img_ptr,
		0, 0);
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
	mlx->image.addr = (int *)mlx_get_data_addr(mlx->image.img_ptr,
			&mlx->image.bits_per_pixel, &mlx->image.width,
			&mlx->image.endian);
}
