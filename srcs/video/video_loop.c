/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   video_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:40:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/16 15:34:11 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	video_loop(void)
{
	t_mlx	*mlx;

	mlx = _mlx();
	create_window();
	init_player();
	hook();
	mlx_loop(mlx->var.mlx);
}
