/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/01 19:55:33 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int		get_next_line(const int fd, char **line)
{
	static char	str[BUFF_SIZE + 1];
	int			i;
	int			end;
	void		*lol;

	i = 0;
	*line = NULL;
	while ((end = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[BUFF_SIZE] = '\0';
		*line = ft_strappend(*line, str, 'f');
		printf("- %s\n", line[0]);
		ft_strclr(str);
		lol = ft_strchr(line[0], '\n');
		printf("+ %s\n", lol);
		if (lol && ft_memcpy(str, ft_strchr(*line, '\n'), ft_strclen(*line, '\n')))
		{
			ft_putstr("lol");
			str[BUFF_SIZE] = '\0';
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
	return 0;
}
