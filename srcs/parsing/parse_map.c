/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:29:37 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/07 13:04:35 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	parse_get_max_y(void)
{
	char	*line;
	t_data	*data;

	data = _data();
	line = get_next_line(data->map.fd);
	data->map.max_y = 0;
	if (!line)
		hasta_la_vista_baby("malloc error");
	data->map.max_y = 1;
	while (line)
	{
		free(line);
		line = get_next_line(data->map.fd);
		data->map.max_y++;
	}
	free(line);
	close(data->map.fd);
}

void	parse_get_max_x(char *line)
{
	t_data	*data;

	data = _data();
	data->map.max_x = ft_strlen(line);
	data->map.max_x--;
}

int	parse_is_header(char *line)
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

void	parse_line(char **tmp, int *i)
{
	t_data	*data;

	data = _data();
	if (ft_strcmp(*tmp, "\n") != 0 && parse_is_header(*tmp) == FAILURE)
	{
		if (i == 0)
			parse_get_max_x(*tmp);
		data->map.map[*i] = ft_strdup(*tmp);
		data->map.map[*i] = ft_strtrim(data->map.map[*i], "\n");
		if (!data->map.map[*i])
			hasta_la_vista_baby("malloc error");
		(*i)++;
	}
	free(*tmp);
	*tmp = get_next_line(data->map.fd);
}

void	parse_map(char **argv)
{
	t_data	*data;
	int		i;
	char	*tmp;

	data = _data();
	i = 0;
	parse_get_max_y();
	open_map(argv);
	data->map.map = malloc(sizeof(char *) * (data->map.max_y + 1));
	tmp = get_next_line(data->map.fd);
	if (!tmp)
		hasta_la_vista_baby("malloc error");
	while (tmp)
		parse_line(&tmp, &i);
	data->map.map[i] = NULL;
	free(tmp);
}
