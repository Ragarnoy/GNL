/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlernoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 21:21:51 by tlernoul          #+#    #+#             */
/*   Updated: 2017/11/13 16:49:26 by tlernoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1
# define MAX_FD 7168
# define MAX_INT 2147483647

# include <unistd.h>
# include "libft/libft.h"

int					get_next_line(const int fd, char **line);

#endif
