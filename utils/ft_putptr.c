/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: boksuz <boksuz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:39:15 by boksuz            #+#    #+#             */
/*   Updated: 2025/07/24 17:54:37 by boksuz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex((unsigned long)ptr, "0123456789abcdef");
	return (len);
}
