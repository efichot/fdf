/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:45:32 by efichot           #+#    #+#             */
/*   Updated: 2016/12/03 15:42:07 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		mouse_hook(int button, int x, int y, t_env *e)
{
	x = x;
	y = y;
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
