/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 12:24:11 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/08 12:26:27 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strdup(const char *str)
{
	char	*res;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen((char*)str);
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

int		ft_strlen(char *s)
{
	if (!s)
		return (0);
	int i;

	i = 0;
	while (s[i])
		i++;
	return(i);
}

char	*ft_reput(char *tmp, char *buff)
{
	char	*new;
	int		l1;
	int		l2;

	l1 = ft_strlen(tmp);
	if (l1 == 0)
		return (ft_strdup(buff));
	l2 = ft_strlen(buff);
	new = ft_calloc(sizeof(char), (l1 + l2 + 1));
	ft_strlcat(new, tmp, (l1 + l2));
	ft_strlcat(new + l1, buff, (l2 + l1));
	return (new);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d_len;
	size_t	i;

	d_len = 0;
	i = 0;
	while (dst[d_len] && d_len < size)
		d_len++;
	while ((d_len + i + 1 < size) && (src[i]))
	{
		dst[d_len + i] = src[i];
		i++;
	}
	if (d_len != size)
		dst[d_len + i] = '\0';
	return (ft_strlen((char*)src) + d_len);
}

void	*ft_calloc(size_t num, size_t size)
{
	void *res;

	res = (char*)malloc(num * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, (num * size));
	return (res);
}

void	*ft_memset(void *dest, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char*)dest;
	while (i < n)
	{
		*str = c;
		str++;
		i++;
	}
	return (dest);
}