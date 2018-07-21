/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 19:59:51 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 21:24:05 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	printmap(t_env *current)
{
	int y;
	int x;

	y = 0;
	while (y != HEIGHT_MAP)
	{
		x = 0;
		while (x != WIDTH_MAP)
		{
			ft_printf("%d ", current->map[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_env *e;

	if (argc != 2)
		exit(1);
	e = init_env();
	ft_initread(argv[1], e);
	printmap(e);
	draw(e);
	printf("finished drawing\n");
	mlx_hook(e->mlx->window, 2, 0, keydown, e);
	mlx_loop(e->mlx->mlx);
	return (0);
}
