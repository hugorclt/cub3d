/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:15:45 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 19:26:07 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_select(char *line, int i)
{
	if (line[i] && ft_strnstr(line + i, "NO", 2))
		parse_texture_insert(line + i + 2, 'N');
	else if (line[i] && ft_strnstr(line + i, "SO", 2))
		parse_texture_insert(line + i + 2, 'S');
	else if (line[i] && ft_strnstr(line + i, "WE", 2))
		parse_texture_insert(line + i + 2, 'W');
	else if (line[i] && ft_strnstr(line + i, "EA", 2))
		parse_texture_insert(line + i + 2, 'E');
	else if (line[i] && ft_strnstr(line + i, "F", 2))
		parse_insert_color(line + i + 1, &data->texture.floor);
	else if (line[i] && ft_strnstr(line + i, "C", 2))
		parse_insert_color(line + i + 1, &data->texture.ceiling);
	else
		return (FAILURE);
	return (SUCCESS);
}

int	parse_data_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		skip_space(line + i);
		parse_select(line, i);

		i++;
	}
	return (0);
}

void	parsing(int ac, char **argv)
{
	char	*line;
	t_data	*data;
	
	open_map(argv);
	data = _data();
	line = get_next_line(data->map.fd);
	while (line)
	{
		if (ft_strcmp(line, "\n") != 0) //Si la ligne n'est pas vide
		{
			parse_data_map(line);
		}
		free(line);
		line = get_next_line(data->map.fd);
	}
	free(line);
}
