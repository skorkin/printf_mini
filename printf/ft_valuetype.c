/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valuetype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:51:44 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 18:26:50 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_transf_decimal(t_info *control)
{
	long			decimal;

	decimal = 0;
	decimal = (long)va_arg(*(control->args), int);
	len_d(decimal, control);
	if (decimal == 0 && control->flg_prec == 0)
		control->actlen = 0;
	if (control->flg_prec >= 0)
		if (control->flg_prec > control->actlen)
			control->diffprec = control->flg_prec - control->actlen;
	if (control->flg_width > control->actlen + control->diffprec +
	control->prefminus)
		control->diffwidth = control->flg_width - control->actlen -
		control->diffprec - control->prefminus;
	control->out_len += control->actlen + control->diffprec +
	control->diffwidth + control->prefminus;
	useforvalues(control, decimal);
}

void				ft_transf_unsigned(t_info *control)
{
	unsigned int	decimal;

	decimal = 0;
	decimal = va_arg(*(control->args), unsigned int);
	len_u(decimal, control);
	if (decimal == 0 && control->flg_prec == 0)
		control->actlen = 0;
	if (control->flg_prec >= 0)
		if (control->flg_prec > control->actlen)
			control->diffprec = control->flg_prec - control->actlen;
	if (control->flg_width > control->actlen + control->diffprec)
		control->diffwidth = control->flg_width - control->actlen -
		control->diffprec;
	control->out_len += control->actlen + control->diffprec +
	control->diffwidth;
	useforvalues_u(control, decimal);
}

void				ft_transf_hexes(t_info *control)
{
	unsigned int	decimal;

	decimal = 0;
	decimal = va_arg(*(control->args), unsigned int);
	len_x(decimal, control);
	if (decimal == 0 && control->flg_prec == 0)
		control->actlen = 0;
	if (control->flg_prec >= 0)
		if (control->flg_prec > control->actlen)
			control->diffprec = control->flg_prec - control->actlen;
	if (control->flg_width > control->actlen + control->diffprec)
		control->diffwidth = control->flg_width - control->actlen -
		control->diffprec;
	control->out_len += control->actlen + control->diffprec +
	control->diffwidth;
	useforvalues_x(control, decimal);
}

void				ft_transf_pointer(t_info *control)
{
	unsigned long	decimal;

	decimal = 0;
	decimal = va_arg(*(control->args), unsigned long);
	len_p(decimal, control);
	if (decimal == 0 && control->flg_prec == 0)
		control->actlen = 0;
	if (control->flg_prec >= 0)
		if (control->flg_prec > control->actlen)
			control->diffprec = control->flg_prec - control->actlen;
	if (control->flg_width > control->actlen + control->diffprec + 2)
		control->diffwidth = control->flg_width - control->actlen - control->
		diffprec - 2;
	control->out_len += control->actlen + control->diffprec +
	control->diffwidth + 2;
	useforvalues_p(control, decimal);
}
