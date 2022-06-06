/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/06 21:05:54 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	main(int argc, char **argv)
{
	parsing(argc, argv);
	print_struct();
	hasta_la_vista_baby(NULL);
	return (SUCCESS);
}
