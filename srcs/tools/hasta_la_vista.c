/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasta_la_vista.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 01:59:14 by oryzon            #+#    #+#             */
/*   Updated: 2022/06/17 21:30:35 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	hasta_la_vista_3(void)
{
	t_mlx		*mlx;
	t_texture	*tex;
	int			i;

	tex = _tex();
	mlx = _mlx();
	i = 0;
	while (i < 4)
	{
		if (mlx->var.mlx && tex->img[i].img_ptr)
			mlx_destroy_image(mlx->var.mlx, tex->img[i].img_ptr);
		i++;
	}
	free(tex->img);
}

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
	free(data->tex.path.north);
	free(data->tex.path.south);
	free(data->tex.path.east);
	free(data->tex.path.west);
	free(data->map.line);
	if (data->map.map)
		free_tab(data->map.map);
	if (data->map.fd > 0)
		close(data->map.fd);
	hasta_la_vista_2();
	hasta_la_vista_3();
	free(mlx->var.mlx);
	exit(FAILURE);
}
