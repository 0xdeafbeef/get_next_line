
#include "get_next_line.h"

REDD;

char		*send_result(char *str, char **line)
{
	size_t	i;
	char	*del;
	char	*tmp;

	i = 0;
	tmp = ft_strnew(0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	del = tmp;
	tmp = ft_strsub(str, (unsigned int)(i + 1), ft_strlen(&str[i]));
	(*line) = ft_strsub(str, 0, (size_t)i);
	ft_strdel(&del);
	ft_strdel(&str);
	return (tmp);
}

int			READ
{
	READ_BODY;
	READ_BODY1;
	READ_BODY2;

	return (!ft_strchr(buf, '\n'));
}

int			get_next_line(const int fd, char **line)
{
	FRST;
	static char	*str[MAX_UNIX_KERNEL_FD_COUNT];
	char		*tmp;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
	{
		CLEAR;
		return (-1);
	}
	if (str[fd] == NULL)
		str[fd] = ft_strnew(0);
	if (!ft_strchr(str[fd], '\n'))
	{
		while ((RREDD = (int)read(fd, buf, BUFF_SIZE)) > 0 && READLER)
			;
		CLEAR;
	}
	if (*str[fd] != '\0')
	{
		str[fd] = send_result(str[fd], line);
		return (1);
	}
	return (0);
}
