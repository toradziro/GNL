/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 10:11:42 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/08 12:30:56 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

static char	*ft_read_to_endl(char *tmp, int fd);

static int		ft_find_endl(char *tmp);

int		get_next_line(int fd, char **line)
{
	static char	*tmp;

	tmp = ft_read_to_endl(tmp, fd);
	*line = tmp;
	return (1);
}

static char	*ft_read_to_endl(char *tmp, int fd)
{
	char	*buff;

	if (!(buff = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (NULL);
	while (!(ft_find_endl(tmp)))
	{
		read(fd, buff, BUFFER_SIZE);
		buff[BUFFER_SIZE] = '\0';
		tmp = ft_reput(tmp, buff);
	}
	return (tmp);
}

static int		ft_find_endl(char *tmp)
{
	int		i;

	i = 0;
	if (ft_strlen(tmp) == 0)
		return (0);
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
