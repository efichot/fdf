/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:05:26 by efichot           #+#    #+#             */
/*   Updated: 2016/11/09 14:10:13 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_listfold(t_list *lst, void *(*f)(void *, void *))
{
	t_list	*list;
	void	*res;

	list = lst;
	res = list->content;
	list = list->next;
	while (list)
	{
		res = f(res, list->content);
		list = list->next;
	}
	return (res);
}
