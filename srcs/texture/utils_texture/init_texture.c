/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:23:05 by ajung             #+#    #+#             */
/*   Updated: 2022/06/17 21:43:27 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_wall_x(void)
{
	t_ray		*ray;
	t_player	*player;

	ray = _ray();
	player = _player();
	if (ray->side == NORTH_SOUTH)
		ray->wall_x = player->pos.y + (ray->wall_dist * ray->dir.y);
	else
		ray->wall_x = player->pos.x + (ray->wall_dist * ray->dir.x);
	ray->wall_x -= floor(ray->wall_x);
}

void	calculate_texture_x(void)
{
	t_texture	*tex;
	t_ray		*ray;

	tex = _tex();
	ray = _ray();
	tex->tex_x = (int)(ray->wall_x *
		(double)tex->img[ray->side_hit].width);
	if (ray->side == NORTH_SOUTH && ray->dir.x > 0)
		tex->tex_x = tex->img[tex->side_hit].width - tex->tex_x - 1;
	if (ray->side == WEST_EAST && ray->dir.y < 0)
		tex->tex_x = tex->img[tex->side_hit].width - tex->tex_x - 1;
}

void	init_side_hit_in_texture(void)
{
	t_ray		*ray;
	t_texture	*texture;

	ray = _ray();
	texture = _tex();

	texture->side_hit = ray->side_hit;
}

void	calculate_step_texture(void)
{
	t_texture	*tex;

	tex = _tex();
	tex->step = 1.0 *
		tex->img[tex->side_hit].width / tex->img[tex->side_hit].height;
}

void	calculate_texture_coor(void)
{
	
}

/* 
            // How much to increase the texture coordinate per screen pixel
      double step = 1.0 * texHeight / lineHeight;
      // Starting texture coordinate
      double texPos = (drawStart - h / 2 + lineHeight / 2) * step; */



/* 	  
      for(int y = drawStart; y<drawEnd; y++)
      {
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
        int texY = (int)texPos & (texHeight - 1);
        texPos += step;
        Uint32 color = texture[texNum][texHeight * texY + texX];
        //make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
        if(side == 1) color = (color >> 1) & 8355711;
        buffer[y][x] = color;
      }
    } */


void	init_texture(void)
{
	t_mlx		*mlx;
	t_texture	*tex;
	int			i;

	mlx = _mlx();
	tex = _tex();
	tex->img = malloc(sizeof(t_image) * 4);
	if (!tex->img)
		hasta_la_vista_baby("Memorry alloc");
	ft_bzero(tex->img, sizeof(t_image) * 4);
	i = 0;
	while (i < 4)
	{
		printf("path north = %s\n", tex->path.north);
		tex->img[i].img_ptr = mlx_xpm_file_to_image(mlx->var.mlx,
			tex->path.north, &tex->img[i].width, &tex->img[i].height);
		if (!tex->img[i].img_ptr) // on casse ici
			hasta_la_vista_baby("mlx fail test1");
		tex->img[i].addr = mlx_get_data_addr(tex->img[i].img_ptr,
			&tex->img[i].bits_per_pixel, NULL, &tex->img[i].endian);
		if (!tex->img[i].img_ptr)
			hasta_la_vista_baby("mlx fail test2");
		i++;
	}
}
