/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:57:11 by efichot           #+#    #+#             */
/*   Updated: 2016/11/07 16:02:27 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **begin_list, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	list = *begin_list;
	while (list)
	{
		tmp = list;
		del(list->content, list->content_size);
		free(list);
		list = tmp->next;
	}
	*begin_list = NULL;
}
