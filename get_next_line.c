/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/03 19:13:19 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	char		*buffer;
	int			end;
	static char	*save = NULL;

	*line = NULL;
	if (fd > MAX_FD || fd < 0 || BUFF_SIZE <= 0 || line == NULL || !(buffer =
				ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	if (save && *save)
		*line = ft_strappend(*line, save, 1);
	ft_strclr(save);
	while ((end = read(fd, buffer, BUFF_SIZE) > 0) && !(ft_strchr(buffer, '\n')))
		*line = ft_strappend(*line, buffer, 1);
	if (end == -1)
		return (-1);
	if (ft_strchr(buffer, '\n'))
	{
		*line = ft_strappend(*line, ft_strsub(buffer, 0, ft_strchr(buffer, '\n') - buffer), 3);
		save = ft_strsub(buffer, ft_strchr(buffer, '\n') - buffer + 1, ft_strclenc(buffer, '\n', '\0'));
	}
	else if (end != 0 && buffer)
		*line = ft_strappend(*line, buffer, 3);
	return (end || *line);
}

/*int		pseudoget_next_line(const int fd, char **line)
{
	Verifier conditions -1 et allouer buffer
	Remplir buffer avec read
	si read == -1 : return -1
	si buffer a '\n'
		line = buffer jusqu'a '\n' et return 1
	sinon si read != 0 et buffer existe
		line = buffer et return 1
	sinon
	return 0
}

	Remplir buffer avec read
	Tant que read > 0 && buffer n'a pas de '\n'
		copier buffer dans line
*/
/*
#include <fcntl.h>
int main(int argc, const char *argv[])
{
	char	*line;
	int		fd;
	int		ret;

	fd = 0;
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	line = NULL;
	return 0;
}*/
