/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:36:38 by efichot           #+#    #+#             */
/*   Updated: 2016/12/03 15:41:44 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_hook_5(int keycode, t_env *e)
{
	if (keycode == 69)
	{
		e->zoom = (e->zoom + 0.2) > 10 ? 9.8 : e->zoom + 0.2;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	if (keycode == 78)
	{
		e->zoom = ((e->zoom * 0.8) < 0.1 ? 0.12 : e->zoom * 0.8);
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	return (1);
}

int		key_hook_4(int keycode, t_env *e)
{
	if (keycode == 84)
	{
		e->cx = (e->cx > 30) ? e->cx - 1 : 31;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	if (keycode == 87)
	{
		e->cy = (e->cy > 30) ? e->cy - 1 : 31;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	return (1);
}

int		key_hook_3(int keycode, t_env *e)
{
	if (keycode == 126)
	{
		e->move_y = e->move_y - 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 67)
	{
		e->cz = (e->cz > -20) ? e->cz - 1 : -19;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	if (keycode == 123)
	{
		e->move_x = e->move_x - 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	return (1);
}

int		key_hook_2(int keycode, t_env *e)
{
	if (keycode == 124)
	{
		e->move_x = e->move_x + 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 125)
	{
		e->move_y = e->move_y + 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	if (keycode == 75)
	{
		e->cz = (e->cz < 20) ? e->cz + 1 : 19;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	return (1);
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_close(e);
	}
	if (keycode == 34)
	{
		mlx_clear_window(e->mlx, e->win);
		e->tab = ft_init_coor_iso(e);
		e->iso = 1;
		expose_hook(e);
	}
	if (keycode == 35)
	{
		mlx_clear_window(e->mlx, e->win);
		e->tab = ft_init_coor_par(e);
		e->iso = 0;
		expose_hook(e);
	}
	key_hook_2(keycode, e);
	key_hook_3(keycode, e);
	key_hook_4(keycode, e);
	key_hook_5(keycode, e);
	key_hook_6(keycode, e);
	return (1);
}
