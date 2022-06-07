/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oryzon <oryzon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:09 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 03:31:30 by oryzon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	hasta_la_vista_baby(char *str)
{
	t_data	*data;

	data = _data();
	free(data->texture.north);
	free(data->texture.south);
	free(data->texture.east);
	free(data->texture.west);
	free(data->map.line);
	if (data->map.map)
		free_tab(data->map.map);
	if (data->map.fd > 0)
		close(data->map.fd);
	if (str)
		printf("Error: %s\n", str);
	exit(1);
}

void	print_struct(void)
{
	t_data	*data;

	data = _data();
	printf("no : %s\n", data->texture.north);
	printf("so : %s\n", data->texture.south);
	printf("we : %s\n", data->texture.west);
	printf("ea : %s\n", data->texture.east);
	printf("rgb floor : %d,", data->texture.floor.trgb.r);
	printf("%d,", data->texture.floor.trgb.g);
	printf("%d\n", data->texture.floor.trgb.b);
	printf("rgb ceilling : %d,", data->texture.ceiling.trgb.r);
	printf("%d,", data->texture.ceiling.trgb.g);
	printf("%d\n", data->texture.ceiling.trgb.b);
}
