/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useparameters_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 19:42:44 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 18:23:44 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		useforstring(t_info *control, char *str)
{
	if (control->flg_minus == 1)
	{
		write(1, str, control->actlen);
		write_i_char(1, " ", control->diffwidth);
	}
	else
	{
		if (control->flg_zero == 0)
			write_i_char(1, " ", control->diffwidth);
		if (control->flg_zero == 1)
			write_i_char(1, "0", control->diffwidth);
		write(1, str, control->actlen);
	}
}

void		useforchar(t_info *control, char sym)
{
	if (control->flg_minus == 1)
	{
		write(1, &sym, control->actlen);
		write_i_char(1, " ", control->diffwidth);
	}
	else
	{
		if (control->flg_zero == 0)
			write_i_char(1, " ", control->diffwidth);
		if (control->flg_zero == 1)
			write_i_char(1, "0", control->diffwidth);
		write_i_char(1, &sym, control->actlen);
	}
}
