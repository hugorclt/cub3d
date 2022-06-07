/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:57:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/07 18:15:21 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_diagonale(int i, int j)
{
	t_data	*data;

	data = _data();
	if (data->map.map[i + 1][j + 1] == ' ' || !data->map.map[i + 1][j + 1])
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i - 1][j - 1] == ' ' || !data->map.map[i - 1][j - 1])
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i - 1][j + 1] == ' ' || !data->map.map[i - 1][j + 1])
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i + 1][j - 1] == ' ' || !data->map.map[i + 1][j - 1])
		hasta_la_vista_baby("Map not closed");
}

static void	check_cell_around(int i, int j)
{
	t_data	*data;

	data = _data();
	if (i + 1 >= data->map.max_y || j + 1 >= data->map.max_x)
		hasta_la_vista_baby("Map not closed");
	if (i - 1 < 0 || j - 1 < 0)
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i + 1][j] == ' ' || !data->map.map[i + 1][j])
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i - 1][j] == ' ' || !data->map.map[i - 1][j])
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i][j + 1] == ' ' || !data->map.map[i][j + 1])
		hasta_la_vista_baby("Map not closed");
	if (data->map.map[i][j - 1] == ' ' || !data->map.map[i][j - 1])
		hasta_la_vista_baby("Map not closed");
	check_diagonale(i, j);
}

static void	check_validity(void)
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
				check_cell_around(i, j);
			}
			j++;
		}
		i++;
	}
}

void	check_map(void)
{
	t_data	*data;

	data = _data();
	check_line_size();
	if (data->map.max_y < 3)
		hasta_la_vista_baby("Not enough lines");
	if (data->map.max_x < 3)
		hasta_la_vista_baby("Not enough columns");
	check_char_in_map();
	check_player_in_map();
	check_validity();
}
