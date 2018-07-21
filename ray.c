/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:11:44 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 20:08:46 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_start_end(t_ray **ray)
{
	if ((*ray)->side == 0)
		(*ray)->perpwalldist = (WALL_DST_X) / (*ray)->raydirx;
	else
		(*ray)->perpwalldist = (WALL_DST_Y) / (*ray)->raydiry;
	(*ray)->lineheight = (int)(HEIGHT / (*ray)->perpwalldist);
	(*ray)->drawstart = -(*ray)->lineheight / 2 + HEIGHT / 2;
	if ((*ray)->drawstart < 0)
		(*ray)->drawstart = 0;
	(*ray)->drawend = (*ray)->lineheight / 2 + HEIGHT / 2;
	if ((*ray)->drawend >= HEIGHT)
		(*ray)->drawend = HEIGHT - 1;
	(*ray)->color = 0xFF7B7B;
}

void	ray_side_dist(t_ray **ray)
{
	if (DSTXDSTY && ((*ray)->sidedistx += (*ray)->deltadistx))
	{
		(*ray)->mapx += (*ray)->stepx;
		(*ray)->side = 0;
	}
	else if (((*ray)->sidedisty += (*ray)->deltadisty))
	{
		(*ray)->mapy += (*ray)->stepy;
		(*ray)->side = 1;
	}
}

void	draw_all(t_env *all)
{
	t_env	*current;
	t_ray	*ray;
	int		x;

	// printf("draw_all\n");
	current = all;
	ray = current->ray;
	x = -1;
	while (x++ != WIDTH)
	{
		start_ray(&ray, x);
		// printf("draw_all 1\n");
		while (ray->hit == 0)
		{
			// printf("draw_all 2\n");
			ray_side_dist(&ray);
			// printf("draw_all 3\n");
			if ((current->x_max < ray->mapx || ray->mapx < 0 ||
				ray->mapy < 0 || current->y_max < ray->mapy) && (ray->hit = 1))
				break ;
			// printf("draw_all 4\n");
			if (current->map[ray->mapy][ray->mapx] > 0)
				ray->hit = 1;
		}
		// printf("draw_all 5\n");
		draw_start_end(&ray);
		// printf("draw_all 6\n");
		draw_vert(x, ray->drawstart, ray->drawend, current);
		// printf("draw_all 7\n");
	}
	// printf("draw_all end\n");
}

void	ft_sky(t_env *all)
{
	int		x;
	t_env	*current;

	x = 0;
	current = all;
	while (x != WIDTH)
	{
		all->ray->color = 0x000b7E;
		draw_vert(x, HEIGHT / 2, HEIGHT, current);
		all->ray->color = 0xBD7BFF;
		draw_vert(x, 0, HEIGHT / 2, current);
		x++;
	}
}

int		draw(t_env *current)
{
	// printf("here\n");
	mlx_clear_window(current->mlx->mlx, current->mlx->window);
	// printf("here1\n");
	ft_sky(current);
	// printf("here2\n");
	draw_all(current);
	// printf("here3\n");
	mlx_put_image_to_window(current->mlx->mlx,
		current->mlx->window, current->mlx->image, 0, 0);
	// printf("here4\n");
	return (1);
}
