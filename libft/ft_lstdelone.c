/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:12:39 by efichot           #+#    #+#             */
/*   Updated: 2016/11/07 15:54:00 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **begin_list, void (*del)(void *, size_t))
{
	t_list	*list;

	list = *begin_list;
	del(list->content, list->content_size);
	free(list);
	*begin_list = NULL;
}
