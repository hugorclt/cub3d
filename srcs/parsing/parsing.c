/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:15:45 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/17 10:01:49 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_select(char *line)
{
	t_data	*data;

	data = _data();
	if (*line && ft_strnstr(line, "NO", 2))
		parse_texture_north(line + 2);
	else if (*line && ft_strnstr(line, "SO", 2))
		parse_texture_south(line + 2);
	else if (*line && ft_strnstr(line, "WE", 2))
		parse_texture_west(line + 2);
	else if (*line && ft_strnstr(line, "EA", 2))
		parse_texture_east(line + 2);
	else if (*line && ft_strnstr(line, "F", 1))
	{
		parse_insert_color(line + 1, &data->texture.floor);
		data->texture.floor_filled = TRUE;
	}
	else if (*line && ft_strnstr(line, "C", 1))
	{
		parse_insert_color(line + 1, &data->texture.ceiling);
		data->texture.ceiling_filled = TRUE;
	}
	else
		hasta_la_vista_baby("bad format");
	return (SUCCESS);
}

int	parse_data_map(char *line)
{
	int	i;

	i = 0;
	skip_space_new(line, &i);
	parse_select(&line[i]);
	return (0);
}

void	open_map(char **argv)
{
	t_data	*data;

	data = _data();
	data->map.fd = open(argv[1], O_RDONLY);
	if (data->map.fd < 0)
		hasta_la_vista_baby("open fail");
}

int	check_struct_filled(void)
{
	t_data	*data;

	data = _data();
	if (!data->texture.north || !data->texture.south
		|| !data->texture.west || !data->texture.east)
		return (FAILURE);
	if (data->texture.ceiling_filled == FALSE
		|| data->texture.floor_filled == FALSE)
		return (FAILURE);
	return (SUCCESS);
}

void	parsing(char **argv)
{
	t_data	*data;

	open_map(argv);
	data = _data();
	data->texture.ceiling_filled = FALSE;
	data->texture.floor_filled = FALSE;
	data->teximg = malloc(sizeof(t_teximg) * 4);
	if (!data->teximg)
		hasta_la_vista_baby("malloc fail");
	data->map.line = get_next_line(data->map.fd);
	if (!data->map.line)
		hasta_la_vista_baby("Memory alloc fail");
	while (data->map.line)
	{
		if (ft_strcmp(data->map.line, "\n") != 0)
			parse_data_map(data->map.line);
		free(data->map.line);
		if (check_struct_filled() == SUCCESS)
			break ;
		data->map.line = get_next_line(data->map.fd);
		if (!data->map.line)
			hasta_la_vista_baby("Memory alloc fail");
	}
	parse_map(argv);
}
