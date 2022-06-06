/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:13:53 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 18:12:08 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_texture_insert(char *line, char c)
{
	t_data	*data;

	data = _data();
	skip_space(line);
	if (c == 'N')
	{
		if (data->texture.no)
			return (printf-1);
		
		
		data->texture.no = ft_strdup(line);
		if (!data->texture.no)
			return (-1);
	}
	else if (c == 'S')
	{
		data->texture.so = ft_strdup(line);
		if (!data->texture.so)
			return (-1);
	}
	else if (c == 'W')
	{
		data->texture.we = ft_strdup(line);
		if (!data->texture.we)
			return (-1);
	}
	else if (c == 'E')
	{
		data->texture.ea = ft_strdup(line);
		if (!data->texture.ea)
			return (-1);
	}
	return (0);
}

static int	parse_select_texture(char *line, int i)
{
	if (line[i] && ft_strnstr(line + i, "NO", 2))
	{
		if (parse_texture_insert(line + i + 2, 'N') == -1)
			return (-1);
	}
	else if (line[i] && ft_strnstr(line + i, "SO", 2))
	{
		if (parse_texture_insert(line + i + 2, 'S') == -1)
			return (-1);
	}
	else if (line[i] && ft_strnstr(line + i, "WE", 2))
	{
		if (parse_texture_insert(line + i + 2, 'W') == -1)
			return (-1);
	}
	else if (line[i] && ft_strnstr(line + i, "EA", 2))
	{
		if (parse_texture_insert(line + i + 2, 'E') == -1)
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	parse_data_map(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		skip_space(line + i);
		if (parse_select_texture(line, i) == -1)
			return (printf("Error\n"), -1);
		if (parse_select_color(line, i) == -1)
			return (printf("Error\n"), -1);
		i++;
	}
	return (0);
}
