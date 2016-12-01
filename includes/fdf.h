/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:56:19 by efichot           #+#    #+#             */
/*   Updated: 2016/12/01 11:09:13 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./../libft/includes/libft.h"
# include "./../libft/includes/get_next_line.h"
# include <stdio.h>
# include <mlx.h>

# define BUFF_SIZE 4096

typedef struct	s_coor
{
	int			x;
	int			y;
	int			z;
}				t_coor;

typedef	struct	s_env
{
	void		*mlx;
	void		*win;
	int			w;
	int			h;
	int			x;
	int			y;
	int			**tab_int;
	t_coor		*tab;
	int			nb_case;
}				t_env;

#endif
