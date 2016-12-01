/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:09:00 by efichot           #+#    #+#             */
/*   Updated: 2016/11/07 17:37:06 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin_list, t_list *new)
{
	t_list	*list;

	if (!*begin_list)
		*begin_list = new;
	else
	{
		list = *begin_list;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
