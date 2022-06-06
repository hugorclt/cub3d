/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 18:43:44 by ajung             #+#    #+#             */
/*   Updated: 2022/06/06 21:13:56 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
