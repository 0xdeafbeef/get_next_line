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

void free_m(char **b, char **c)
{
	free(*b);
	free(*c);
	*b = 0x0;
	*c = 0x0;
}

void init(char **strg, char **cr_line, char **redd, int *resp)
{
	*redd = ft_strnew(BUFF_SIZE);
	*cr_line = ft_strnew(BUFF_SIZE);
	if (*strg == 0x0)
		*strg = ft_strnew(0);
	*resp = 1;
}

char *parse_and_cut(char **stor, char **cr_line, char **redd)
{
	char *temp;
//	if (ft_strchr(*stor, '\n') == 0x0)
//		return ft_strjoin(*cr_line, *redd);
	if (*redd != 0x0)
	{
		temp = ft_strjoin(*cr_line, *redd); //here we joines redd and buff
		*cr_line = ft_strjoin(*stor, temp);// and here
		free_m(stor, &temp);//+
		*stor = ft_strdup(*cr_line);
		free(*cr_line);
	} else
	{
		temp = ft_strdup(*cr_line);
	}

	if (ft_strchr(*stor, '\n') != 0x0)
	{
		temp = ft_strcopy_until(*stor, '\n');
		*cr_line = ft_strsub(ft_strchr(*stor, '\n'), 1,
							 ft_strlen(ft_strchr(*stor, '\n')));
		free(*stor);
		*stor = ft_strdup(*cr_line);
	}

	free(*cr_line);
	return (temp);
}

char *read_logics(char **cr_line, char **redd, char **temp)
{
	if (!*temp)
		free(*temp);
	*temp = ft_strdup(*cr_line);
	free(*cr_line);
	*cr_line = ft_strjoin(*temp, *redd);
	free(*temp);
	ft_bzero(*redd, BUFF_SIZE);
	return (*cr_line);
}

int get_next_line(const int fd, char **line)
{
	static char *storage[590432];
	char *cr_line;
	char *redd;
	char *temp;
	int response;

	if (fd == -1)
		return (-1);
	init(&storage[fd], &cr_line, &redd, &response);
	if (ft_strchr(storage[fd], '\n') == 0x0)
		while ((response = (int) read(fd, redd, BUFF_SIZE)) != 0 &&
			   ft_strchr(redd, 10) == 0x0)
			cr_line = read_logics(&cr_line, &redd, &temp);
	if (response == 0)
	{
		free(redd);
		redd = 0x0;
		*line = parse_and_cut(&storage[fd], &cr_line, &redd);
		free(storage[fd]);
		return (0);
	}
	*line = parse_and_cut(&storage[fd], &cr_line, &redd);
	return (1);
}