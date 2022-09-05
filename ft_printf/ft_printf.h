/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: numussan <numussan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 00:27:32 by numussan          #+#    #+#             */
/*   Updated: 2022/05/13 00:59:10 by numussan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_printf(const char *str, ...);
int	ft_conversions(va_list ar, char ch);
int	ft_putchar(char ch);
int	ft_putstr(char *str);
int	ft_putuint(unsigned int n);
int	ft_putnbr(int n);
int	ft_puthex(unsigned int n, char ch);
int	ft_putpointer(unsigned long n);
int	ft_lenpointer(unsigned long n);

#endif
