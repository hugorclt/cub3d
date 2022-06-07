/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:44 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 19:06:45 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	*_data(void)
{
	static t_data	data;
	static int		check = 0;

	if (check == 0)
	{
		ft_bzero(&data, sizeof(t_data));
		check = 1;
	}
	return (&data);
}

t_mlx	*_mlx(void)
{
	t_data	*data;
	t_mlx	*mlx;

	data = _data();
	mlx = &(data->mlx);
	return (mlx);
}
