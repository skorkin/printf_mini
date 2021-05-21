/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_definerules.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:52:02 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 18:26:50 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	definerules(t_info *control)
{
	if (control->type == 'd' || control->type == 'i')
		ft_transf_decimal(control);
	else if (control->type == 's')
		ft_transfstring(control);
	else if (control->type == 'c')
		ft_transfschar(control);
	else if (control->type == 'x' || control->type == 'X')
		ft_transf_hexes(control);
	else if (control->type == 'u')
		ft_transf_unsigned(control);
	else if (control->type == 'p')
		ft_transf_pointer(control);
	else if (control->type == '%')
		ft_transfschar(control);
	else
		ft_transfschar(control);
}
