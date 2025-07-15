/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:36:28 by boksuz            #+#    #+#             */
/*   Updated: 2025/07/15 15:37:05 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(unsigned long n, int upper)
{
    char *base;
	
	base = upper ? "0123456789ABCDEF" : "0123456789abcdef";
    int len = 0;
    if (n >= 16)
        len += ft_puthex(n / 16, upper);
    len += ft_putchar(base[n % 16]);
    return (len);
}