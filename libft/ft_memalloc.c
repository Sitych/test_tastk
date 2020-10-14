/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:59:28 by snorcros          #+#    #+#             */
/*   Updated: 2020/10/14 18:06:45 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ans;

	ans = malloc(sizeof(char) * size);
	if (!ans)
		return (NULL);
	ft_bzero(ans, size);
	return (ans);
}
