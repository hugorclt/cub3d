/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasta_la_vista.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:59:14 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/18 17:56:08 by hrecolet         ###   ########.fr       */
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
}

void	hasta_la_vista_baby(char *str)
{
	t_data	*data;
	t_mlx	*mlx;

	data = _data();
	mlx = _mlx();
	if (str)
		printf("Error: %s\n", str);
	free(data->tex.path[0]);
	free(data->tex.path[1]);
	free(data->tex.path[2]);
	free(data->tex.path[3]);
	free(data->map.line);
	if (data->map.map)
		free_tab(data->map.map);
	if (data->map.fd > 0)
		close(data->map.fd);
	hasta_la_vista_2();
	free(mlx->var.mlx);
	exit(FAILURE);
}
