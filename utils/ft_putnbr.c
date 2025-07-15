/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:38:17 by boksuz            #+#    #+#             */
/*   Updated: 2025/07/15 15:38:26 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putnbr(int n)
{
    char c;
    int len;
	
	len = 0;
    if (n == -2147483648)
        return ft_putstr("-2147483648");
    if (n < 0) 
	{
        len += ft_putchar('-');
        n = -n;
    }
    if (n >= 10)
        len += ft_putnbr(n / 10);
    c = n % 10 + '0';
    len += ft_putchar(c);
    return (len);
}