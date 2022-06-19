/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:23:05 by ajung             #+#    #+#             */
/*   Updated: 2022/06/19 15:54:11 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(void)
{
	t_mlx	*mlx;
	t_tex	*tex;
	int		i;

	mlx = _mlx();
	tex = _tex();
	i = 0;
	while (i < 4)
	{
		tex->img[i].img_ptr = mlx_xpm_file_to_image(mlx->var.mlx,
				tex->path[i], &tex->img[i].width, &tex->img[i].height);
		if (!tex->img[i].img_ptr)
			hasta_la_vista_baby("mlx fail");
		tex->img[i].addr = (int *)mlx_get_data_addr(tex->img[i].img_ptr,
				&tex->img[i].bits_per_pixel, &tex->img[i].width,
				&tex->img[i].endian);
		if (!tex->img[i].addr)
			hasta_la_vista_baby("mlx fail");
		i++;
	}
}
