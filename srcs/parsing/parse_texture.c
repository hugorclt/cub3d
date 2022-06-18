/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/18 16:13:03 by hrecolet         ###   ########.fr       */
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
	if (data->tex.path[0])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[0] = ft_strdup(&line[i]);
	data->tex.path[0] = ft_strtrim(data->tex.path[0], "\n ");
	if (!data->tex.path[0])
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
	if (data->tex.path[1])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[1] = ft_strdup(&line[i]);
	data->tex.path[1] = ft_strtrim(data->tex.path[1], "\n ");
	if (!data->tex.path[1])
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
	if (data->tex.path[2])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[2] = ft_strdup(&line[i]);
	data->tex.path[2] = ft_strtrim(data->tex.path[2], "\n ");
	if (!data->tex.path[2])
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
	if (data->tex.path[3])
		hasta_la_vista_baby("Doublon detected");
	data->tex.path[3] = ft_strdup(&line[i]);
	data->tex.path[3] = ft_strtrim(data->tex.path[3], "\n ");
	if (!data->tex.path[3])
		hasta_la_vista_baby("Memory alloc fail");
	return (SUCCESS);
}
