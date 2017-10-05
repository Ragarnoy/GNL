/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/05 23:10:47 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	newline(char *str, char *line)
{
	size_t	i;
	char	*p;
printf("--------\nDebug 1 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n",line,ft_strlen(line),str,ft_strlen(str));
	p = ft_strchr(str, '\n');
	i = str + ft_strlen(str) - p;
	if (str[0] == '\n')
	{
		ft_memmove(str, str + 1, i);
		return;
	}
	*p = '\0';
	ft_memcpy(line + ft_strlen(line), str, i);
	//line[ft_strlen(line) + 1] = '\0';
	ft_memmove(str, p + 1, i);
printf("--------\nDebug 2 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n",line,ft_strlen(line),str,ft_strlen(str));
}

void	total_recall(char *str, char *line)
{
	if (str && !ft_strchr(str, '\n'))
		line = ft_strappend(line, str, 'f');
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			end;

	if (!str && !(str = ft_strnew(BUFF_SIZE)))
		return (0);
	*line = ft_strnew(BUFF_SIZE); //lol je sais pas
	total_recall(str, *line);
	while ((end = read(fd, str, BUFF_SIZE)) > 0)
	{
printf("--------\nDebug 0 \n>>> line=%s %zu\n>>>> str=%s %zu\n--------\n\n",*line,ft_strlen(*line),str,ft_strlen(str));
		if (ft_strchr(str, '\n'))
		{
printf("======================\nPassing into newline !\n======================\n");
			newline(str, *line);
printf("==================\nQuitting newline !\n==================\n");
			return (1);
		}
		else
			*line = ft_strappend(*line, str, 'f');
	}
	if (!line && !end)
	{
		free(str);
		str = NULL;
		printf("str is free\n");
	}
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
	line = NULL;
	return 0;
}
