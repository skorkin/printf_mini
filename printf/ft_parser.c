/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:52:00 by bzelda            #+#    #+#             */
/*   Updated: 2021/01/31 19:14:02 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	simple_trans(const char **fmt, t_info *cont, char type)
{
	int		num;

	num = 0;
	while (ftp_strchr("0123456789", **fmt))
	{
		num = num * 10 + (**fmt - '0');
		(*fmt)++;
	}
	if (type == 'p')
		cont->flg_prec = num;
	else if (type == 'w')
		cont->flg_width = num;
}

int			find_spec(const char **fmt, t_info *cont)
{
	if (ftp_strchr("cspdiuxX%", **fmt))
	{
		cont->type = **fmt;
		(*fmt)++;
		return (1);
	}
	else if (**fmt == '0' || **fmt == '-')
	{
		if (**fmt == '0')
			cont->flg_zero = 1;
		else
			cont->flg_minus = 1;
		(*fmt)++;
	}
	return (0);
}

void		find_width(const char **fmt, t_info *cont)
{
	while (ftp_strchr("*0123456789-", **fmt))
	{
		if (**fmt == '*')
		{
			cont->flg_width = va_arg(*(cont->args), int);
			(*fmt)++;
		}
		else if (ftp_strchr("123456789", **fmt))
			simple_trans(fmt, cont, 'w');
		else
			find_spec(fmt, cont);
	}
}

void		find_precision(const char **fmt, t_info *cont)
{
	if (**fmt == '.')
	{
		cont->flg_prec = 0;
		(*fmt)++;
		while (ftp_strchr("*0123456789-", **fmt))
		{
			if (**fmt == '*')
			{
				cont->flg_prec = va_arg(*(cont->args), int);
				(*fmt)++;
			}
			else if (ftp_strchr("0123456789", **fmt))
				simple_trans(fmt, cont, 'p');
			else
				find_spec(fmt, cont);
		}
	}
}

void		ft_parser(const char **fmt, t_info *cont)
{
	while (**fmt)
	{
		if (find_spec(fmt, cont))
			break ;
		else
		{
			find_width(fmt, cont);
			find_precision(fmt, cont);
		}
		if (!(ftp_strchr("0123456789-*0cspdiuxX%", **fmt)))
		{
			cont->type = **fmt;
			(*fmt)++;
			break ;
		}
	}
}
