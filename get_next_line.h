/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:21:51 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/31 18:36:56 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10
# define FD_MAX 7168

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>

typedef struct		s_gnl
{
	char			*save[FD_MAX];
	int				end;
	int				fd;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
