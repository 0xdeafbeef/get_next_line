/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 20:26:33 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/19 22:25:10 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define MAX_UNIX_KERNEL_FD_COUNT 590432
# define BUFF_SIZE 50000
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# if BUFF_SIZE > 8388608
#  define REDD int redd;
#  define FRST char		*buf; buf = ft_strnew(BUFF_SIZE);
#  define CLEAR ft_strdel(&buf)
#  define READLER readler(&buf, &str[fd], &tmp)
#  define READ readler(char **buf, char **str, char **tmp)
#  define READ_BODY *tmp = ft_strdup(*str); ft_strdel(str);
#  define READ_BODY1 *str=ft_strjoin(*tmp,*buf);ft_strdel(tmp);
#  define READ_BODY2 ft_bzero(*buf,BUFF_SIZE);
# define RREDD redd
# else
#  define REDD int redd;
#  define FRST char		buf[BUFF_SIZE];
#  define CLEAR *line = *line + 0;
#  define INN char **str,char **tmp,int fd,int redd)
#  define READ readler(char buf[BUFF_SIZE], INN
#  define READLER readler(buf, &str, tmp, fd, redd)
#  define READ_BODY tmp = &str[fd];
#  define READ_BODY1 buf[redd] = '\0';
#  define READ_BODY2 	*str[fd] = ft_strjoin(*tmp, buf); ft_strdel(tmp);
# define RREDD redd

# endif

int		get_next_line(const int fd, char **line);
#endif
