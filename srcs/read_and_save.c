/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:34:37 by efichot           #+#    #+#             */
/*   Updated: 2016/12/03 15:42:18 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			*ft_atoi_line(char *line, t_env *e)
{
	char	**nb;
	int		*tab_line;
	int		i;
	int		j;

	if (!(nb = ft_strsplit(line, ' ')))
		return (NULL);
	i = 0;
	while (nb[i])
		i++;
	e->x = i;
	if (!(tab_line = (int *)ft_memalloc(sizeof(*tab_line) * e->x)))
		return (NULL);
	i = 0;
	while (i < e->x)
	{
		tab_line[i] = ft_atoi(nb[i]);
		i++;
	}
	return (tab_line);
}

int			ft_read(int fd, char **file)
{
	int		**tab;
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	*file = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(*file, buf);
		ft_strdel(file);
		*file = ft_strdup(tmp);
		ft_strdel(&tmp);
	}
	if (ret == -1)
		return (0);
	return (1);
}

t_coor		*ft_put_in_struct(t_env *e)
{
	t_coor	*tab;
	int		nb_case;
	int		i;
	int		j;
	int		k;

	nb_case = (e->x) * (e->y);
	e->nb_case = nb_case;
	tab = (t_coor *)ft_memalloc(sizeof(t_coor) * e->nb_case);
	i = 0;
	k = 0;
	while (i < e->y)
	{
		j = 0;
		while (j < e->x)
		{
			tab[k].x = j;
			tab[k].y = i;
			tab[k].z = e->tab_int[i][j];
			k++;
			j++;
		}
		i++;
	}
	return (tab);
}

void		ft_verif_value(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < e->y)
	{
		j = 0;
		while (j < e->x)
		{
			if (e->tab_int[i][j] > 1000 || e->tab_int[i][j] < -1000)
			{
				ft_putstr_fd("Incorrect value in file.\n", 2);
				ft_close(e);
			}
			j++;
		}
		i++;
	}
}

t_coor		*ft_put_in_tab_struct(char **file, t_env *e)
{
	int		line;
	char	**tab_line;
	int		nb_line;
	int		**tab_int;
	int		i;

	if (!(tab_line = ft_strsplit(*file, '\n')))
		return (NULL);
	ft_strdel(file);
	nb_line = 0;
	while (tab_line[nb_line])
		nb_line++;
	e->y = nb_line;
	if (!(tab_int = (int **)ft_memalloc(sizeof(*tab_int) * e->y)))
		return (NULL);
	i = 0;
	while (i < e->y)
	{
		tab_int[i] = ft_atoi_line(tab_line[i], e);
		i++;
	}
	e->tab_int = tab_int;
	ft_verif_value(e);
	return (ft_put_in_struct(e));
}
