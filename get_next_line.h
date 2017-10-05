/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:21:51 by tlernoul          #+#    #+#             */
/*   Updated: 2017/10/05 23:24:56 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 10

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <string.h>

typedef struct		s_gnl
{
	void			*content;
	size_t			content_size;
	struct s_gnl	*next;
}					t_gnl;

int	get_next_line(const int fd, char **line);

#endif
