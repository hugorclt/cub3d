/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:23:05 by ajung             #+#    #+#             */
/*   Updated: 2022/06/24 18:56:32 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_power_of_two(int nb)
{
	if (nb <= 0)
		return (FAILURE);
	while (nb != 1)
	{
		if (nb % 2 != 0)
			return (FAILURE);
		nb = nb / 2;
	}
	return (SUCCESS);
}

static void	check_texture(int width, int height)
{
	if (width != height)
		hasta_la_vista_baby("Invalid texture");
	if (is_power_of_two(width) == FAILURE)
		hasta_la_vista_baby("Invalid texture");
}

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
		check_texture(tex->img[i].width, tex->img[i].height);
		tex->img[i].addr = (int *)mlx_get_data_addr(tex->img[i].img_ptr,
				&tex->img[i].bits_per_pixel, &tex->img[i].width,
				&tex->img[i].endian);
		if (!tex->img[i].addr)
			hasta_la_vista_baby("mlx fail");
		i++;
	}
}
