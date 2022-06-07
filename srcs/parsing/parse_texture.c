/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 18:15:19 by ajung            ###   ########.fr       */
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
	if (data->texture.north)
		hasta_la_vista_baby("Doublon detected");
	data->texture.north = ft_strdup(&line[i]);
	data->texture.north = ft_strtrim(data->texture.north, "\n");
	if (!data->texture.north)
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
	if (data->texture.west)
		hasta_la_vista_baby("Doublon detected");
	data->texture.west = ft_strdup(&line[i]);
	data->texture.west = ft_strtrim(data->texture.west, "\n");
	if (!data->texture.west)
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
	if (data->texture.east)
		hasta_la_vista_baby("Doublon detected");
	data->texture.east = ft_strdup(&line[i]);
	data->texture.east = ft_strtrim(data->texture.east, "\n");
	if (!data->texture.east)
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
	if (data->texture.south)
		hasta_la_vista_baby("Doublon detected");
	data->texture.south = ft_strdup(&line[i]);
	data->texture.south = ft_strtrim(data->texture.south, "\n");
	if (!data->texture.south)
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}
