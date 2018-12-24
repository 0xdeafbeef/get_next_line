/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:13:52 by qhetting          #+#    #+#             */
/*   Updated: 2018/12/02 17:16:15 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*tmp;
	int		l;

	l = ft_strlen(src);
	i = -1;
	tmp = (char*)malloc(l + 1);
	if (tmp == NULL)
		return (tmp);
	while (++i < l)
		*(tmp + i) = *(src + i);
	*(tmp + i) = '\0';
	return (tmp);
}
