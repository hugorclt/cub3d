/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 15:28:14 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*_data(void)
{
	static 	t_data	data;
	static int 		check = 0;

	if (check == 0)
	{
		ft_bzero(&data, sizeof(t_data));
		check = 1;
	}
	return (&data);
}

void	print_struct(void)
{
	t_data	*data;

	data = _data();
	printf("no : %s\n", data->texture.no);
	printf("so : %s\n", data->texture.so);
	printf("we : %s\n", data->texture.we);
	printf("ea : %s\n", data->texture.ea);
	printf("rgb floor : %d,", data->texture.f.r);
	printf("%d,", data->texture.f.g);
	printf("%d\n", data->texture.f.b);
	printf("rgb ceilling : %d,", data->texture.c.r);
	printf("%d,", data->texture.c.g);
	printf("%d\n", data->texture.c.b);
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;


	int	fd = open("maps/test.cub", O_RDONLY);
	parse_launch(fd);
	print_struct();
	return (0);
}
