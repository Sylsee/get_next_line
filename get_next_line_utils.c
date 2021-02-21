/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoliart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:08:12 by spoliart          #+#    #+#             */
/*   Updated: 2021/02/21 16:12:15 by spoliart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	if (!s1 || !s2)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		size;
	char	*ret;

	i = 0;
	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) + 1)
		size = ft_strlen(s);
	else
		size = len;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (NULL);
	while (s[start + i] && i < (int)len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
