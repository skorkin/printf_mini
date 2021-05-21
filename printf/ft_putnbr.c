/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 12:50:54 by bzelda            #+#    #+#             */
/*   Updated: 2021/01/31 19:43:00 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("2147483648", fd);
		return ;
	}
	if (n < 0)
		n = n * (-1);
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(((n % 10) + '0'), fd);
}

void	ft_putnbr_u(unsigned int n, int fd)
{
	if (n >= 10)
		ft_putnbr_u(n / 10, fd);
	ft_putchar_fd(((n % 10) + '0'), fd);
}

void	ft_putnbr_x(unsigned int n, int fd, t_info *control)
{
	const char	*conv;

	if (control->type == 'x')
		conv = "0123456789abcdef";
	else
		conv = "0123456789ABCDEF";
	if (n >= 16)
		ft_putnbr_x(n / 16, fd, control);
	ft_putchar_fd((conv[n % 16]), fd);
}

void	ft_putnbr_p(unsigned long n, int fd)
{
	const char	*conv;

	conv = "0123456789abcdef";
	if (n >= 16)
		ft_putnbr_p(n / 16, fd);
	ft_putchar_fd((conv[n % 16]), fd);
}
