/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bzelda <bzelda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 18:51:55 by bzelda            #+#    #+#             */
/*   Updated: 2021/02/01 21:43:18 by bzelda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_info
{
	int			out_len;
	int			flg_minus;
	int			prefminus;
	int			diffwidth;
	int			diffprec;
	int			flg_zero;
	int			flg_width;
	int			flg_prec;
	int			actlen;
	char		type;
	va_list		*args;
}				t_info;

int				ft_printf(const char *fmt, ...);
void			struct_set(t_info *control);
char			*ftp_strchr(char *s, int sym);
void			ft_parser(const char **fmt, t_info *cont);
size_t			ft_strlen(const char *str);
void			definerules(t_info *control);
void			ft_transfstring(t_info *control);
void			ft_transfschar(t_info *control);
void			ft_transf_decimal(t_info *control);
void			ft_transf_unsigned(t_info *control);
void			ft_transf_hexes(t_info *control);
void			ft_transf_pointer(t_info *control);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

void			len_d(long n, t_info *control);
void			len_u(unsigned int n, t_info *control);
void			len_x(unsigned int n, t_info *control);
void			len_p(unsigned long n, t_info *control);

void			ft_putnbr_fd(long n, int fd);
void			ft_putnbr_u(unsigned int n, int fd);
void			ft_putnbr_x(unsigned int n, int fd, t_info *control);
void			ft_putnbr_p(unsigned long n, int fd);

void			write_i_char(int fd, char *sym, int n);
void			useforvalues(t_info *control, long n);
void			useforvalues_u(t_info *control, unsigned int decimal);
void			useforvalues_x(t_info *control, unsigned int decimal);
void			useforvalues_p(t_info *control, unsigned long decimal);

void			useforstring(t_info *control, char *str);
void			useforchar(t_info *control, char sym);

#endif
