/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:17:03 by efichot           #+#    #+#             */
/*   Updated: 2016/11/09 14:30:58 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrmap(char **arr, char *(*f)(char *))
{
	int		i;
	char	**ret;

	if (!arr || !f)
		return (NULL);
	ret = ft_arrnew((size_t)ft_arrsize(arr));
	i = 0;
	while (ret[i])
	{
		ret[i] = ft_strdup(f(arr[i]));
		i++;
	}
	return (ret);
}
