/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:45:32 by efichot           #+#    #+#             */
/*   Updated: 2016/12/06 18:06:31 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		ft_color_bis(int coef)
{
	coef = -coef * 2;
	if (coef < -3 * 255)
		return (0x0000FF);
	else if (coef < -2 * 255 && coef >= -3 * 255)
		return (0x00FFFF - (coef * -1 - 2 * 255) * 256);
	else if (coef < -1 * 255 && coef >= -2 * 255)
		return (0x00FF00 + (coef * -1 - 1 * 255));
	else if (coef < 0 && coef >= -1 * 255)
		return (0xFF0000 + (coef) * 256 * 256);
	else if (coef < 1 * 256 && coef >= 0)
		return (0xFFFF00 - 256 * coef);
	else if (coef < 2 * 256 && coef >= 1 * 256)
		return (0xFF0000 + coef - 256);
	else if (coef < 3 * 256 && coef >= 2 * 256)
		return (0xFF00FF + (coef - 2 * 256) * 256);
	else
		return (0xFFFFFF);
}

int		ft_color(int i, int k, t_env *e, int j)
{
	int		color;
	int		dx;
	int		dy;

	dx = (e->tab_ori[k]).x - (e->tab_ori[i]).x;
	dy = (e->tab_ori[k]).y - (e->tab_ori[i]).y;
	dx = (dx >= 0) ? dx : -dx;
	dy = (dy >= 0) ? dy : -dy;
	color = (e->tab_ori[i].z != 0 ? HIGHT_COLOR + e->cb : BASE_COLOR + e->cb);
	if (dx >= dy)
		color += ft_color_bis(e->tab_ori[i].z + j * (e->tab_ori[k].z
			- e->tab_ori[i].z) / (dx));
	else
		color += ft_color_bis(e->tab_ori[i].z + j * (e->tab_ori[k].z
			- e->tab_ori[i].z) / (dy));
	return (color);
}

int		ft_put_pixel(t_env *e, int x, int y, int color)
{
	mlx_pixel_put(e->mlx, e->win, x + e->move_x,
		y + e->move_y, color);
	return (1);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4)
	{
		e->zoom = ((e->zoom * 0.8) < 0.1 ? 0.12 : e->zoom * 0.8);
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	if (button == 5)
	{
		e->zoom = (e->zoom + 0.2) > 10 ? 9.8 : e->zoom + 0.2;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	return (1);
}
