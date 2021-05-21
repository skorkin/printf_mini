/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:51:48 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 19:38:25 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ftp_strchr(char *s, int sym)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == sym)
			return (s);
		s++;
	}
	return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void		ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (!s || fd == (-1))
		return ;
	write(fd, s, ft_strlen(s));
}
