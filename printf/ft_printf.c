/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:51:57 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/03 02:56:51 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	struct_set(t_info *control)
{
	control->flg_minus = 0;
	control->prefminus = 0;
	control->flg_zero = 0;
	control->flg_width = 0;
	control->flg_prec = -1;
	control->diffwidth = 0;
	control->diffprec = 0;
	control->actlen = 0;
	control->type = '?';
}

void	struct_redefine(t_info *control)
{
	if (control->flg_width < 0)
	{
		control->flg_width *= (-1);
		control->flg_minus = 1;
	}
	if (control->flg_prec < -1)
		control->flg_prec = -1;
	if (control->flg_prec >= 0 && ftp_strchr("xXupdi", control->type))
		control->flg_zero = 0;
	if (control->flg_minus == 1)
		control->flg_zero = 0;
	if (control->type == 'p')
		control->prefminus = 2;
}

int		ft_printf_helper(t_info *control, const char *rtfm)
{
	while (*rtfm)
	{
		if (*rtfm == '%')
		{
			rtfm++;
			if (*rtfm)
			{
				struct_set(control);
				ft_parser(&rtfm, control);
				struct_redefine(control);
				definerules(control);
			}
		}
		else if (*rtfm)
		{
			write(1, rtfm, 1);
			rtfm++;
			(control->out_len)++;
		}
	}
	return (control->out_len);
}

int		ft_printf(const char *rtfm, ...)
{
	va_list			args;
	t_info			control;
	int				ret;
	char			*f;

	f = (char *)rtfm;
	va_start(args, rtfm);
	control.args = &args;
	control.out_len = 0;
	ret = ft_printf_helper(&control, rtfm);
	va_end(args);
	return (ret);
}
