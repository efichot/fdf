/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arriteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:21:18 by efichot           #+#    #+#             */
/*   Updated: 2016/11/09 11:27:20 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arriteri(char **arr, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (arr && f)
	{
		while (arr[i])
		{
			f(i, arr[i]);
			i++;
		}
	}
}
