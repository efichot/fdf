/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 14:56:45 by efichot           #+#    #+#             */
/*   Updated: 2016/12/03 16:20:43 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_env	*e;
	int		fd;
	char	*file;

	if (!(read_option(ac)) || !(e = init_env()))
		return (0);
	if ((fd = open(av[1], O_RDONLY)) < 0 || !(ft_read(fd, &file)))
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
