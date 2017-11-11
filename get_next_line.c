/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/11 21:00:03 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	**multi_fd(int fd)
{
	static char		***mfd = NULL;

	if (!mfd)
		mfd = (char ***)ft_memalloc(sizeof(char **) * MAX_FD);
	if (mfd)
	{
		if (!mfd[fd])
		{
			mfd[fd] = (char **)ft_memalloc(sizeof(char *));
			*(mfd[fd]) = ft_strnew(BUFF_SIZE);
		}
		if (mfd[fd])
			return (mfd[fd]);
	}
	return (NULL);
}

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	int			end;
	char		**save;

	if (fd > MAX_FD || fd < 0 || BUFF_SIZE <= 0 || line == NULL || !(buf =
				ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = NULL;
	save = multi_fd(fd);
	while (!(ft_strchr(*save, '\n')) && ((end = read(fd, buf, BUFF_SIZE)) > 0))
		*save = ft_strappend(*save, buf, 0);
	if (end == -1)
		return (-1);
//printf("######\n0line===%s===\nsave ===%s===\n",*line,*save);
	*line = (ft_strchr(*save, '\n') ? ft_strappend(*line, ft_strsub(*save, 0, ft_strchr(*save, '\n') - *save), 3) : ft_strappend(*line, *save, 1));
//printf("1line===%s===\nsave ===%s===\n",*line,*save);
	if (ft_strchr(*save, '\n'))
		ft_strcpy(*save, ft_strchr(*save, '\n') + 1);
//printf("2line===%s===\nsave ===%s===\n######\n\n",*line,*save);
	if (!end)
		ft_strclr(*save);
	ft_strdel(&buf);
	return (end || **line);
}
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
