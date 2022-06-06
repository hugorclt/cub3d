/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 19:16:03 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_map(char **argv)
{
	t_data	*data;

	data = _data();
	data->map.fd = open(argv[1], O_RDONLY);
	if (data->map.fd < 0)
		hasta_la_vista_baby("open fail");
	
}



int	main(int argc, char **argv)
{
	t_data	*data;

	data = _data();
	parsing(argc, argv);
	hasta_la_vista_baby(NULL);
	return (SUCCESS);
}
