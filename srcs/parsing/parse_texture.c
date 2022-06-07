/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 11:17:58 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_texture_north(char *line)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	skip_space_new(line, &i);
	if (data->texture.north)
		hasta_la_vista_baby("Doublon detected");
	data->texture.north = ft_strdup(&line[i]);
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
	skip_space_new(line, &i);	
	if (data->texture.west)
		hasta_la_vista_baby("Doublon detected");
	data->texture.west = ft_strdup(&line[i]);
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
	// skip_space(line);
	skip_space_new(line, &i);
	if (data->texture.east)
		hasta_la_vista_baby("Doublon detected");
	data->texture.east = ft_strdup(&line[i]);
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
	skip_space_new(line, &i);
	if (data->texture.south)
		hasta_la_vista_baby("Doublon detected");
	data->texture.south = ft_strdup(&line[i]);
	if (!data->texture.south)
		hasta_la_vista_baby("Memory alloc fail");		
	return (SUCCESS);
}

