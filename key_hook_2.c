/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:47:20 by efichot           #+#    #+#             */
/*   Updated: 2016/12/06 18:15:36 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		key_hook_6(int keycode, t_env *e)
{
	if (keycode == 83)
	{
		e->cx = (e->cx < 70) ? e->cx + 1 : 69;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	if (keycode == 86)
	{
		e->cy = (e->cy < 70) ? e->cy + 1 : 69;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	key_hook_7(keycode, e);
	return (1);
}

int		key_hook_7(int keycode, t_env *e)
{
	if (keycode == 65)
	{
		e->cb = (e->cb < 1000) ? e->cb + 10 : 0;
		mlx_clear_window(e->mlx, e->win);
		if (e->iso)
			e->tab = ft_init_coor_iso(e);
		else
			e->tab = ft_init_coor_par(e);
		expose_hook(e);
	}
	return (1);
}
