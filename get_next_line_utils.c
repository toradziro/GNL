/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:23:06 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/07 21:06:08 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*join;
	char	*tmp;

	if (!s1 && !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(join = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	tmp = join;
	while (*s1)
		*(tmp++) = *(s1++);
	while (*s2)
		*(tmp++) = *(s2++);
	*tmp = '\0';
	return (join);
}

int		ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		j;
	int		i;

	if (!s)
		return (NULL);
	j = start;
	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (!(substr = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (len > 0 && s[j])
	{
		substr[i] = s[j];
		j++;
		i++;
		len--;
	}
	substr[i] = '\0';
	return (substr);
}

char		*ft_strdup(const char *str)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(str);
	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
