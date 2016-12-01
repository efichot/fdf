/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:31:03 by efichot           #+#    #+#             */
/*   Updated: 2016/11/09 14:30:05 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arradd(char ***arr, char *str)
{
	char	**tmp;
	char	**new;
	int		i;

	if (!arr && !str)
		return (0);
	tmp = *arr;
	new = (!arr) ? ft_arrnew(1) : ft_arrnew((size_t)ft_arrsize(*arr) + 1);
	if (!new)
		return (0);
	i = 0;
	if (tmp)
	{
		while (tmp[i])
		{
			new[i] = tmp[i];
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
	new[i] = str;
	*arr = new;
	return (1);
}
