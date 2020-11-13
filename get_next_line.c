/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:11:42 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/13 18:29:03 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static char	*rem;
	char		*buff;
	int			rd;

	buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1);
	rd = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buff)
	{
		free(buff);
		return (-1);
	}
	while (rd > 0 && !(ft_find_endl(rem)))
	{
		if ((rd = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[rd] = '\0';
		rem = ft_strjoin(rem, buff);
	}
	free(buff);
	*line = ft_init(rem);
	rem = ft_cut(rem);
	if (rd == 0)
		return (0);
	return (1);
}

int		ft_find_endl(char *tmp)
{
	if (!tmp)
		return (0);
	while (*tmp != '\0')
	{
		if (*tmp == '\n')
			return (1);
		tmp++;
	}
	return (0);
}

char	*ft_init(char *rem)
{
	char	*tmp;
	int		i;

	i = 0;
	while (rem[i] != '\n' && rem[i])
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (rem[i] != '\n' && rem[i])
	{
		tmp[i] = rem[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_cut(char *rem)
{
	char	*tmp;
	int		i;
	int		count;

	i = 0;
	count = ft_count_to_endl(rem);
	if (rem[count] == '\0')
	{
		free(rem);
		return (NULL);
	}
	count++;
	while (rem[i + count])
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (rem[count])
	{
		tmp[i] = rem[count];
		i++;
		count++;
	}
	tmp[i] = '\0';
	free(rem);
	return (tmp);
}

int		ft_count_to_endl(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}
