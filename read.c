/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:15:53 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 19:51:34 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	parse(char *str, int x, t_env **current, int index)
{
	int k;

	k = 0;
	if (!((*current)->map[index] = (int *)malloc(sizeof(int) * x)))
		exit(1);
	while (*str)
	{
		if (ft_isdigit(str[0]) && k <= x)
		{
			(*current)->map[index][k] = str[0] - '0';
			k++;
		}
		str++;
	}
	(*current)->map[index][17] = 1;
	(*current)->map[index][0] = 1;
}

int		ft_initread(char *str, t_env *current)
{
	int		fd;
	char	*line;
	int		index;

	index = 0;
	line = NULL;
	if ((fd = open(str, O_RDONLY)) == -1)
	{
		ft_putendl("ERROR");
		exit(1);
	}
	if (!(current->map = (int **)malloc(sizeof(int *) * HEIGHT_MAP)))
		exit(1);
	while (get_next_line(fd, &line) == 1)
	{
		parse(line, WIDTH_MAP, &current, index);
		free(line);
		index++;
	}
	close(fd);
	return (0);
}
