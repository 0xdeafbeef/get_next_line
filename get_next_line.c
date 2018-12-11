
#include <fcntl.h>
#include <printf.h>
#include "get_next_line.h"
#include "libft.h"
#include "unistd.h"


int get_next_line(const int fd, char **line)
{
	static t_list *node;
	char *s;
	int i;
	char *temp;

	temp = NULL;
	i = 0;
	s = ft_strnew(BUFF_SIZE);
	read(fd, s, BUFF_SIZE);
	node = ft_lstnew(s, BUFF_SIZE);
	while (1)
	{
		while (s[i] != '\n' && s[i] != EOF && i <= BUFF_SIZE)
			i++;
		if (s[i] != '\n' && s[i] != EOF)
			break;
		else
			read(fd, s, BUFF_SIZE);
		temp = ft_strjoinf(s, temp);
	}

	*line = temp;
	return 0;
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY, BUFF_SIZE);
	char *read_b = malloc(BUFF_SIZE * 1024);
	get_next_line(fd, &read_b);
//	printf("%s", read_b);
	free(read_b);
}