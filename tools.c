/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 00:31:51 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 21:43:10 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	start_ray(t_ray **ray, int x)
{
	(*ray)->camerax = 2 * x / (double)(WIDTH) - 1;
	(*ray)->raydirx = (*ray)->dirx + (*ray)->planex * (*ray)->camerax;
	(*ray)->raydiry = (*ray)->diry + (*ray)->planey * (*ray)->camerax;
	(*ray)->mapx = (int)(*ray)->posx;
	(*ray)->mapy = (int)(*ray)->posy;
	(*ray)->deltadistx = fabs(1 / (*ray)->raydirx);
	(*ray)->deltadisty = fabs(1 / (*ray)->raydiry);
	(*ray)->hit = 0;
	if ((*ray)->raydirx < 0 && ((*ray)->stepx = -1))
		(*ray)->sidedistx = (POSXMAPX) * (*ray)->deltadistx;
	else if (((*ray)->stepx = 1))
		(*ray)->sidedistx = (MAPXPOSX) * (*ray)->deltadistx;
	if ((*ray)->raydiry < 0 && ((*ray)->stepy = -1))
		(*ray)->sidedisty = (POSYMAPY) * (*ray)->deltadisty;
	else if (((*ray)->stepy = 1))
		(*ray)->sidedisty = (MAPYPOSX) * (*ray)->deltadisty;
}

void	pixel_put_img(t_env *j, int x, int y, int color)
{
	t_env	*e;
	int		hex;

	e = j;
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (x < WIDTH && y < HEIGHT)
	{
		hex = mlx_get_color_value(e->mlx->mlx, color);
		ft_memcpy(MLXPTR + 4 * WIDTH * y + x * 4, &color, sizeof(int));
	}
}

void	draw_vert(int x, int start, int end, t_env *all)
{
	// printf("%d %d\n", start, end);
	if (start < end)
	{
		while (start != end)
		{
			pixel_put_img(all, x, start, all->ray->color);
			start++;
		}
	}
	else
	{
		while (start != end)
		{
			pixel_put_img(all, x, start, all->ray->color);
			start--;
		}
	}
	// printf("out draw vert\n");
}
