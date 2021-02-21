/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 16:17:20 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/21 16:56:47 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_2(char *s)
{
	size_t i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_check(char *s)
{
	int i;

	i = -1;
	if (!s)
		return (-1);
	while (s[++i])
		if (s[i] == '\n')
			return (i);
	return (-1);
}

int	ft_return(char *s)
{
	int i;

	i = -1;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (s[i] == '\0')
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*tab[FDMAX];
	size_t		i;
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;

	i = 1;
	if (!line || read(fd, 0, 0) == -1)
		return (-1);
	while(i != 0 && ft_check(tab[fd] == -1))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		buffer[i] = '\0';
		tmp = tab[fd];
		tab[fd] = ft_strjoin(buffer, tab[fd]);
		free(tmp);
	}
	tmp = *line;
	*line = ft_substr(tab[fd], 0, ft_strlen_2(tab[fd]));
	free(tmp);
	tmp = tab[i];
	tab[fd] = ft_substr(tab[fd], ft_strlen_2(tab[fd]), ft_strlen(tab[fd]) - ft_strlen_2(tab[fd]));
	free(tmp);
	return (ft_return(tab[fd]));
}
