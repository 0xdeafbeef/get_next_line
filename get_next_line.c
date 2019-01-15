

#include "get_next_line.h"
#include <stdio.h>

char			*send_result(char *str, char **line)
{
	int			i;
	char		*del;
	char		*tmp;

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

int				get_next_line(const int fd, char **line)
{
	char		*buf;
	int			redd;
	static char	*str[4096];
	char		*tmp;

	buf = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	while (!ft_strchr(str[fd], '\n') && (redd = (int) read(fd, buf, BUFF_SIZE)) > 0)
	{
		tmp = str[fd];
		buf[redd] = '\0';
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