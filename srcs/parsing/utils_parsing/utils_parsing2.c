/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:09 by ajung             #+#    #+#             */
/*   Updated: 2022/06/17 18:54:59 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (SUCCESS);
	return (FAILURE);
}

void	ft_print_map(void)
{
	t_data	*data;
	int		i;

	data = _data();
	i = 0;
	while (data->map.map[i])
	{
		printf("%s\n", data->map.map[i]);
		i++;
	}
}

void	print_struct(void)
{
	t_data	*data;

	data = _data();
	printf("no : %s\n", data->tex.path.north);
	printf("so : %s\n", data->tex.path.south);
	printf("we : %s\n", data->tex.path.west);
	printf("ea : %s\n", data->tex.path.east);
	printf("rgb floor : %d,", data->tex.floor.trgb.r);
	printf("%d,", data->tex.floor.trgb.g);
	printf("%d\n", data->tex.floor.trgb.b);
	printf("rgb ceilling : %d,", data->tex.ceiling.trgb.r);
	printf("%d,", data->tex.ceiling.trgb.g);
	printf("%d\n", data->tex.ceiling.trgb.b);
	ft_print_map();
}

int	len_number(char *line)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] != ',' && line[i] != ' ' && line[i] != '\n'))
		i++;
	return (i);
}

void	skip_newline(void)
{
	t_data	*data;

	data = _data();
	data->map.line = get_next_line(data->map.fd);
	if (!data->map.line)
		hasta_la_vista_baby("malloc error");
	while (data->map.line[0] == '\n')
	{
		free(data->map.line);
		data->map.line = get_next_line(data->map.fd);
		if (!data->map.line)
			hasta_la_vista_baby("malloc error");
	}
}
