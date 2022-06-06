/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:02:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/06 20:56:37 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_insert_color(char *line, t_color *color)
{
	int		i;
	int		len_color;

	i = 0;
	while (i < 3)
	{
		skip_space(line);
		if (is_num(line) == FAILURE)
			hasta_la_vista_baby("non digit character");
		len_color = len_number(line);
		if (i == 0)
			color->trgb.r = ft_atoi(ft_substr(line, 0, len_color));
		else if (i == 1)
			color->trgb.g = ft_atoi(ft_substr(line, 0, len_color));
		else if (i == 2)
			color->trgb.b = ft_atoi(ft_substr(line, 0, len_color));
		line += len_color;
		skip_space(line);
		if (i < 2 && line[0] != ',')
			hasta_la_vista_baby("Bad format");
		if (i < 2)
			line++;
		i++;
	}
	if (line[0] != '\n')
		hasta_la_vista_baby("bad format");
	return (SUCCESS);
}

int	parse_color_floor(char *line)
{
	t_data	*data;
	int		i;
	int		end_num;

	data = _data();
	i = 0;
	end_num = 0;
	skip_space(line);
	while (ft_isdigit(line[i]) == TRUE)
		i++;
	
}

int	parse_color_ceiling(char *line)
{
	t_data	*data;

	data = _data();
}

//F 111, 111                       , 111
