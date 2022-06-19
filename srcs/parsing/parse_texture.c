/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/18 20:22:40 by ajung            ###   ########.fr       */
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
	if (data->tex.path[NORTH])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[NORTH]= ft_strdup(&line[i]);
	data->tex.path[NORTH] = ft_strtrim(data->tex.path[NORTH], "\n \t");
	if (!data->tex.path[NORTH])
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
	if (data->tex.path[WEST])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[WEST] = ft_strdup(&line[i]);
	data->tex.path[WEST] = ft_strtrim(data->tex.path[WEST], "\n \t");
	if (!data->tex.path[WEST])
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
	if (data->tex.path[EAST])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[EAST] = ft_strdup(&line[i]);
	data->tex.path[EAST] = ft_strtrim(data->tex.path[EAST], "\n \t");
	if (!data->tex.path[EAST])
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
	if (data->tex.path[SOUTH])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[SOUTH] = ft_strdup(&line[i]);
	data->tex.path[SOUTH] = ft_strtrim(data->tex.path[SOUTH], "\n \t");
	if (!data->tex.path[SOUTH])
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}
