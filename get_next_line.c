/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/06 20:12:30 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	newline(char *str, char *line, char *save)
{
	size_t	i;
	char	*p;

printf("--------\nDebug 1 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n",line,ft_strlen(line),str,ft_strlen(str));
	p = ft_strchr(str, '\n');
	i = str + ft_strlen(str) - p;
	save = ft_strnew(i);
	if (str[0] == '\n' && str[1] != '\n')
	{
		ft_memmove(str, str + 1, i);
		return;
	}
	*p = '\0';
	ft_memcpy(line + ft_strlen(line), str, i);
	ft_memmove(save, p + 1, i);
printf("--------\nDebug 1 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n",line,ft_strlen(line),str,ft_strlen(str));
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		buffer[BUFF_SIZE + 1];
	int			end;

	*line = ft_strnew(BUFF_SIZE); //lol je sais pas
	while (!ft_strchr(buffer, '\n'))
	{
printf("--------\nDebug 0 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n\n",*line,ft_strlen(*line),buffer,ft_strlen(buffer));
		if (save[1])
			*line = ft_strappend(*line, save, 'f');
		if (buffer[1])
			*line = ft_strappend(*line, buffer, 'f');
		(end = read(fd, buffer, BUFF_SIZE));
		save = NULL;
	}
		newline (buffer, *line, save);
printf("--------\nSortie NL \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n\n",*line,ft_strlen(*line),buffer,ft_strlen(buffer));
	return (1);
	if (!end)
	{
		printf("str is free\n");
		return (0);
	}
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
		free(line);
	}
	line = NULL;
	return 0;
}
