/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:29:37 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/22 15:44:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	parse_is_header(char *line)
{
	int		i;

	i = 0;
	skip_space_new(line, &i);
	if (ft_strnstr(line + i, "NO", 2))
		return (SUCCESS);
	else if (ft_strnstr(line + i, "SO", 2))
		return (SUCCESS);
	else if (ft_strnstr(line + i, "WE", 2))
		return (SUCCESS);
	else if (ft_strnstr(line + i, "EA", 2))
		return (SUCCESS);
	else if (ft_strnstr(line + i, "F", 1))
		return (SUCCESS);
	else if (ft_strnstr(line + i, "C", 1))
		return (SUCCESS);
	else
		return (FAILURE);
}

void	skip_to_map(void)
{
	t_data	*data;

	data = _data();
	data->map.line = get_next_line(data->map.fd);
	while (ft_strcmp(data->map.line, "\n") == TRUE
		|| parse_is_header(data->map.line) == SUCCESS)
	{
		free(data->map.line);
		data->map.line = get_next_line(data->map.fd);
	}
}

void	parse_get_map(void)
{
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	skip_to_map();
	while (data->map.line)
	{
		data->map.map[i] = ft_strdup(data->map.line);
		data->map.map[i] = ft_strtrim(data->map.map[i], "\n");
		if (!data->map.map[i])
			hasta_la_vista_baby("malloc error");
		free(data->map.line);
		data->map.line = get_next_line(data->map.fd);
		if (!data->map.line && i != data->map.max_y - 1)
			hasta_la_vista_baby("invalid map");
		i++;
	}
	data->map.map[i] = NULL;
}

void	parse_map(char **av)
{
	t_data	*data;

	data = _data();
	parse_get_max_y();
	open_map(av);
	data->map.map = malloc(sizeof(char *) * (data->map.max_y + 1));
	if (!data->map.map)
		hasta_la_vista_baby("malloc error");
	parse_get_map();
}
