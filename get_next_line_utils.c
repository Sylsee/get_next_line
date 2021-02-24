/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:08:12 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/24 03:44:28 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_chr(char *s, int c)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i] && s[i] != c)
			i++;
	return (i);
}

size_t	ft_strlen(char *s)
{
	size_t i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int		ft_check(char *s)
{
	int i;

	i = -1;
	if (!s)
		return (1);
	while (s[++i])
		if (s[i] == '\n')
			return (0);
	return (1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	ret = (char *)malloc(sizeof(char) * (j + 1));
	if (!ret)
		return (NULL);
	j = -1;
	if (s1)
		while (s1[++j])
			ret[i++] = s1[j];
	j = -1;
	if (s2)
		while (s2[++j])
			ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*ret;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s) + 1)
		size = ft_strlen(s);
	else
		size = len;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
