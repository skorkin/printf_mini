/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numcount.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:52:01 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 18:21:04 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	len_d(long n, t_info *control)
{
	long	i;

	i = 0;
	if (n < 0)
		control->prefminus = 1;
	if (!n)
	{
		control->actlen = 1;
		if (control->flg_prec == 0)
			control->actlen = 0;
	}
	else
	{
		while (n)
		{
			n = n / 10;
			i++;
		}
		control->actlen = i;
	}
}

void	len_u(unsigned int n, t_info *control)
{
	int i;

	i = 0;
	if (!n)
	{
		control->actlen = 1;
		if (control->flg_prec == 0)
			control->actlen = 0;
	}
	else
	{
		while (n)
		{
			n = n / 10;
			i++;
		}
		control->actlen = i;
	}
}

void	len_x(unsigned int n, t_info *control)
{
	int i;

	i = 0;
	if (!n)
	{
		control->actlen = 1;
		if (control->flg_prec == 0)
			control->actlen = 0;
	}
	else
	{
		while (n)
		{
			n = n / 16;
			i++;
		}
		control->actlen = i;
	}
}

void	len_p(unsigned long n, t_info *control)
{
	int i;

	i = 0;
	if (!n)
	{
		control->actlen = 1;
		if (control->flg_prec == 0)
			control->actlen = 0;
	}
	else
	{
		while (n)
		{
			n = n / 16;
			i++;
		}
		control->actlen = i;
	}
}
