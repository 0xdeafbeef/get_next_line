//
// Created by Quenton hightower Hettinger on 2018-12-07.
//

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#define MAX_UNIX_KERNEL_FD_COUNT 590432
#define BUFF_SIZE 10
#include <fcntl.h>
#include <unistd.h>
#include "libft/libft.h"

int		get_next_line(const int fd, char **line);
#endif