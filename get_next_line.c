
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

#define BUFF_SIZE 32

int get_next_line(const int fd, char **line)
{
	read(fd, line, BUFF_SIZE);
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDWR, BUFF_SIZE);
	char *read_b = malloc(BUFF_SIZE);
	get_next_line(fd, &read_b);
}