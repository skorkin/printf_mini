/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_useparameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:51:49 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 18:23:44 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		write_i_char(int fd, char *sym, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(fd, sym, 1);
		i++;
	}
}

void		useforvalues(t_info *control, long decimal)
{
	if (control->flg_minus == 1)
	{
		if (control->prefminus == 1)
			write_i_char(1, "-", control->prefminus);
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_fd(decimal, 1);
		write_i_char(1, " ", control->diffwidth);
	}
	else
	{
		if (control->flg_zero == 0)
			write_i_char(1, " ", control->diffwidth);
		if (control->prefminus == 1)
			write_i_char(1, "-", control->prefminus);
		if (control->flg_zero == 1)
			write_i_char(1, "0", control->diffwidth);
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_fd(decimal, 1);
	}
}

void		useforvalues_u(t_info *control, unsigned int decimal)
{
	if (control->flg_minus == 1)
	{
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_u(decimal, 1);
		write_i_char(1, " ", control->diffwidth);
	}
	else
	{
		if (control->flg_zero == 0)
			write_i_char(1, " ", control->diffwidth);
		if (control->flg_zero == 1)
			write_i_char(1, "0", control->diffwidth);
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_u(decimal, 1);
	}
}

void		useforvalues_x(t_info *control, unsigned int decimal)
{
	if (control->flg_minus == 1)
	{
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_x(decimal, 1, control);
		write_i_char(1, " ", control->diffwidth);
	}
	else
	{
		if (control->flg_zero == 0)
			write_i_char(1, " ", control->diffwidth);
		if (control->flg_zero == 1)
			write_i_char(1, "0", control->diffwidth);
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_x(decimal, 1, control);
	}
}

void		useforvalues_p(t_info *control, unsigned long decimal)
{
	if (control->flg_minus == 1)
	{
		write(1, "0x", control->prefminus);
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_p(decimal, 1);
		write_i_char(1, " ", control->diffwidth);
	}
	else
	{
		if (control->flg_zero == 0)
			write_i_char(1, " ", control->diffwidth);
		write(1, "0x", control->prefminus);
		if (control->flg_zero == 1)
			write_i_char(1, "0", control->diffwidth);
		write_i_char(1, "0", control->diffprec);
		if (control->actlen != 0)
			ft_putnbr_p(decimal, 1);
	}
}
