/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/17 21:43:54 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture_north(char *line)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->tex.path.north)
		hasta_la_vista_baby("Doublon detected");
	data->tex.path.north = ft_strdup(&line[i]);
	data->tex.path.north = ft_strtrim(data->tex.path.north, "\n ");
	if (!data->tex.path.north)
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}

int	parse_texture_west(char *line)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->tex.path.west)
		hasta_la_vista_baby("Doublon detected");
	data->tex.path.west = ft_strdup(&line[i]);
	data->tex.path.west = ft_strtrim(data->tex.path.west, "\n ");
	if (!data->tex.path.west)
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}

int	parse_texture_east(char *line)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->tex.path.east)
		hasta_la_vista_baby("Doublon detected");
	data->tex.path.east = ft_strdup(&line[i]);
	data->tex.path.east = ft_strtrim(data->tex.path.east, "\n ");
	if (!data->tex.path.east)
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}

int	parse_texture_south(char *line)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->tex.path.south)
		hasta_la_vista_baby("Doublon detected");
	data->tex.path.south = ft_strdup(&line[i]);
	data->tex.path.south = ft_strtrim(data->tex.path.south, "\n ");
	if (!data->tex.path.south)
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}
