/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:02:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 03:04:27 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_insert_color(char *line, t_color *color)
{
	int		i;
	int		tour;
	int		len_color;

	i = 0;
	tour = 0;
	while (tour < 3)
	{
		// printf("before in insert color : %c\n", *line);
		// skip_space(line);
		// printf("after in insert color : %c\n", *line);
		skip_space_new(&line[i], &i);
		if (is_num(&line[i]) == FAILURE)
			hasta_la_vista_baby("non digit character");
		len_color = len_number(&line[i]);
		if (i == 0)
			color->trgb.r = ft_atoi(ft_substr(&line[i], 0, len_color));
		else if (i == 1)
			color->trgb.g = ft_atoi(ft_substr(&line[i], 0, len_color));
		else if (i == 2)
			color->trgb.b = ft_atoi(ft_substr(&line[i], 0, len_color));
		// line += len_color;
		i += len_color;
		// skip_space(line);
		skip_space_new(line, &i);
		// if (i < 2 && line[0] != ',')
		if (tour < 2 && line[i] != ',')
			hasta_la_vista_baby("Bad format");
		// if (i < 2)
		// 	line++;
		if (tour < 2)
			i++;
		tour++;
	}
	// if (line[0] != '\n')
	if (line[i] != '\n')
		hasta_la_vista_baby("bad format");
	return (SUCCESS);
}
