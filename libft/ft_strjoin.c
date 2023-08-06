/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 21:12:50 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/25 03:18:57 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*concat;
	char	*result;

	concat = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	result = concat;
	while (*s1 != '\0')
	{
		*concat = *s1;
		s1++;
		concat++;
	}
	while (*s2 != '\0')
	{
		*concat = *s2;
		s2++;
		concat++;
	}
	*concat = '\0';
	if (result == NULL)
		return (NULL);
	return (result);
}
