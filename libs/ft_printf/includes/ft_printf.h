/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:41:14 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:52:56 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "ft_printf_defines.h"
# include "ft_printf_typedefs.h"

int				ft_printf(const char *format, ...);
int				ft_fprintf(FILE *stream, const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_vprintf(const char *format, va_list ap);
int				ft_vfprintf(FILE *stream, const char *format, va_list ap);
int				ft_vdprintf(int fd, const char *format, va_list ap);

void			ptf_buff_add_char(t_buff *buff, const char *format);
void			ptf_buff_add_uchar(t_buff *buff, unsigned char wchar);
void			ptf_buff_add_str(t_buff *buff, char *add, unsigned int len);
void			ptf_buff_flush(t_buff *buff);
void			ptf_buff_init(t_buff *buff, int fd);

const char		*ptf_get_flags(t_flags *flags, const char *format, va_list ap);

void			ptf_lltoa_base(t_flags *flags, t_conv *d, int base);

void			ptf_put_str(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_wstr(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_ptr(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_dec(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_ldec(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_oct(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_loct(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_udec(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_ludec(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_hex(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_mhex(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_char(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_wchar(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_bin(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_arbs(t_flags *flags, t_buff *buff, va_list ap);
void			ptf_put_ret(t_flags *flags, t_buff *buff, va_list ap);

uintmax_t		ptf_select_cast(t_flags *flags, va_list ap);
uintmax_t		ptf_select_ucast(t_flags *flags, va_list ap);

char			**ptf_sgl_colors(void);
void			(**g_ptf_sgl_hash(void))(t_flags *, t_buff *, va_list);

long long		ptf_abs(long long n);
int				ptf_isalpha(int c);
int				ptf_isdigit(int c);
int				ptf_isflag(char c);

size_t			ptf_strlen(const char *s);
int				ptf_wcharlen(wchar_t wchar);
int				ptf_wstrlen(wchar_t *wstr);
size_t			ptf_numlen_base(intmax_t n, int base);
size_t			ptf_numlen_ubase(uintmax_t n, int base);

void			ptf_write_num(t_flags *flags, t_buff *buff, t_conv *num);

#endif
