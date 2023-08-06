/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 23:21:17 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/16 23:13:52 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	size;

	size = ft_strlen(s) + 1;
	new = (char *)malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	else
		return ((char *)ft_memcpy(new, s, size));
}
//