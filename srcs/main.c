/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 17:58:55 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/17 16:33:40 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	(void) argc;
	parsing(argv);
	check_map();
	video_loop();
	hasta_la_vista_baby(NULL);
	return (SUCCESS);
}
