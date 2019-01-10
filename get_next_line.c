/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 19:05:16 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/02 19:20:45 by odm3n            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "get_next_line.h"

void concat(char *crnt,char **storage,char **temp,ssize_t resp)
{
	crnt[resp] =0;
	*temp = *storage;
	*storage = ft_strjoin(*storage,crnt);
	free(*temp);
}

int		get_next_line(const int fd, char **line)
{
	ssize_t		resp;
	char		crnt[BUFF_SIZE + 1];
	static char	*str[MAX_LINUX_KERNEL_FD_COUNT];
	int			len;
	char		*tmp;

	if (fd < 0 || (!str[fd] && !(str[fd] = ft_strnew(1))))
		return (-1);
	while (!ft_strchr(str[fd], '\n') && (resp = read(fd, crnt,BUFF_SIZE)) > 0)
		concat(crnt,&str[fd],&tmp,resp);
	if (resp == -1 || !*(tmp = str[fd]))
		return (resp == -1 ? -1 : 0);
	if ((len = ft_strchr(str[fd], '\n') != 0x0))
		*line = ft_strsub(str[fd], 0, ft_strchr(str[fd], '\n') - str[fd]);
	else
		*line = ft_strdup(str[fd]);
	str[fd] = ft_strsub(str[fd], (unsigned int)(ft_strlen(*line) + len),
						(size_t)(ft_strlen(str[fd]) - (ft_strlen(*line) + len)));
	ft_strdel(&tmp);
	return (!(!str[fd] && !ft_strnlen(*line,0xFFFFFFFF-1)));
}

int main()
{


	char 	*line;
	int		out;
	int		p[2];
	char 	*str;
	int		len = 50;

	str = (char *)malloc(1000 * 1000);
	*str = '\0';
	while (len--)
		strcat(str, "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Curabitur in leo dignissim, gravida leo id, imperdiet urna. Aliquam magna nunc, maximus quis eleifend et, scelerisque non dolor. Suspendisse augue augue, tempus");
	out = dup(1);
	pipe(p);
	dup2(p[1], 1);

	if (str)
		write(1, str, strlen(str));
	close(p[1]);
	dup2(out, 1);
	get_next_line(p[0], &line);
	printf("%d",strcmp(line, str) == 0);
}

