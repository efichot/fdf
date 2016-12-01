/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitlst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:11:50 by efichot           #+#    #+#             */
/*   Updated: 2016/11/09 14:25:06 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_strplitlst(char *str, char c)
{
	int		i;
	char	word[64];
	int		j;
	t_list	*new;
	t_list	*list;

	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		j = 0;
		while (str[i] != c && str[i])
		{
			word[j++] = str[i++];
		}
		word[j] = '\0';
		new = ft_lstnew(word, ft_strlen(word) + 1);
		ft_lstpushback(&list, new);
		free(new);
	}
	return (list);
}
