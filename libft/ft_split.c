/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 01:21:57 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/25 01:36:11 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nstr(const char *s, char c)
{
	size_t	ogni;

	ogni = 0;
	if (*s != c)
		ogni++;
	while (*s)
	{
		if ((*(s + 1) == c && *s != c))
			ogni++;
		s++;
	}
	return (ogni);
}

size_t	checksizesub(const char *s, char c)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		a++;
		i++;
	}
	return (a);
}

char	**ft_split(char *s, char c)
{
	size_t	y;
	size_t	x;
	size_t	i;
	char	**result;

	y = 0;
	i = 0;
	x = 0;
	result = (char **)malloc(sizeof(char *) * (nstr(s, c) + 1));
	while (y < ft_strlen(s) && x < nstr(s, c))
	{
		result[x] = (char *)malloc(sizeof(char) * (checksizesub((s + y), c)
					+ 1));
		while (c == s[y] && i == 0)
			y++;
		while (s[y] != c && '\0' != s[y])
			result[x][i++] = s[y++];
		if (s[y] == c || (s[y++] == '\0' && i != 0))
			result[x++][i] = '\0';
		i = 0;
	}
	result[x] = NULL;
	return (result);
}
