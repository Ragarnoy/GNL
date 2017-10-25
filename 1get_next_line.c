/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/25 18:06:08 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_gnl	*lstnew(const char *save, int fd)
{
	t_gnl *elem;

	if (!(elem = malloc(sizeof(t_list))))
		return (NULL);
	if (!(elem->save = malloc(sizeof(elem->save) + (ft_strlen(save) + 1))))
		return (NULL);
	if (!(save))
	{
		elem->save = NULL;
		elem->fd = 0;
	}
	else
	{
		ft_strcpy(elem->save, save);
		elem->fd = fd;
	}
	elem->next = NULL;
	return (elem);
}

char	*concaten(char **buffer)
{
	char *save;

	save = ft_strsub(*buffer, ft_strchr(*buffer, '\n') - *buffer + 1,
			ft_strclenc(*buffer, '\n', '\0'));
	if

}

int		ft_get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char			*buffer;
	int				end;

	*line = NULL;
	while ((end = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (*buffer)
			*line = ft_strappend(*line, buffer, 'f');
		if (ft_strchr(buffer, '\n'))
		{
			*line = ft_strappend(*line, ft_strsub(buffer, 0,
						ft_strchr(buffer, '\n') - buffer), 'f');
			save = lstnew(concaten(&buffer), fd);
			ft_strdel(&buffer);
			return (1);
		}
	}
	return (end || (line && *line));
}
