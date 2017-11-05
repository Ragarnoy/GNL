/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <tlernoul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:39:50 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/05 15:29:02 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		get_next_line(const int fd, char **line)
{
	char		*buf;
	int			end;
	static char	*save = NULL;

	*line = NULL;
	if (fd > MAX_FD || fd < 0 || BUFF_SIZE <= 0 || line == NULL || !(buf =
				ft_strnew(BUFF_SIZE)))
		return (-1);
	if (save && *save)
		*line = ft_strappend(*line, save, 1);
	ft_strdel(&save);
	while (((end = read(fd, buf, BUFF_SIZE)) > 0) && !(ft_strchr(buf, '\n')))
	{
		//printf("===buf:'%s'||line:'%s'||save:'%s'||end=%d\n",buf,*line,save, end);
		printf("===%s===%d=\n",buf,end);
		*line = ft_strappend(*line, buf, 1);
	}
		printf("===%s===%d=\n",buf,end);
	if (end == -1)
		return (-1);
	if (ft_strchr(buf, '\n'))
	{
		*line = ft_strappend(*line, ft_strsub(buf, 0, ft_strchr(buf, '\n') - buf), 3);
		save = ft_strsub(buf, ft_strchr(buf, '\n') - buf + 1, ft_strclenc(buf, '\n', '\0'));
	}
	else if (end != 0 && buf)
		*line = ft_strappend(*line, buf, 3);
	return (end || *line);
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
