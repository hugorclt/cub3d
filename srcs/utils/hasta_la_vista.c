/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasta_la_vista.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:59:14 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/08 02:03:01 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hasta_la_vista_2(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	if (mlx->var.mlx && mlx->var.win)
		mlx_destroy_window(mlx->var.mlx, mlx->var.win);
	if (mlx->var.mlx && mlx->image.img_ptr)
		mlx_destroy_image(mlx->var.mlx, mlx->image.img_ptr);
	if (mlx->var.mlx)
		mlx_destroy_display(mlx->var.mlx);
	free(mlx->var.mlx);
}

void	hasta_la_vista_baby(char *str)
{
	t_data	*data;

	data = _data();
	if (str)
		printf("Error: %s\n", str);
	free(data->texture.north);
	free(data->texture.south);
	free(data->texture.east);
	free(data->texture.west);
	free(data->map.line);
	if (data->map.map)
		free_tab(data->map.map);
	if (data->map.fd > 0)
		close(data->map.fd);
	hasta_la_vista_2();
	exit(FAILURE);
}
