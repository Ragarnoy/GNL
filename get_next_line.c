/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/04 21:32:17 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	newline(char *str, char *line)
{
	size_t	i;
	char	*p;
printf("--------\nDebug 1 \n>>> line=%s0\n>>>> str=%s0\n--------\n\n",line,str);
	p = ft_strchr(str, '\n');
	i = str + ft_strlen(str) - p;
	if (str[0] == '\n')
	{
		ft_memmove(str, str + 1, i);
		return;
	}
	ft_memcpy(line + ft_strlen(line), str, i);
	line[i] = '\0';
	ft_memmove(str, p + 1, i);
printf("--------\nDebug 2 %zu\n>>> line=%s0\n>>>> str=%s0\n--------\n\n",i,line,str);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str = NULL;
	int			end;

	if (/*!str &&*/!(str = ft_strnew(BUFF_SIZE)))
		return (0);
	*line = ft_strnew(50); //lol je sais pas
	while ((end = read(fd, str, BUFF_SIZE)) > 0)
	{
printf("--------\nDebug 0 \n>>> line=%s0\n>>>> str=%s0\n--------\n\n",*line,str);
		if (ft_strchr(str, '\n'))
		{
printf("======================\nPassing into newline !\n======================\n");
			newline(str, *line);
			return (1);
		}
		else
			*line = ft_strappend(*line, str, 'f');
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
