

#include "get_next_line.h"
#include <stdio.h>

char *send_result(char *str, char **line)
{
	int i;
	char *del;
	char *tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	del = tmp;
	tmp = ft_strsub(str, (unsigned int) (i + 1), ft_strlen(&str[i]));
	(*line) = ft_strsub(str, 0, (size_t) i);
	ft_strdel(&del);
	ft_strdel(&str);
	return (tmp);
}

int get_next_line(const int fd, char **line)
{
	char *buf;
	static char *str[MAX_UNIX_KERNEL_FD_COUNT];
	char *tmp;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
	{
		ft_strdel(str);
		return (-1);
	}
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && read(fd, buf, BUFF_SIZE) > 0)
	{
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	if (*str[fd] != '\0')
	{
		str[fd] = send_result(str[fd], line);
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}

int main()
{
	char *line;
	int fd;
	int fd2;
	int fd3;
	int diff_file_size;

	system("mkdir -p sandbox");
	system("openssl rand -base64 $((30 * 1000 * 3/4)) | tr -d '\n' | tr -d '\r' > sandbox/one_big_fat_line.txt");
	system("echo '\n' >> sandbox/one_big_fat_line.txt");

	fd = open("sandbox/one_big_fat_line.txt", O_RDONLY);
	fd2 = open("sandbox/one_big_fat_line.txt.mine", O_CREAT | O_RDWR | O_TRUNC,
			   0755);

	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, "\n", 1);
	}
	if (line)
		write(fd2, line, strlen(line));
	close(fd);
	close(fd2);

	system("diff sandbox/one_big_fat_line.txt sandbox/one_big_fat_line.txt.mine > sandbox/one_big_fat_line.diff");
	fd3 = open("sandbox/one_big_fat_line.diff", O_RDONLY);
	diff_file_size = read(fd3, NULL, 10);
	close(fd3);


}
