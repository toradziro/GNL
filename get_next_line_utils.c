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

#include <unistd.h>
#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

char	*ft_strdup(const char *str);

char	*ft_reput(char *tmp, char *buff);

int		ft_strlen(char *s);

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			i;

	tmp1 = (unsigned char*)dest;
	tmp2 = (unsigned char*)src;
	i = 0;
	if (!tmp1 && !tmp2)
		return (NULL);
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (dest);
}

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
	new = (char*)malloc(sizeof(char) * (l1 + l2 + 1));
	ft_memcpy(new, tmp, l1);
	ft_memcpy(new + l1, buff, l2);
	return (new);
}
