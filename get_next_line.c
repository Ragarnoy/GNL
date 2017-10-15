/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/14 19:33:06 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	newline(char *str, char *line, char **save)
{
	size_t	i;
	char	*p;

//printf("--------\nDebug 1 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n",line,ft_strlen(line),str,ft_strlen(str));
	p = ft_strchr(str, '\n');
	i = (str + ft_strlen(str)) - p;
	if (str[0] == '\n' && str[1] != '\n')
	{
		ft_memmove(str, str + 1, i);
		*save = ft_strdup(p);
		return ;
	}
	if (p[0] == '\n' && p[1] == '\n')
		line = ft_strappend(line, "\n", 'f');
	*p = '\0';
	*save = ft_strdup(p + 1);
	line = ft_strappend(line, str, 'f');
//printf("--------\nDebug 2 \n>>> line=%s %zu\n>>> *save=%s %zu\n--------\n",line,ft_strlen(line),*save,ft_strlen(*save));
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		buffer[BUFF_SIZE + 1];
	int			end;

	*line = ft_strnew(BUFF_SIZE); //lol je sais pas
	ft_bzero(buffer, BUFF_SIZE + 1);
	while ((end = read(fd, buffer, BUFF_SIZE)) >= 0 && 
			(!ft_strchr(buffer, '\n')))
	{
//printf("--------\nDebug 0 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n\n",*line,ft_strlen(*line),buffer,ft_strlen(buffer));
		if (save)
		{
			//ft_putstr("fucktard\n");
			*line = ft_strappend(*line, save, 'f');
		}
		if (buffer[0])
		{
			//ft_putstr("fucktardo\n");
			*line = ft_strappend(*line, buffer, 'f');
		}
			//ft_putstr("fucktardus\n");
		ft_strdel(&save);
	}
		newline (buffer, *line, &save);
//printf("--------\nSortie NL \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n\n",*line,ft_strlen(*line),buffer,ft_strlen(buffer));
	if (!end)
	{
		//printf("str is free\n");
		return (0);
	}
	return (1);
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
		//printf(" %zu\n", ft_strlen(line));
		free(line);
	}
	line = NULL;
	return 0;
}
