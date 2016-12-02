/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:56:19 by efichot           #+#    #+#             */
/*   Updated: 2016/12/02 19:05:11 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <mlx.h>

# define BUFF_SIZE 4096
# define CONSTX 0.7
# define CONSTY 0.7
# define CONST 0.5

typedef struct	s_coor
{
	int			x;
	int			y;
	int			z;
}				t_coor;

typedef struct	s_calc
{
	int			dx;
	int			dy;
	int			xinc;
	int			yinc;
	int			cumul;
}				t_calc;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			w;
	int			h;
	int			x;
	int			y;
	int			**tab_int;
	t_coor		*tab_ori;
	t_coor		*tab;
	int			nb_case;
	int			move_x;
	int			move_y;
	float		zoom;
	int			iso;
}				t_env;

t_env	*init_env(void);
int		read_option(int ac);
void	ft_draw(t_env *e);
int		expose_hook(t_env *e);
void	ft_close(t_env *e);
int		key_hook(int keycode, t_env *e);
int		mouse_hook(int button, int x ,int y, t_env *e);
int		*ft_atoi_line(char *line, t_env *e);
int		ft_read(int fd, char **file);
t_coor		*ft_put_in_struct(t_env *e);
void		ft_verif_value(t_env *e);
t_coor		*ft_put_in_tab_struct(char **file, t_env *e);
t_coor		*ft_init_coor_par(t_env *e);
t_coor		*ft_init_coor_iso(t_env *e);
void		ft_set_coord(int *x, int *start, int nb1, int nb2);
void	ft_draw_lines(t_env *e);
void	ft_draw_pixels(t_env *e);
void	ft_draw_line(t_env *e, int i, int k);

#endif
