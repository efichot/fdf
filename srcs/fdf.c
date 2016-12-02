#include "../includes/fdf.h"

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

void	ft_draw_pixels(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->nb_case)
	{
		mlx_pixel_put(e->mlx, e->win, (e->tab[i]).x + e->move_x, (e->tab[i]).y + e->move_y, 0xFFF3B8);
		i++;
	}
}

void	ft_draw_line(t_env *e, int i, int k)
{
	t_calc *calc;
	int x;
	int y;
	int j;

	j = 1;
	if (!(calc = ft_memalloc(sizeof(t_calc))))
		return ;
	calc->dx = e->tab[k].x - e->tab[i].x;
	calc->dy = e->tab[k].y - e->tab[i].y;
	calc->xinc = (calc->dx >= 0) ? 1 : -1;
	calc->yinc = (calc->dy >= 0) ? 1 : -1;
	calc->dx = (calc->dx >= 0) ? calc->dx : -calc->dx;
	calc->dy = (calc->dy >= 0) ? calc->dy : -calc->dy;
	x = e->tab[i].x;
	y = e->tab[i].y;
	if (calc->dx >= calc->dy)
	{
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
			mlx_pixel_put(e->mlx, e->win, x + e->move_x, y + e->move_y, 0xFFF3B8);
			j++;
		}
	}
	else
	{
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
			mlx_pixel_put(e->mlx, e->win, x + e->move_x, y + e->move_y, 0xFFF3B8);
			j++;
		}
	}
	free(calc);
	calc = NULL;
}

void ft_draw_lines(t_env *e)
{
	int i;

	i = 0;
	while (i < e->nb_case)
	{
		if ((i + 1) % e->x != 0)
		{
			ft_draw_line(e, i, i + 1);
		}
		if (i < (e->y - 1) * e->x)
		{
			ft_draw_line(e, i, i + e->x);
		}
		i++;
	}
}

int		expose_hook(t_env *e)
{
	ft_draw_pixels(e);
	ft_draw_lines(e);
	return (1);
}

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
		e->zoom = ((e->zoom * 0.8) < 0.4 ? 0.45 : e->zoom * 0.8);
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
	if (keycode == 126)
	{
		e->move_y = e->move_y - 30;
		mlx_clear_window(e->mlx, e->win);
		expose_hook(e);
	}
	return (1);
}

int		mouse_hook(int button, int x ,int y, t_env *e)
{
	e = e;
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
		tmp = 500 + ((e->tab_ori[i]).x * 50) * e->zoom + CONST * ((e->tab_ori[i]).z * 5) * e->zoom;
		tab[i].x = (int)(tmp + 0.5);
		tmp = 300 + ((e->tab_ori[i]).y * 50) * e->zoom + (CONST / 2) * ((e->tab_ori[i]).z * 5) * e->zoom;
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
		tmp = 900 + CONSTX * ((e->tab_ori[i]).x * 50) * e->zoom - CONSTY * ((e->tab_ori[i]).y * 50) * e->zoom;
		tab[i].x = (int)(tmp + 0.5);
		tmp = 300 + ((e->tab_ori[i]).z * -5) * e->zoom + CONSTX / 2 * ((e->tab_ori[i]).x * 50) * e->zoom + CONSTY / 2 * ((e->tab_ori[i]).y * 50) * e->zoom;
		tab[i].y = (int)(tmp + 0.5);
		i++;
	}
	return (tab);
}

int		main(int ac, char **av)
{
	t_env	*e;
	int		fd;
	char	*file;

	if (!(read_option(ac)))
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
	if (!(e->tab_ori = ft_put_in_tab_struct(&file, e)))
	{
		ft_putstr_fd(av[1], 2);
		ft_putstr_fd("Incorrect value in file.\n", 2);
		return (0);
	}
	e->tab = ft_init_coor_par(e);
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_expose_hook(e->win, expose_hook, e);
	mlx_loop(e->mlx);
	return (1);
}
