/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 12:00:41 by efichot           #+#    #+#             */
/*   Updated: 2016/12/01 12:03:22 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env	*init_env(void)
{
	t_env	*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(*e))))
		return (NULL);
	// if (!(e->mlx = mlx_init()))
	// {
 // 		ft_putstr_fd("Error minilibx init\n", 2);
	// 	return (NULL);
	// }
	e->w = 1000;
	e->h = 1000;
	// if (!(e->win = mlx_new_window(e->mlx, e->w, e->h, "mlx_efichot")))
	// 	return (NULL);
	return (e);
}

int		read_option(int ac, char **av)
{
	if (ac == 2)
		return (1);
	ft_putstr_fd("usage : fdf input_file\n", 2);
	return (0);
}

/*void	ft_draw(t_env *e)
{
	int		y;
	int		x;

	while (y < e->y)
	{
		x = 0;
		while (x < e->x)
		{
			mlx_pixel_put(e->mlx, e->win, e->tab[]);
		}
		y++;
	}
}

int		expose_hook(t_env *e)
{
	ft_draw(e);
}
*/

void	ft_close(t_env *e)
{
	free(e);
	exit(0);
	return ;
}

int		key_hook(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		mlx_destroy_window(e->mlx, e->win);
		ft_close(e);
	}
	ft_putnbr(keycode);
	return (1);
}

int		mouse_hook(int button, int x ,int y, t_env *e)
{
	ft_putstr("button: ");
	ft_putnbr(button);
	ft_putchar('\n');
	ft_putstr("x: ");
	ft_putnbr(x);
	ft_putchar('\n');
	ft_putstr("y: ");
	ft_putnbr(y);
	ft_putchar('\n');
	return (1);
}

int		*ft_atoi_line(char *line, t_env *e)
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
	if (e->x)
	{
		if (e->x != i)
			return (NULL);
	}
	e->x = i;
	if (!(tab_line = (int *)ft_memalloc(sizeof(*tab_line) * i)))
		return (NULL);
	i = 0;
	while (nb[i])
	{
		tab_line[i] = ft_atoi(nb[i]);
		i++;
	}
	ft_putnbr(i);
	ft_putchar(' ');
	return (tab_line);
}

int		ft_read(int fd, char **file)
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
		*file = tmp;
		ft_strdel(&tmp);
	}
	if (ret == -1)
		return (0);
	return (1);
}

t_coor		*ft_put_in_struct(int **tab_int, t_env *e)
{
	t_coor	*tab;
	int		nb_case;
	int		i;
	int		j;
	int		k;

	nb_case = (e->x) * (e->y);
	e->nb_case = nb_case;
	ft_putnbr(nb_case);
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
			tab[k].z = (e->tab_int)[i][j];
			ft_putnbr(k);
			ft_putstr(" = ");
			ft_putnbr(tab[k].z);
			ft_putchar(' ');
			k++;
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (tab);
}

t_coor		*ft_put_in_tab(char *file, t_env *e)
{
	int		line;
	char	**tab_line;
	int		nb_line;
	int		**tab_int;
	int		i;

	if (!(tab_line = ft_strsplit(file, '\n')))
		return (NULL);
	nb_line = 0;
	while (tab_line[nb_line])
		nb_line++;
	if (!(tab_int = (int **)malloc(sizeof(*tab_int) * nb_line)))
		return (NULL);
	e->y = nb_line;
	i = 0;
	while (i < nb_line)
	{
		tab_int[i] = ft_atoi_line(tab_line[i], e);
		i++;
	}
	e->tab_int = tab_int;
	int k;
	int j;

	k = 0;
	while (k < e->y)
	{
		j = 0;
		while (j < e->x)
		{
			ft_putnbr(e->tab_int[k][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		k++;
	}
	return (ft_put_in_struct(tab_int, e));
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		fd;
	char	*file;

	if (!(read_option(ac, av)))
		return (0);
	if (!(e = init_env()))
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0)
	{
		perror(av[1]);
		return (0);
	}
	if (!(ft_read(fd, &file)))
	{
		perror(av[1]);
		return (0);
	}
	if (!(e->tab = ft_put_in_tab(file, e)))
	{
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("Incorrect value in file\n", 2);
		return (0);
	}
	int i;

	i = 0;
	while (i < e->nb_case)
	{
		ft_putnbr(i);
		ft_putstr(": ");
		ft_putnbr(e->tab[i].x);
		ft_putchar(',');
		ft_putnbr(e->tab[i].y);
		ft_putchar(',');
		ft_putnbr(e->tab[i].z);
		ft_putchar('\n');
		i++;
	}
	//mlx_expose_hook(e->win, expose_hook, e);
	// mlx_key_hook(e->win, key_hook, e);
	// mlx_mouse_hook(e->win, mouse_hook, e);
	// mlx_loop(e->mlx);
	return (1);
}
