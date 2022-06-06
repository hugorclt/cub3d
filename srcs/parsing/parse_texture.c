/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:13:53 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 15:58:24 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	parse_insert_we_ea(char *line)
{
	t_data	*data;

	data = _data();
	if (ft_strnstr(line, "WE", 2) != NULL)
	{
		data->texture.we = ft_strdup(line + 3);
		if (data->texture.we == NULL)
			return (-1);
	}
	else if (ft_strnstr(line, "EA", 2) != NULL)
	{
		data->texture.ea = ft_strdup(line + 3);
		if (data->texture.ea == NULL)
			return (-1);
	}
	return (0);
}

static int	parse_insert_no_so(char *line)
{
	t_data	*data;

	data = _data();
	if (ft_strnstr(line, "NO", 2) != NULL)
	{
		data->texture.no = ft_strdup(line + 3);
		if (data->texture.no == NULL)
			return (-1);
	}
	else if (ft_strnstr(line, "SO", 2) != NULL)
	{
		data->texture.so = ft_strdup(line + 3);
		if (data->texture.so == NULL)
			return (-1);
	}
	return (0);
}

int	parse_texture(int fd, char *line)
{
	if (parse_insert_no_so(line) == -1)
		return (close(fd), -1);
	if (parse_insert_we_ea(line) == -1)
		return (close(fd), -1);
	return (0);
}

