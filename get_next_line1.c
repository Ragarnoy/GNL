/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/20 16:42:27 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	concaten(char **save, char **line)
{
	if (save)
	{
		*line = ft_strappend(*line, *save, 'n');
		ft_strdel(save);
	}
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		*buffer;
	int			end;

	*line = NULL;
	buffer = ft_strnew(BUFF_SIZE + 1);
	while ((end = read(fd, buffer, BUFF_SIZE)) > 0 && (!ft_strchr(buffer, '\n')))
	{
		concaten(&save, line);
		if (buffer[0])
			*line = ft_strappend(*line, buffer, 'f');
	}
	if (ft_strchr(buffer, '\n'))
	{
		concaten(&save, line);
		*line = ft_strappend(*line, ft_strsub(buffer, 0, ft_strchr(buffer, '\n') - buffer), 'f');
		save = ft_strsub(buffer, ft_strchr(buffer, '\n') - buffer + 1, ft_strclenc(buffer, '\n', '\0'));
	}
	else
		*line = ft_strappend(*line, buffer, 'n');
	ft_strdel(&buffer);
	if (!end && save)
			*line = ft_strappend(*line, save, 'n');
	return (!(!end && save));
}

#include <fcntl.h>
int main(int argc, const char *argv[])
{
	char	*line;
	int		fd;

	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		ft_putendl(line);
	//	printf("   ||>>  %zu\n",ft_strlen(line));
		free(line);
	}
	line = NULL;
	return 0;
}
