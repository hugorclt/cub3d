/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:02:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/06 21:31:03 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_insert_color(char *line, t_color *color)
{
	int		i;
	int		len_color;

	i = 0;
	while (i < 3)
	{
		printf("before in insert color : %c\n", *line);
		skip_space(line);
		printf("after in insert color : %c\n", *line);
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

