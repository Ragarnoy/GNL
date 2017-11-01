/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:21:51 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/01 19:01:42 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# define MAX_FD 7168
# define MAX_INT 2147483647

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>

typedef struct		s_gnl
{
	char			*save[MAX_FD];
	int				end;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
