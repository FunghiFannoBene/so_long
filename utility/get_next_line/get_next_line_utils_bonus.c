/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:41:44 by shhuang           #+#    #+#             */
/*   Updated: 2023/01/17 02:15:23 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen_g(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	int		i;
	int		j;
	int		len;
	int		len2;
	char	*s;

	len = ft_strlen_g(s1);
	len2 = ft_strlen_g(s2);
	i = 0;
	j = 0;
	s = (char *)malloc(len + len2 + 1);
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	free(s1);
	s1 = NULL;
	while (j < len2)
	{
		s[i + j] = s2[j];
		j++;
	}
	s[i + j] = '\0';
	return (s);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*s;
	int		len;
	int		len2;

	len = ft_strlen_g(s1);
	len2 = ft_strlen_g(s2);
	i = 0;
	j = 0;
	s = (char *)malloc(len + len2 + 1);
	while (i < len)
	{
		s[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		s[i + j] = s2[j];
		j++;
	}
	free(s1);
	free(s2);
	s[i + j] = '\0';
	return (s);
}

int	ft_strchr_g(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	if (!c && s[i] == '\0')
		return (1);
	return (0);
}

char	*copyafter(int len, char *contusabile)
{
	char	*strmemory;
	int		i;
	int		len2;

	i = 0;
	len2 = ft_strlen_g(contusabile);
	strmemory = (char *)malloc(len2 - len + 1);
	while (i < len2 - len)
	{
		strmemory[i] = contusabile[i + len];
		i++;
	}
	strmemory[i] = '\0';
	return (strmemory);
}
