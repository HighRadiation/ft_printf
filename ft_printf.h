/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 19:21:51 by boksuz            #+#    #+#             */
/*   Updated: 2025/07/15 17:58:09 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putnbr(int n);
int		ft_putchar(char c);
int		ft_putptr(void *ptr);
int		ft_putstr(const char *s);
int		ft_putunbr(unsigned int n);
int		ft_format(char c, va_list *args);
int		ft_printf(const char *format, ...);
int		ft_puthex(unsigned long n, int upper);

#endif