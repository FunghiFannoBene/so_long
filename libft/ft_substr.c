/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 23:23:33 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/25 03:20:37 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*alloc;
	size_t	i;
	char	*result;

	alloc = (char *)malloc(sizeof(*s) * len + 1);
	result = alloc;
	i = 0;
	while (s[start] && i < len && start < ft_strlen(s))
	{
		*alloc = s[start];
		i++;
		alloc++;
		start++;
	}
	*alloc = '\0';
	if (alloc == NULL)
	{
		return (NULL);
	}
	return (result);
}
