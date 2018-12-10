
#include <fcntl.h>
#include <printf.h>
#include "get_next_line.h"
#include "libft.h"
#include "unistd.h"


int get_next_line(const int fd, char **line)
{
	static t_list *init;
	char *s;
	int i;

	s = ft_strnew(BUFF_SIZE);
	if (ft_is_null_ptr(s))
			return (-1);
	read(fd, s, BUFF_SIZE);
	init = ft_lstnew(s, BUFF_SIZE);
	free(s);
	while (1)
	{
		i =-1;
		while (s[++i] != '\n' && s[i] != EOF)
			;
		if (i = BUFF_SIZE)
		{
			
		}
	}
	if ( i == BUFF_SIZE)
	*line = init->content;
	return 0;
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY, BUFF_SIZE);
	char *read_b = malloc(BUFF_SIZE);
	get_next_line(fd, &read_b);
//	printf("%s", read_b);
	free(read_b);
}