/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 19:16:50 by lprior            #+#    #+#             */
/*   Updated: 2018/02/18 01:20:36 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_putchar(char c, int *res)
{
	(*res)++;
	write(1, &c, 1);
}
