/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseabass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 22:29:33 by cseabass          #+#    #+#             */
/*   Updated: 2019/09/30 22:29:39 by cseabass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h>

static int	error(char **s)
{
	free(*s);
	return (-1);
}

static int	end(char **s, char **line, int fd)
{
	int		j;
	char	*end;

	j = 0;
	while (s[fd][j] != '\n' && s[fd][j])
		j++;
	if (!(*line = ft_strsub(s[fd], 0, j)))
		return (-1);
	if (ft_strchr(s[fd], '\n') == NULL)
	{
		if (!(end = ft_strdup(ft_strchr(s[fd], '\0') + 0)))
			return (error(&s[fd]));
	}
	else
	{
		if (!(end = ft_strdup(ft_strchr(s[fd], '\n') + 1)))
			return (error(&s[fd]));
	}
	free(s[fd]);
	s[fd] = end;
	return (1);
}

static int	returns(char **s, char **line, int i, int fd)
{
	if (i == -1)
		return (-1);
	if (i <= 0 && (!(s[fd]) || !(s[fd][0])))
		return (0);
	return (end(s, line, fd));
}

int			get_next_line(const int fd, char **line)
{
	char		*tmp;
	char		buf[BUFF_SIZE + 1];
	static char	*s[10240];
	int			i;

	i = -2;
	if (fd < 0 || fd > 10239 || BUFF_SIZE < 1)
		return (-1);
	if (s[fd] == NULL)
		if (!(s[fd] = ft_strnew(1)))
			return (-1);
	if (ft_strchr(s[fd], '\n') == NULL)
		while ((i = read(fd, buf, BUFF_SIZE)) > 0)
		{
			buf[i] = '\0';
			if (!(tmp = ft_strjoin(s[fd], buf)))
				return (error(&s[fd]));
			free(s[fd]);
			s[fd] = tmp;
			if (ft_strchr(buf, '\n') != NULL)
				break ;
		}
	return (returns(s, line, i, fd));
}
