/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 03:03:38 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_texture_north(char *line)
{
	t_data	*data;
	int		i;

	i = 0;
	data = _data();
	// skip_space(line);
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
	// skip_space(line);
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
	// skip_space(line);
	skip_space_new(line, &i);
	if (data->texture.south)
		hasta_la_vista_baby("Doublon detected");
	data->texture.south = ft_strdup(&line[i]);
	if (!data->texture.south)
		hasta_la_vista_baby("Memory alloc fail");		
	return (SUCCESS);
}

/* int	parse_select_texture(char *line, char c)
{
	t_data	*data;

	data = _data();
	skip_space(line);
	if (c == 'N')
	{
		if (data->texture.north)
		{
			free(line);
			hasta_la_vista_baby("Doublon detected");
		}
			
		data->texture.north = ft_strdup(line);
		if (!data->texture.north)
			hasta_la_vista_baby("Memory alloc fail");
	}
	else if (c == 'S')
	{
		if (data->texture.south)
			hasta_la_vista_baby("Doublon detected");
		data->texture.south = ft_strdup(line);
		if (!data->texture.south)
			hasta_la_vista_baby("Memory alloc fail");
	}
	else if (c == 'W')
	{
		if (data->texture.west)
			hasta_la_vista_baby("Doublon detected");
		data->texture.west = ft_strdup(line);
		if (!data->texture.west)
			hasta_la_vista_baby("Memory alloc fail");
	}
	else if (c == 'E')
	{
		if (data->texture.east)
			hasta_la_vista_baby("Doublon detected");
		data->texture.east = ft_strdup(line);
		if (!data->texture.east)
			hasta_la_vista_baby("Memory alloc fail");
	}
	return (SUCCESS);
}
 */
