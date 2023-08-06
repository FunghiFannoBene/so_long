/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 20:24:21 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/24 20:15:51 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*puntdst;
	char	*puntsrc;

	i = 0;
	puntdst = (char *)dst;
	puntsrc = (char *)src;
	if ((puntdst != NULL) && (puntsrc != NULL))
	{
		while (i < n)
		{
			puntdst[i] = puntsrc[i];
			i++;
		}
	}
	return (dst);
}
