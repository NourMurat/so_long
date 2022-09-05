/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 06:06:21 by numussan          #+#    #+#             */
/*   Updated: 2022/05/13 00:33:54 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_lenpointer(unsigned long n)
{
	int	len;

	len = 1;
	if (n >= 16)
		len += ft_lenpointer(n / 16);
	if (n % 16 < 10)
		ft_putchar(n % 16 + '0');
	else
		ft_putchar(n % 16 - 10 + 'a');
	return (len);
}

int	ft_putpointer(unsigned long n)
{
	int	len;

	ft_putstr("0x");
	len = ft_lenpointer(n);
	return (len + 2);
}

int	ft_puthex(unsigned int n, char ch)
{
	int	len;

	len = 1;
	if (n >= 16)
		len += ft_puthex(n / 16, ch);
	if (n % 16 < 10)
		ft_putchar((n % 16) + '0');
	else
	{
		if (ch == 'x')
			ft_putchar((n % 16) - 10 + 'a');
		if (ch == 'X')
			ft_putchar((n % 16) - 10 + 'A');
	}
	return (len);
}
