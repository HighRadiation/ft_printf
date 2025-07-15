/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 20:03:57 by boksuz            #+#    #+#             */
/*   Updated: 2025/07/15 14:02:11 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_format(char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (c == 's')
		return (ft_putst(va_arg(*args, char *)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(*args, unsigned int)));
	if (c == 'x')
		return (ft_puthex(va_arg(*args, unsigned int), 0));
	if (c == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), 1));
	if (c == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}