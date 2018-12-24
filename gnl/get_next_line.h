//
// Created by Quenton hightower Hettinger on 2018-12-07.
//

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H
#define BUFF_SIZE 7
#include <fcntl.h>
#include <printf.h>
#include "unistd.h"
#include "libft.h"

typedef	struct		tf_list
{
	char			*content;
	int				fd;
	struct sf_list	*next;
}					sf_list;
#endif //GET_NEXT_LINE_GET_NEXT_LINE_H
