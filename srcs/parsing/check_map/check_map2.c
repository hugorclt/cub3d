/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:56:19 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/22 15:19:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_char_in_map(void)
{
	t_data	*data;
	int		i;
	int		j;

	data = _data();
	i = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] != '1' && data->map.map[i][j] != '0'
				&& data->map.map[i][j] != ' ' && data->map.map[i][j] != 'N'
				&& data->map.map[i][j] != 'S' && data->map.map[i][j] != 'E'
				&& data->map.map[i][j] != 'W')
				hasta_la_vista_baby("Wrong character in map");
			j++;
		}
		i++;
	}
}

void	check_player_in_map(void)
{
	t_data	*data;
	int		i;
	int		j;
	int		total;

	data = _data();
	i = 0;
	total = 0;
	while (data->map.map[i])
	{
		j = 0;
		while (data->map.map[i][j])
		{
			if (data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
				total++;
			j++;
		}
		i++;
	}
	if (total != 1)
		hasta_la_vista_baby("Wrong number of player in map");
}
