/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehillman <ehillman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 16:23:10 by ehillman          #+#    #+#             */
/*   Updated: 2020/11/07 21:29:11 by ehillman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_find_endl(char *tmp);

static void		ft_read(char *buff, char *tmp, int fd, int BUFFER_SIZE);

static char		*ft_fill(char *tmp, char **line);

static char 	*ft_fill_eof(char *tmp, char **line);

int		get_next_line(int fd, char **line)
{
	int				BUFFER_SIZE = 10;
	static char		*tmp;
	char			*buff;

	buff = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (ft_find_endl(tmp) == 0)
		ft_read(buff, tmp, fd, BUFFER_SIZE);
	if ((ft_find_endl(tmp)) == 1)
	{
		*line = ft_fill(tmp, line);
		return (1);
	}
	else if ((ft_find_endl(tmp)) == 2)
	{
		*line = ft_fill_eof(tmp, line);
		return (0);
	}
	return (0);
}

static char *ft_fill_eof(char *tmp, char **line)
{
	int		i;
	char	*new;

	i = 0;
	while (tmp[i] != '\0')
		i++;
	new = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (tmp[i] != '\0')
	{
		new[i] = tmp[i];
		i++;
	}
	new[i] = '\0';
	free(tmp);
	return (new);
}

static char	*ft_fill(char *tmp, char **line)
{
	int		i;
	char	*new;

	i = 0;
	while (tmp[i] != '\n')
		i++;
	new = (char*)malloc(sizeof(char) * i + 1);
	i = 0;
	while (tmp[i] != '\n')
	{
		new[i] = tmp[i];
		i++;
	}
	new[i] = '\0';
	tmp = ft_substr(tmp, i, (ft_strlen(tmp) - i));
	return (new);
}

static void	ft_read(char *buff, char *tmp, int fd, int BUFFER_SIZE)
{
	read(fd, buff, BUFFER_SIZE);
	buff[BUFFER_SIZE] = '\0';
	tmp = ft_strjoin(tmp, buff);
}

static int		ft_find_endl(char *tmp)
{
	int		i;

	i = 0;
	if (!tmp)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == '\0')
			return (2);
		else if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
