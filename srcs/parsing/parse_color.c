/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:32:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 17:56:41 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_insert_color(char *line, t_rgb *color)
{
	int		i;
	int		len_color;

	i = 0;
	while (i < 3)
	{
		skip_space(line);
		if (is_num(line) == -1)
			return (-1);
		len_color = len_number(line);
		if (i == 0)
			color->r = ft_atoi(ft_substr(line, 0, len_color));
		else if (i == 1)
			color->g = ft_atoi(ft_substr(line, 0, len_color));
		else if (i == 2)
			color->b = ft_atoi(ft_substr(line, 0, len_color));
		line += len_color;
		skip_space(line);
		if (line[0] != ',')
			return (-1);
		line++;
		i++;
	}
	return (0);
}

int	parse_select_color(char *line, int i)
{
	t_data *data;

	data = _data();
	if (line[i] && ft_strnstr(line + i, "F", 1))
	{
		if (parse_insert_color(line + i + 1, &data->texture.f) == -1)
			return (-1);
	}
	else if (line[i] && ft_strnstr(line + i, "C", 1))
	{
		if (parse_insert_color(line + i + 1, &data->texture.c) == -1)
			return (-1);
	}
	return (0);
}
