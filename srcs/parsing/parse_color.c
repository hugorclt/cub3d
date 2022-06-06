/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 14:39:20 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 15:30:07 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_insert_color(char *line, t_rgb *fill)
{
	char	**color;

	color = ft_split(line + 2, ',');
	if (color == NULL)
		return (-1);
	fill->r = ft_atoi(color[0]);
	fill->g = ft_atoi(color[1]);
	fill->b = ft_atoi(color[2]);
	free_tab(color);
	return (0);
}

static int	parse_color(char *line, int *i)
{
	t_data *data;

	data = _data();
	if (ft_strnstr(line, "F", 1) != NULL)
	{
		if (parse_insert_color(line, &data->texture.f) == -1)
			return (-1);
		(*i)++;
	}
	else if (ft_strnstr(line, "C", 1) != NULL)
	{
		if (parse_insert_color(line, &data->texture.c) == -1)
			return (-1);
		(*i)++;
	}
	return (0);
}

int	parse_ceiling_floor(int fd, char *line)
{
	int		i;
	
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (i == 2)
			break ;
		if (ft_strcmp(line, "\n") != 0)
		{
			if (parse_color(line , &i) == -1)
				return (-1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
