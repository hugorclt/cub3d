/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:57:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/22 15:20:33 by hrecolet         ###   ########.fr       */
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
	if (i + 1 >= data->map.max_y)
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
	if (data->map.max_y < 3)
		hasta_la_vista_baby("Not enough lines");
	check_char_in_map();
	check_player_in_map();
	check_validity();
}
