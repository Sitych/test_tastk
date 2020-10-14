/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 19:12:00 by snorcros          #+#    #+#             */
/*   Updated: 2020/10/14 17:58:27 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ans;
	int		len;

	len = ft_strlen(src);
	ans = (char*)ft_memalloc(sizeof(char) * (len + 1));
	if (ans == NULL)
		return (0);
	ans = ft_strcpy(ans, src);
	return (ans);
}
