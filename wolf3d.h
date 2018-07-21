/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lprior <lprior@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:08:10 by pdavid            #+#    #+#             */
/*   Updated: 2018/07/20 20:31:06 by lprior           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define HEIGHT 800
# define WIDTH 800
# define HEIGHT_MAP 18
# define WIDTH_MAP 20
# define POSXDIRX (int)(e->ray->posx + e->ray->dirx * 0.06)
# define POSYDIRY (int)(e->ray->posy + e->ray->diry * 0.06)
# define NEW_PLNX_COS e->ray->planex * cos
# define OLD_PLNX_SIN e->ray->oldplanex * sin
# define WALL_DST_X (*ray)->mapx - (*ray)->posx + (1 - (*ray)->stepx) / 2
# define WALL_DST_Y (*ray)->mapy - (*ray)->posy + (1 - (*ray)->stepy) / 2
# define DSTXDSTY (*ray)->sidedistx < (*ray)->sidedisty
# define POSXMAPX (*ray)->posx - (*ray)->mapx
# define MAPXPOSX (*ray)->mapx + 1.0 - (*ray)->posx
# define POSYMAPY (*ray)->posy - (*ray)->mapy
# define MAPYPOSX (*ray)->mapy + 1.0 - (*ray)->posy
# define MLXPTR e->mlx->image_ptr

# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <stdlib.h>
# include <fcntl.h>
# include "math.h"

typedef struct		s_events
{
	int				w;
	int				a;
	int				s;
	int				d;
}					t_events;

typedef	struct		s_mlx
{
	void			*mlx;
	void			*image;
	void			*image_ptr;
	void			*window;
	int				endian;
	int				sl;
	int				bpp;
}					t_mlx;

typedef	struct		s_player
{
	double			x;
	double			y;
	double			viewangle;
}					t_player;

typedef struct		s_ray
{
	double			planex;
	double			planey;
	double			posx;
	double			posy;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			dirx;
	double			diry;
	double			olddirx;
	double			oldplanex;
	double			camerax;
	double			raydirx;
	double			raydiry;
	double			deltadistx;
	double			deltadisty;
	double			perpwalldist;
	int				stepx;
	int				stepy;
	int				side;
	int				hit;
	double			time;
	double			oldtime;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				color;
	double			frametime;
}					t_ray;

typedef	struct		s_env
{
	t_player		*player;
	t_ray			*ray;
	t_mlx			*mlx;
	t_events		*events;
	int				**map;
	int				x_max;
	int				y_max;
}					t_env;

int					keydown(int	keycode, t_env *all);
int					keydowntwo(int keycode, t_env *e);
int					ft_initread(char *str, t_env *all);
int					ft_reopen(char *str, int y, t_env *all);
int					ft_countnum(char *str);
// int					*parse(char *str, int x);
void				parse(char *str, int x, t_env **current, int index);
void				start_ray(t_ray **ray, int x);
void				ft_sky(t_env *all);
int					draw(t_env *all);
void				ft_exit(t_env *all);
void				draw_vert(int x, int start, int end, t_env *all);
t_env				*init_env(void);
t_events			*init_events(void);
t_ray				*init_ray(void);

#endif
