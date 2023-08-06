/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:45:44 by shhuang           #+#    #+#             */
/*   Updated: 2022/11/24 20:49:04 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n && *d == *s)
	{
		d++;
		s++;
		n--;
	}
	if (n)
		return (*d - *s);
	else
		return (0);
}
/* indirizzo di memoria di d == a 
s??????!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!/
/verifica che i due puntatori siano uguali, 
inferiori o maggiori per n numero. 
Scorre i puntatori finche' sono uguali e 
si ferma quando n va a 0 o non trova piu un uguaglianza.*/