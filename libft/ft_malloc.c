/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjosmyn <qjosmyn@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 17:58:50 by qjosmyn           #+#    #+#             */
/*   Updated: 2020/10/14 18:01:55 by qjosmyn          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*tmp;

	if ((tmp = malloc(size)) == NULL)
	{
		ft_putstr("Error: malloc error\n");
		exit(EXIT_FAILURE);
	}
	return (tmp);
}