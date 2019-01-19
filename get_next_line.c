#include <stdio.h>
#include <sys/wait.h>
#include "get_next_line.h"

size_t get_int(const char *str, size_t i)
{
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

char *send_result(char *str, char **line)
{
	size_t i;
	char *del;
	char *tmp;

	i = 0;
	tmp = ft_strnew(0);
	i = get_int(str, i);
	del = tmp;
	tmp = ft_strsub(str, (unsigned int) (i + 1), ft_strlen(&str[i]));
	(*line) = ft_strsub(str, 0, (size_t) i);
	ft_strdel(&del);
	ft_strdel(&str);
	return (tmp);
}

int readler(char **buf, char **str, char **tmp)
{
	*tmp = ft_strdup(*str);
	ft_strdel(str);
	*str = ft_strjoin(*tmp, *buf);
	ft_strdel(tmp);
	bzero(*buf, BUFF_SIZE);
	return (!ft_strchr(*buf, '\n'));
}

int get_next_line(const int fd, char **line)
{
	char *buf;
	static char *str[MAX_UNIX_KERNEL_FD_COUNT];
	char *tmp;
	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
	{
		ft_strdel(buf);
		return (-1);
	}
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	if (!ft_strchr(str[fd], '\n'))
	{
		while (read(fd, buf, BUFF_SIZE) > 0 && readler(&buf, &str[fd], &tmp))
			;
		ft_strdel(&buf);
	}
	if (*str[fd] != '\0')
	{
		str[fd] = send_result(str[fd], line);
		return (1);
	}
	return (0);
}
