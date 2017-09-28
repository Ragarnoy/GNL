/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:28:37 by tlernoul          #+#    #+#             */
/*   Updated: 2017/09/28 23:27:24 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static char str[BUFF_SIZE + 1];
	char	*tmp;
	int i;
	int end;

	i = 0;
	*line = NULL;
	while ((end = read(fd, str, BUFF_SIZE)) > 0)
	{
		str[BUFF_SIZE] = '\0';
		*line = ft_strappend(*line, str, 'f');
		if ((tmp = ft_strchr(*line, '\n')))
		{
			*tmp = '\0';
			return (1);
		}
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
	return 0;
}
