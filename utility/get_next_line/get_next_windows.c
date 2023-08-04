/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_windows.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 13:26:34 by marvin            #+#    #+#             */
/*   Updated: 2023/08/04 13:26:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*windows_return_carriage(char *fullstr)
{
	int	i;

	i = 0;
	while (fullstr[i])
	{
		if (fullstr[i] == '\r')
			fullstr[i] = '\n';
		i++;
	}
	return (fullstr);
}
