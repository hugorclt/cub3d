/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/05 19:15:59 by hrecolet         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_data	*data;

	data = _data();
	return (0);
}
