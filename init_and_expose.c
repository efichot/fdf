/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_expose.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:51:45 by efichot           #+#    #+#             */
/*   Updated: 2016/12/06 18:17:35 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

t_env	*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(*e))))
		return (NULL);
	if (!(e->mlx = mlx_init()))
	{
		ft_putstr_fd("Error minilibx init\n", 2);
		return (NULL);
	}
	e->w = 2080;
	e->h = 1350;
	e->zoom = 1;
	e->cz = -3;
	e->cx = 50;
	e->cy = 50;
	if (!(e->win = mlx_new_window(e->mlx, e->w, e->h, "fdf")))
		return (NULL);
	return (e);
}

int		read_option(int ac)
{
	if (ac == 2)
		return (1);
	ft_putstr_fd("usage : fdf input_file\n", 2);
	return (0);
}

void	ft_write_order(t_env *e)
{
	mlx_string_put(e->mlx, e->win, 35, 35, TEXT_COLOR, "Quit = ESC");
	mlx_string_put(e->mlx, e->win, 35, 55, TEXT_COLOR, "Move = ^ v < >");
	mlx_string_put(e->mlx, e->win, 35, 75, TEXT_COLOR,
		"Zoom = + - or scrolling");
	mlx_string_put(e->mlx, e->win, 35, 95, TEXT_COLOR, "Isometric = i");
	mlx_string_put(e->mlx, e->win, 35, 115, TEXT_COLOR, "Parallel = p");
	mlx_string_put(e->mlx, e->win, 35, 135, TEXT_COLOR, "Increase z = *");
	mlx_string_put(e->mlx, e->win, 35, 155, TEXT_COLOR, "Decrease z = /");
	mlx_string_put(e->mlx, e->win, 35, 175, TEXT_COLOR, "Increase x = 1");
	mlx_string_put(e->mlx, e->win, 35, 195, TEXT_COLOR, "Decrease x = 2");
	mlx_string_put(e->mlx, e->win, 35, 215, TEXT_COLOR, "Increase z = 4");
	mlx_string_put(e->mlx, e->win, 35, 235, TEXT_COLOR, "Decrease z = 5");
	mlx_string_put(e->mlx, e->win, 35, 255, TEXT_COLOR, "Change color = .");
}

int		expose_hook(t_env *e)
{
	ft_draw_pixels(e);
	ft_draw_lines(e);
	ft_write_order(e);
	return (1);
}

void	ft_close(t_env *e)
{
	free(e);
	exit(0);
	return ;
}
