/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:31:31 by efichot           #+#    #+#             */
/*   Updated: 2016/12/03 15:42:24 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_coor		*ft_init_coor_par(t_env *e)
{
	int		i;
	float	tmp;
	t_coor	*tab;

	if (!(tab = (t_coor*)ft_memalloc(sizeof(t_coor) * e->nb_case)))
		return (NULL);
	i = 0;
	while (i < e->nb_case)
	{
		tmp = 500 + ((e->tab_ori[i]).x * e->cx) * e->zoom + CONST *
		((e->tab_ori[i]).z * e->cz) * e->zoom;
		tab[i].x = (int)(tmp + 0.5);
		tmp = 300 + ((e->tab_ori[i]).y * e->cy) * e->zoom + (CONST / 2) *
		((e->tab_ori[i]).z * e->cz) * e->zoom;
		tab[i].y = (int)(tmp + 0.5);
		i++;
	}
	return (tab);
}

t_coor		*ft_init_coor_iso(t_env *e)
{
	int		i;
	float	tmp;
	t_coor	*tab;

	if (!(tab = (t_coor*)ft_memalloc(sizeof(t_coor) * e->nb_case)))
		return (NULL);
	i = 0;
	while (i < e->nb_case)
	{
		tmp = 900 + CONSTX * ((e->tab_ori[i]).x * e->cx) * e->zoom - CONSTY *
		((e->tab_ori[i]).y * e->cy) * e->zoom;
		tab[i].x = (int)(tmp + 0.5);
		tmp = 300 + ((e->tab_ori[i]).z * e->cz) * e->zoom + CONSTX / 2 *
		((e->tab_ori[i]).x * e->cx) * e->zoom + CONSTY / 2 *
		((e->tab_ori[i]).y * e->cy) * e->zoom;
		tab[i].y = (int)(tmp + 0.5);
		i++;
	}
	return (tab);
}
