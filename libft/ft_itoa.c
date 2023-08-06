/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 04:16:43 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/25 01:47:49 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	contatore(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	ndigit;
	char	*stringa;
	long	nconv;

	ndigit = contatore(n);
	nconv = n;
	stringa = (char *)malloc(sizeof(char) * ndigit + 1);
	if (stringa == NULL)
		return (NULL);
	if (nconv < 0)
	{
		stringa[0] = '-';
		nconv = -nconv;
	}
	if (nconv == 0)
		stringa[0] = '0';
	stringa[ndigit--] = '\0';
	while (nconv)
	{
		stringa[ndigit] = nconv % 10 + '0';
		ndigit--;
		nconv = nconv / 10;
	}
	return (stringa);
}
