/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:09 by ajung             #+#    #+#             */
/*   Updated: 2022/06/06 18:43:30 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hasta_la_vista_baby(char *str)
{
	t_data	*data;

	data = _data();
	free(data->texture.north);
	free(data->texture.south);
	free(data->texture.east);
	free(data->texture.west);
	free_tab(data->map.map);

	if (str)
		printf("Error: %s\n");
	exit(1);
}
