/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:56:19 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/07 17:06:50 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_line_size(void)
{
	int	i;
	t_data	*data;

	data = _data();
	i = 0;
	while (data->map.map[i])
	{
		if ((int)ft_strlen(data->map.map[i]) != data->map.max_x)
			hasta_la_vista_baby("Wrong map size");
		i++;
	}
}
