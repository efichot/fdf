/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_pixels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:53:26 by efichot           #+#    #+#             */
/*   Updated: 2016/12/06 17:39:46 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	ft_draw_pixels(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->nb_case)
	{
		ft_put_pixel(e, (e->tab[i]).x, (e->tab[i]).y, (e->tab[i]).z);
		i++;
	}
}

void	ft_draw_line_x(int i, int k, t_calc *calc, t_env *e)
{
	int		x;
	int		y;
	int		j;

	j = 1;
	x = e->tab[i].x;
	y = e->tab[i].y;
	calc->cumul = calc->dx / 2;
	while (j <= calc->dx)
	{
		x += calc->xinc;
		calc->cumul += calc->dy;
		if (calc->cumul >= calc->dx)
		{
			calc->cumul -= calc->dx;
			y += calc->yinc;
		}
		ft_put_pixel(e, x, y, ft_color(i, k, e, j));
		j++;
	}
}

void	ft_draw_line_y(int i, int k, t_calc *calc, t_env *e)
{
	int		x;
	int		y;
	int		j;

	j = 1;
	x = e->tab[i].x;
	y = e->tab[i].y;
	calc->cumul = calc->dy / 2;
	while (j <= calc->dy)
	{
		y += calc->yinc;
		calc->cumul += calc->dx;
		if (calc->cumul >= calc->dy)
		{
			calc->cumul -= calc->dy;
			x += calc->xinc;
		}
		ft_put_pixel(e, x, y, ft_color(i, k, e, j));
		j++;
	}
}

void	ft_draw_line(t_env *e, int i, int k)
{
	t_calc	*calc;

	if (!(calc = ft_memalloc(sizeof(t_calc))))
		return ;
	calc->dx = e->tab[k].x - e->tab[i].x;
	calc->dy = e->tab[k].y - e->tab[i].y;
	calc->xinc = (calc->dx >= 0) ? 1 : -1;
	calc->yinc = (calc->dy >= 0) ? 1 : -1;
	calc->dx = (calc->dx >= 0) ? calc->dx : -calc->dx;
	calc->dy = (calc->dy >= 0) ? calc->dy : -calc->dy;
	if (calc->dx >= calc->dy)
		ft_draw_line_x(i, k, calc, e);
	else
		ft_draw_line_y(i, k, calc, e);
	free(calc);
	calc = NULL;
}

void	ft_draw_lines(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_case)
	{
		if ((i + 1) % e->x != 0)
			ft_draw_line(e, i, i + 1);
		if (i < (e->y - 1) * e->x)
			ft_draw_line(e, i, i + e->x);
		i++;
	}
}
