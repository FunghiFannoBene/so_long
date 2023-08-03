/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shhuang <shhuang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:41:44 by shhuang           #+#    #+#             */
/*   Updated: 2023/01/17 02:15:23 by shhuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char		*nuovalinea;
	static char	*strmemory[1024];
	char		*contusabile;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &contusabile, 0) < 0)
		return (NULL);
	contusabile = size_1mem(contusabile);
	contusabile = crea_contusabile(contusabile, fd);
	if ((contusabile[0] == '\0' && !strmemory[fd]) || !contusabile)
	{
		getfree_g(&contusabile);
		return (NULL);
	}
	if (!strmemory[fd])
		strmemory[fd] = size_1mem(strmemory[fd]);
	contusabile = ft_strjoin2(strmemory[fd], contusabile);
	nuovalinea = trova_nl(contusabile);
	i = ft_strlen_g(nuovalinea);
	if (i != 0 && contusabile)
		strmemory[fd] = copyafter(i, contusabile);
	free(contusabile);
	if (strmemory[fd][0] == '\0' || nuovalinea[0] == '\0')
		getfree_g(&strmemory[fd]);
	return (nuovalinea);
}

char	*trova_nl(char *contusabile)
{
	int		j;
	char	*nuovalinea;

	j = 0;
	while (contusabile[j] != '\n' && contusabile[j])
		j++;
	if (contusabile[j] == '\n')
		j++;
	nuovalinea = (char *)malloc(j + 1);
	j = 0;
	while (contusabile[j] != '\n' && contusabile[j])
	{
		nuovalinea[j] = contusabile[j];
		j++;
	}
	if (contusabile[j] == '\n')
	{
		nuovalinea[j] = contusabile[j];
		j++;
	}
	nuovalinea[j] = '\0';
	return (nuovalinea);
}

char	*crea_contusabile(char *contusabile, int fd)
{
	int		caratteriletti;
	char	*contenitore;

	caratteriletti = 1;
	while (caratteriletti)
	{
		contenitore = (char *)malloc(BUFFER_SIZE + 1);
		caratteriletti = read(fd, contenitore, BUFFER_SIZE);
		if (caratteriletti == -1)
		{
			free(contenitore);
			getfree_g(&contusabile);
			break ;
		}
		contenitore[caratteriletti] = '\0';
		contusabile = ft_strjoin_g(contusabile, contenitore);
		if (ft_strchr_g(contenitore, '\n'))
		{
			free(contenitore);
			break ;
		}
		free(contenitore);
	}
	return (contusabile);
}

char	*size_1mem(char *c)
{
	c = (char *)malloc(1);
	c[0] = '\0';
	return (c);
}

void	getfree_g(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
	return ;
}
// int  main(void)
// {
//      char    *line;
// 	 char    *line2;
// 	 char    *line3;
//      int             i;
//      int             fileid;
// 	  int             fileid2;
// 	  int             fileid3;
//      fileid = open("read_error.txt", O_RDONLY);
// 	 fileid2 = open("text.txt", O_RDONLY);
// 	 fileid3 = open("text2.txt", O_RDONLY);
//      i = 1;
//      while (i < 80)
//      {
//              line = get_next_line(fileid);
// 				line2 = get_next_line(fileid2);
// 				line3 = get_next_line(fileid3);
//              printf("\n%s\n%s\n%s", line, line2, line3);
//              free(line);
// 			 free(line2);
// 			  free(line3);
//              i++;
//      }
//      close(fileid);
// 	  close(fileid2);
// 	   close(fileid3);
//      return (0);
// }