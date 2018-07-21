/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 20:04:41 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 21:02:49 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	keydowntwo(int keycode, t_env *e)
{
	if (keycode == 2)
	{
		e->ray->olddirx = e->ray->dirx;
		e->ray->dirx = e->ray->dirx * cos(-.04) - e->ray->diry * sin(-.04);
		e->ray->diry = e->ray->olddirx * sin(-.04) + e->ray->diry * cos(-.04);
		e->ray->oldplanex = e->ray->planex;
		e->ray->planex = NEW_PLNX_COS(-.04) - e->ray->planey * sin(-.04);
		e->ray->planey = OLD_PLNX_SIN(-0.04) + e->ray->planey * cos(-.04);
	}
	else if (keycode == 0)
	{
		e->ray->olddirx = e->ray->dirx;
		e->ray->dirx = e->ray->dirx * cos(0.04) - e->ray->diry * sin(0.04);
		e->ray->diry = e->ray->olddirx * sin(0.04) + e->ray->diry * cos(.04);
		e->ray->oldplanex = e->ray->planex;
		e->ray->planex = NEW_PLNX_COS(0.04) - e->ray->planey * sin(0.04);
		e->ray->planey = OLD_PLNX_SIN(0.04) + e->ray->planey * cos(0.04);
	}
	draw(e);
	return (0);
}

int	keydown(int keycode, t_env *all)
{
	t_env *e;

	e = all;
	// printf("%d\n", keycode);
	if (keycode == 53)
		exit(1);
	if (keycode == 13)
	{
		if (e->map[(int)(e->ray->posy)][POSXDIRX] == 0)
			e->ray->posx += e->ray->dirx * 0.06;
		if (e->map[POSYDIRY][(int)e->ray->posx] == 0)
			e->ray->posy += e->ray->diry * 0.06;
	}
	else if (keycode == 1)
	{
		if (e->map[(int)(e->ray->posy)][POSXDIRX] == 0)
			e->ray->posx -= e->ray->dirx * 0.06;
		if (e->map[POSYDIRY][(int)e->ray->posx] == 0)
			e->ray->posy -= e->ray->diry * 0.06;
	}
	keydowntwo(keycode, e);
	return (0);
}
