/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringtype.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:51:53 by bzelda            #+#    #+#             */
/*   Updated: 2021/01/31 19:19:52 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_transfstring(t_info *control)
{
	char	*str;

	str = 0;
	str = va_arg(*(control->args), char *);
	if (!str)
		str = "(null)";
	control->actlen = ft_strlen(str);
	if (control->flg_prec >= 0)
		if (control->actlen > control->flg_prec)
			control->actlen = control->flg_prec;
	if (control->flg_width > control->actlen)
		control->diffwidth = control->flg_width - control->actlen;
	control->out_len += control->actlen + control->diffwidth;
	useforstring(control, str);
}

void			ft_transfschar(t_info *control)
{
	char		sym;

	if (control->type == 'c')
		sym = va_arg(*(control->args), int);
	else if (control->type == '%')
		sym = '%';
	else
		sym = control->type;
	control->actlen = 1;
	if (control->flg_width > control->actlen)
		control->diffwidth = control->flg_width - control->actlen;
	control->out_len += control->actlen + control->diffwidth;
	useforchar(control, sym);
}
