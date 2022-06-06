/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:24:07 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 15:30:18 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse_launch(int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < 4)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (close(fd), -1);
		if (parse_texture(fd, line) == -1)
			return (free(line), -1);
		free(line);
		i++;
	}
	if (parse_ceiling_floor(fd, line) == -1)
		return (-1);
	return (close(fd), 0);
}

