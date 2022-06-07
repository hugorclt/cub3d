/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:57:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/07 14:57:08 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	check_char_in_map()
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

static void	check_player_in_map()
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
		hasta_la_vista_baby("Wrong player in map");
}

static void	check_cell_around(char **line, int i, int j)
{
	// x
	//x0x check cell juxtapose
	// x
	if (line[i + 1][j] == ' ' || !line[i + 1][j])
		hasta_la_vista_baby("Map not closed");
	if (line[i - 1][j] == ' ' || !line[i - 1][j])
		hasta_la_vista_baby("Map not closed");
	if (line[i][j + 1] == ' ' || !line[i][j + 1])
		hasta_la_vista_baby("Map not closed");
	if (line[i][j - 1] == ' ' || !line[i][j - 1])
		hasta_la_vista_baby("Map not closed");
		
	//x x
	// 0   check cell coin
	//x x
	if (line[i + 1][j + 1] == ' ' || !line[i + 1][j + 1])
		hasta_la_vista_baby("Map not closed");
	if (line[i - 1][j - 1] == ' ' || !line[i - 1][j - 1])
		hasta_la_vista_baby("Map not closed");
	if (line[i - 1][j + 1] == ' ' || !line[i - 1][j + 1])
		hasta_la_vista_baby("Map not closed");
	if (line[i + 1][j - 1] == ' ' || !line[i + 1][j - 1])
		hasta_la_vista_baby("Map not closed");
}

static void	check_validity()
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
			if (data->map.map[i][j] == '0'
				|| data->map.map[i][j] == 'N' || data->map.map[i][j] == 'S'
				|| data->map.map[i][j] == 'E' || data->map.map[i][j] == 'W')
			{
				check_cell_around(data->map.map, i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_map()
{
	t_data	*data;

	data = _data();
	check_line();
	if (data->map.max_y < 3)
		hasta_la_vista_baby("Not enough lines");
	if (data->map.max_x < 3)
		hasta_la_vista_baby("Not enough columns");
	check_char_in_map();
	check_player_in_map();
	check_validity();
}
