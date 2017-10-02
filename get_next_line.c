/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/02 19:15:30 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
char	*findnewline_cut(char *str)
{
	char	*ret;

	ret = ft_strnew(BUFF_SIZE);
	if (!(ft_strchr(str, '\n')))
		return (NULL);
	else
	{
		ret = ft_memmove(str, ft_strchr(str, '\n') + 1, ft_strclen(str, '\n'));
		ft_bzero(ft_strchr(str, '\n'), ft_strlen(ft_strchr(str, '\n')));
	}
		//printf("=+%s+=\n", str);
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	char		*tmp;
	int			end;

	if (!str && !(str = ft_strnew(BUFF_SIZE)))
		return (0);
	while ((end = read(fd, str, BUFF_SIZE)) > 0)
	{
		tmp = ft_strnew(BUFF_SIZE);
		tmp = ft_strappend(*line, str, 'f');
		ft_bzero(str, BUFF_SIZE);
		if (findnewline_cut(tmp))
		{
			*line = ft_strappend(*line, str, 'f');
			return (1);
		}
	}
	if (!line && !end)
		free(str);
	return (0);
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
		ft_putendl(line);
	free(line);
	return 0;
}
