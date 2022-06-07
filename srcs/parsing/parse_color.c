/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 20:02:49 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 17:40:10 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	nike_la_naurme(char	*str, t_color *color, int len_color, int tour)
{
	if (tour == 0)
		color->trgb.r = ft_atoi(ft_substr(str, 0, len_color));
	else if (tour == 1)
		color->trgb.g = ft_atoi(ft_substr(str, 0, len_color));
	else if (tour == 2)
		color->trgb.b = ft_atoi(ft_substr(str, 0, len_color));
}

int	parse_insert_color(char *line, t_color *color)
{
	int		i;
	int		tour;
	int		len_color;

	i = 0;
	tour = 0;
	while (tour < 3)
	{
		skip_space_new(line, &i);
		if (is_num(&line[i]) == FAILURE)
			hasta_la_vista_baby("non digit character");
		len_color = len_number(&line[i]);
		nike_la_naurme(&line[i], color, len_color, tour);
		i += len_color;
		skip_space_new(line, &i);
		if (tour < 2 && line[i] != ',')
			hasta_la_vista_baby("Bad format");
		if (tour < 2)
			i++;
		tour++;
	}
	if (line[i] != '\n')
		hasta_la_vista_baby("bad format");
	return (SUCCESS);
}
