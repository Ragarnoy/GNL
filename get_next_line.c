/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/08 18:38:09 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
/*
int		testget_next_line(const int fd, char **line)
{
	char		*buf;
	int			end;
	static char	*save = NULL;

	if (fd > MAX_FD || fd < 0 || BUFF_SIZE <= 0 || line == NULL || !(buf =
				ft_strnew(BUFF_SIZE)))
		return (-1);
	if (save && *save)
		*line = ft_strappend(*line, save, 1);
	while (((end = read(fd, buf, BUFF_SIZE)) > 0) && !(ft_strchr(save, '\n')))
	{
		//printf("===buf:'%s'||line:'%s'||save:'%s'||end=%d\n",buf,*line,save, end);
		printf("===%s===%d=\n",buf,end);
		*save = ft_strappend(save, buf, 1);
	}
}

Check -1

Tant que !\n dans save ou read
	read dans BUF
	buf dans save
Check read-1
Append de save dans line jusqu'a \n
strsub de \n + 1 a \0
*/


int		get_next_line(const int fd, char **line)
{
	char		*buf;
	int			end;
	static char	*save = NULL;

	*line = NULL;
	if (fd > MAX_FD || fd < 0 || BUFF_SIZE <= 0 || line == NULL || !(buf =
				ft_strnew(BUFF_SIZE)) || !(save = ft_strnew(BUFF_SIZE)))
		return (-1);
	while (((end = read(fd, buf, BUFF_SIZE)) > 0) && !(ft_strchr(save, '\n')))
	{
		save = ft_strappend(save, buf, 1);
	}
	if (end == -1)
		return (-1);
	*line = (ft_strchr(save, '\n') ? ft_strappend(*line, ft_strsub(save, 0,
			ft_strchr(save, '\n') - save), 3) : ft_strappend(*line, save, 1));
	if (ft_strchr(buf, '\n'))
		save = ft_strsub(buf, ft_strchr(buf, '\n') - buf + 1, ft_strclenc(buf, '\n', '\0'));
	else if (end != 0 && buf)
		*line = ft_strappend(*line, buf, 3);
	printf("%s\n",*line);
	return (end/* || *line*/);
}

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
}
