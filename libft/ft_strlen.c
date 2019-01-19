/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhetting <qhetting@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 17:28:07 by qhetting          #+#    #+#             */
/*   Updated: 2019/01/19 21:09:31 by qhetting         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strlen.h"

unsigned long int			g_longword;
unsigned long int			g_himagic;
unsigned long int			g_lomagic;

static void					inner(const char *char_ptr,
		const unsigned long **longword_ptr, unsigned long *himagic,
		unsigned long *lomagic)
{
	(*longword_ptr) = (unsigned long int *)char_ptr;
	(*himagic) = 0x80808080L;
	(*lomagic) = 0x01010101L;
	(*himagic) = (((*himagic) << 16) << 16) | (*himagic);
	(*lomagic) = (((*lomagic) << 16) << 16) | (*lomagic);
}

size_t						ft_strlen(const char *str)
{
	const char				*char_ptr;
	const unsigned long	int	*longword_ptr;
	const char				*cp;

	char_ptr = str - 1;
	while (((unsigned long int)char_ptr++ & (sizeof(g_longword) - 1)) != 0)
	{
		if (*char_ptr == '\0')
			return (char_ptr - str);
	}
	inner(char_ptr, &longword_ptr, &g_himagic, &g_lomagic);
	while (1)
	{
		g_longword = *longword_ptr++;
		if (((g_longword - g_lomagic) & ~g_longword & g_himagic) != 0)
		{
			cp = (const char *)(longword_ptr - 1);
			ARR;
			ARR1;
			ARR2;
			ARR3;
		}
	}
}
