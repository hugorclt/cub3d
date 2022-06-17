/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 19:57:59 by ajung             #+#    #+#             */
/*   Updated: 2022/06/17 10:46:34 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture_north(char *line)
{
	t_data	*data;
	t_mlx	*mlx;
	int		i;

	i = 0;
	mlx = _mlx();
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->texture.north)
		hasta_la_vista_baby("Doublon detected");
	data->texture.north = ft_strdup(&line[i]);
	data->texture.north = ft_strtrim(data->texture.north, "\n ");
	if (!data->texture.north)
		hasta_la_vista_baby("Memory alloc fail");
	data->teximg[0].img = mlx_xpm_file_to_image(mlx->var.mlx, data->texture.north,
			&data->teximg[0].width, &data->teximg[0].height);
	if (!data->teximg[0].img)
		hasta_la_vista_baby("Texture fa1il");
	data->teximg[0].addr = (int *)mlx_get_data_addr(data->teximg[0].img,
			&data->teximg[0].bpp, &data->teximg[0].line_len,
			&data->teximg[0].endian);
	return (SUCCESS);
}

int	parse_texture_west(char *line)
{
	t_data	*data;
	t_mlx	*mlx;
	int		i;

	i = 0;
	data = _data();
	mlx = _mlx();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->texture.west)
		hasta_la_vista_baby("Doublon detected");
	data->texture.west = ft_strdup(&line[i]);
	data->texture.west = ft_strtrim(data->texture.west, "\n ");
	if (!data->texture.west)
		hasta_la_vista_baby("Memory alloc fail");
	data->teximg[1].img = mlx_xpm_file_to_image(mlx->var.mlx, data->texture.west,
			&data->teximg[1].width, &data->teximg[1].height);
	if (!data->teximg[1].img)
		hasta_la_vista_baby("Texture fail");
	data->teximg[1].addr = (int *)mlx_get_data_addr(data->teximg[1].img,
			&data->teximg[1].bpp, &data->teximg[1].line_len,
			&data->teximg[1].endian);
	return (SUCCESS);
}

int	parse_texture_east(char *line)
{
	t_data	*data;
	t_mlx	*mlx;
	int		i;

	i = 0;
	mlx = _mlx();
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->texture.east)
		hasta_la_vista_baby("Doublon detected");
	data->texture.east = ft_strdup(&line[i]);
	data->texture.east = ft_strtrim(data->texture.east, "\n ");
	if (!data->texture.east)
		hasta_la_vista_baby("Memory alloc fail");
	data->teximg[2].img = mlx_xpm_file_to_image(mlx->var.mlx, data->texture.east,
			&data->teximg[2].width, &data->teximg[2].height);
	if (!data->teximg[2].img)
		hasta_la_vista_baby("Texture fail");
	data->teximg[2].addr = (int *)mlx_get_data_addr(data->teximg[2].img,
			&data->teximg[2].bpp, &data->teximg[2].line_len,
			&data->teximg[2].endian);
	return (SUCCESS);
}

int	parse_texture_south(char *line)
{
	t_data	*data;
	t_mlx	*mlx;
	int		i;

	i = 0;
	mlx = _mlx();
	data = _data();
	if (line[i] != ' ')
		hasta_la_vista_baby("Wrong format");
	skip_space_new(line, &i);
	if (data->texture.south)
		hasta_la_vista_baby("Doublon detected");
	data->texture.south = ft_strdup(&line[i]);
	data->texture.south = ft_strtrim(data->texture.south, "\n ");
	if (!data->texture.south)
		hasta_la_vista_baby("Memory alloc fail");
	data->teximg[3].img = mlx_xpm_file_to_image(mlx->var.mlx, data->texture.south,
			&data->teximg[3].width, &data->teximg[3].height);
	if (!data->teximg[3].img)
		hasta_la_vista_baby("Texture fail");
	data->teximg[3].addr = (int *)mlx_get_data_addr(data->teximg[3].img,
			&data->teximg[3].bpp, &data->teximg[3].line_len,
			&data->teximg[3].endian);
	return (SUCCESS);
}
