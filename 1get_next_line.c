/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/31 18:37:35 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*concaten(char **buffer, t_gnl *gnl)
{
	gnl->save[gnl->fd] = ft_strsub(*buffer, ft_strchr(*buffer, '\n')
			- *buffer + 1,ft_strclenc(*buffer, '\n', '\0'));

}

int		ft_get_next_line(const int fd, char **line)
{
	static t_gnl	gnl;
	char			*buffer;

	*line = NULL;
	while ((gnl.end = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (*buffer)
			*line = ft_strappend(*line, buffer, 'f');
		if (ft_strchr(buffer, '\n'))
		{
			*line = ft_strappend(*line, ft_strsub(buffer, 0,
						ft_strchr(buffer, '\n') - buffer), 'f');
			ft_strdel(&buffer);
			return (1);
		}
	}
	return (gnl.end || (line && *line));
}
