/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:17:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/24 00:38:08 by spoliart         ###   ########.fr       */
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

	i = -1;
	if (read(fd, 0, 0) == -1 || fd < 0 || fd > FDMAX || !line ||
			BUFFER_SIZE < 1)
		return (-1);
	while (i != 0 && ft_check(tab[fd]))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin(tab[fd], buffer);
		free(tmp);
	}
	*line = ft_substr(tab[fd], 0, ft_bad_strlen(tab[fd]));
	tmp = tab[fd];
	tab[fd] = ft_substr(tab[fd], ft_bad_strlen(tab[fd]) + 1,
			ft_strlen(tab[fd]) - ft_bad_strlen(tab[fd]));
	free(tmp);
	return (ft_return(tab[fd], i));
}
