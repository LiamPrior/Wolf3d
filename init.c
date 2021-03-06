/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:03:53 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 22:45:45 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_events	*init_events(void)
{
	t_events	*e;

	e = (t_events *)malloc(sizeof(t_events));
	e->w = 0;
	e->a = 0;
	e->s = 0;
	e->d = 0;
	return (e);
}

t_ray		*init_ray(void)
{
	t_ray	*e;

	if (!(e = (t_ray *)malloc(sizeof(t_ray))))
	{
		ft_putendl("Ray wasn't initated correctly");
		exit(1);
	}
	e->dirx = -1.0;
	e->diry = 0.0;
	e->planex = 0;
	e->planey = 2 * (atan(0.50 / 1.0));
	return (e);
}

t_env		*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		exit(1);
	if (!(e->player = (t_player *)malloc(sizeof(t_player))))
		exit(1);
	if (!(e->mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		exit(1);
	if ((e->mlx->mlx = mlx_init()) == NULL)
		exit(1);
	e->mlx->window = mlx_new_window(e->mlx->mlx, WIDTH, HEIGHT, "Wolf3d");
	e->mlx->image = mlx_new_image(e->mlx->mlx, WIDTH, HEIGHT);
	e->mlx->image_ptr = mlx_get_data_addr(e->mlx->image,
		&(e->mlx->bpp), &(e->mlx->sl), &(e->mlx->endian));
	e->ray = init_ray();
	e->events = init_events();
	e->player->x = 5;
	e->player->y = 5;
	e->ray->posx = e->player->x;
	e->ray->posy = e->player->y;
	e->x_max = 689180108;
	e->y_max = 689180108;
	return (e);
}