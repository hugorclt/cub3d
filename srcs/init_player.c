/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 13:02:30 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/09 10:01:26 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (SUCCESS);
	return (FAILURE);
}

void	init_player_position(void)
{
	int		i;
	int		j;
	t_data	*data;

	data = _data();
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (is_player(data->map.map[i][j]) == SUCCESS)
			{
				data->player.x = j;
				data->player.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_player_direction(void)
{
	t_data	*data;

	data = _data();
	if (data->map.map[(int)data->player.y][(int)data->player.x] == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
	}
	else if (data->map.map[(int)data->player.y][(int)data->player.x] == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
	}
	else if (data->map.map[(int)data->player.y][(int)data->player.x] == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
	}
	else if (data->map.map[(int)data->player.y][(int)data->player.x] == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
	}
}

void	init_player(void)
{
	t_data	*data;

	data = _data();
	init_player_position();
	init_player_direction();
	//data->player.dir_x = -1;
	//data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
}
