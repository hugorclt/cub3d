/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:15:45 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 21:10:25 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
	else if (*line && ft_strnstr(line, "F", 2))
		parse_insert_color(line + 1, &data->texture.floor);
	else if (*line && ft_strnstr( line, "C", 2))
		parse_insert_color(line + 1, &data->texture.ceiling);
	else
		hasta_la_vista_baby("bad format");
	return (SUCCESS);
}

int	parse_data_map(char *line)
{
	skip_space(line);
	parse_select(line);
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


void	parsing(int ac, char **argv)
{
	t_data	*data;
	(void)ac;
	
	open_map(argv);
	data = _data();
	data->map.line = get_next_line(data->map.fd);
	while (data->map.line)
	{
		if (ft_strcmp(data->map.line, "\n") != 0)
		{
			parse_data_map(data->map.line);
		}
		free(data->map.line);
		data->map.line = get_next_line(data->map.fd);
	}
}
