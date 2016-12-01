/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:10:04 by efichot           #+#    #+#             */
/*   Updated: 2016/11/09 14:28:55 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(size_t size)
{
	char	**ret;

	if (!(ret = (char **)malloc(sizeof(*ret) * size + 1)))
		return (NULL);
	ret[size + 1] = 0;
	while (size)
		ret[size--] = NULL;
	return (ret);
}
