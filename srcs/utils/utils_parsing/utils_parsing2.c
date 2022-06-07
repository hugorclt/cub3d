/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:09 by ajung             #+#    #+#             */
/*   Updated: 2022/06/07 19:19:52 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hasta_la_vista_baby(char *str)
{
	t_data	*data;
	t_mlx	*mlx;

	data = _data();
	mlx = _mlx();
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
/* 	mlx_destroy_window(mlx->var.mlx, mlx->var.win);
	mlx_destroy_image(mlx->var.mlx, mlx->image.img_ptr);
	mlx_destroy_display(mlx->var.mlx);
	free(mlx->var.mlx); */ //--> A MODIFIER
	exit(FAILURE);
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
