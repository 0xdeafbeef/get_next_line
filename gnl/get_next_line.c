#include <stdio.h>
#include "get_next_line.h"
#include <locale.h>
void free_a(char *a, char *b, char *c)
{
	free(a);
	free(b);
	free(c);
	a = 0x0;
	b = 0x0;
	c = 0x0;
}

char *getString(char *cr_line, const char *redd, char *temp)
{
	temp = ft_strdup(cr_line);
	free(cr_line);
	cr_line = ft_strjoin(temp, redd);
	free(temp);
	return cr_line;
}

char *magic(const int fd, char **storage, char *cr_line, char *temp)
{
	cr_line = ft_strdup(temp); // same
	free(temp);
	temp = ft_strjoin(storage[fd], cr_line); //cr_line +
	free(&storage[fd]);
	storage[fd] = ft_strdup(temp); // all with \n
	free(temp);
	return cr_line;
}

void init(const int fd, char **storage, char **cr_line, char **redd)
{
	(*redd) = ft_strnew(BUFF_SIZE);
	(*cr_line) = ft_strnew(BUFF_SIZE);
	if (storage[fd] == NULL)
		storage[fd] = (*cr_line);
}

int get_next_line(const int fd, char **line)
{
	static char *storage[590432];
	char *cr_line;
	char *redd;
	char *temp;
	int response;

	temp = 0x0;
	if (fd == -1)
		return -1;
	init(fd, storage, &cr_line, &redd);
	while (ft_strchr(storage[fd], '\n') == 0x0 &&(response =
			(int)read(fd, redd, BUFF_SIZE)) !=0 &&
			ft_strchr(redd, 10) == 0x0)
		cr_line = getString(cr_line, redd, temp);
	if (!response)
		return 0;
	temp = ft_strjoin(cr_line, redd); // here stores what has been read
	cr_line = magic(fd, storage, cr_line, temp);
	if (ft_strchr(storage[fd], '\n') == 0x0)
		temp = ft_strdup((storage[fd]));
	else
		temp = ft_strcopy_until(storage[fd], '\n');
	*line = ft_strdup(temp);
	free(temp);
	temp = ft_strdup(ft_strchr(storage[fd], '\n') + 1);
	storage[fd] = ft_strdup(temp);
	free_a(cr_line, redd, temp);
	return 1;
}

int main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char *read_b = ft_strnew(1024 * 1024);
	while (get_next_line(fd, & read_b))
	{
		printf("%s\n", read_b);
	}
}