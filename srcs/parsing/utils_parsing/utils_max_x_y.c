/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_max_x_y.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:05:50 by ajung             #+#    #+#             */
/*   Updated: 2022/06/22 15:19:58 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_get_max_y(void)
{
	t_data	*data;

	data = _data();
	data->map.max_y = 0;
	skip_newline();
	while (data->map.line)
	{
		data->map.max_y++;
		free(data->map.line);
		data->map.line = get_next_line(data->map.fd);
	}
	free(data->map.line);
	data->map.line = NULL;
	close(data->map.fd);
}
