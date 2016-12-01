/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efichot <efichot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:39:28 by efichot           #+#    #+#             */
/*   Updated: 2016/11/05 17:08:44 by efichot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	if (!s[i])
		return (ft_strsub(s, i, 0));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if (!i && j == ft_strlen(s) - 1)
		return (ft_strdup(s));
	len = j - i;
	return (ft_strsub(s, i, len + 1));
}
