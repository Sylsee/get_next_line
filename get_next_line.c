/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:17:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/22 20:02:39 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_return(char *s, size_t i)
{
	if (i == 0)
	{
		if (s)
			free(s);
		return (0);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	static char	*tab[FDMAX];
	size_t		i;
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	i = 1;
	if (!line || read(fd, 0, 0)  == -1 || BUFFER_SIZE < 1 || fd < 0 || fd > FDMAX)
		return (-1);
	while(i != 0 && ft_check(tab[fd]) == -1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin(buffer, tab[fd]);
		free(tmp);
	}
	*line = ft_substr(tab[fd], 0, ft_bad_strlen(tab[fd]));
	tmp = tab[fd];
	tab[fd] = ft_substr(tab[fd], ft_bad_strlen(tab[fd]),
			ft_strlen(tab[fd]) - ft_bad_strlen(tab[fd]));
	free(tmp);
	return (ft_return(tab[fd], i));
}
/*
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	char			*lineadress[66];
	
	j = 1;
	if (!(fd = open("files/alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 66)
		printf("\nRight number of lines\n");
	else if (j != 66)
		printf("\nNot Good - Wrong Number Of Lines\n");
	while (--j > 0)
		free(lineadress[j - 1]);
}*/
