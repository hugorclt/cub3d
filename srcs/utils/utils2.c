/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:09 by ajung             #+#    #+#             */
/*   Updated: 2022/06/06 21:00:39 by ajung            ###   ########.fr       */
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
	free(data->map.line);
	free_tab(data->map.map);
	if (data->map.fd > 0)
		close(data->map.fd);
	if (str)
		printf("Error: %s\n");
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
	printf("rgb floor : %d,", data->texture.floor.r);
	printf("%d,", data->texture.floor.g);
	printf("%d\n", data->texture.floor.b);
	printf("rgb ceilling : %d,", data->texture.ceiling.r);
	printf("%d,", data->texture.ceiling.g);
	printf("%d\n", data->texture.ceiling.b);
}
