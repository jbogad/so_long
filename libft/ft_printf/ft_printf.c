/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:32:08 by marvin            #+#    #+#             */
/*   Updated: 2025/05/09 13:51:22 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conversion(va_list vl, const char str)
{
	int	char_printed;

	char_printed = 0;
	if (str == 'c')
		char_printed += ft_putchar(va_arg(vl, int));
	else if (str == 's')
		char_printed += ft_putstr(va_arg(vl, char *));
	else if (str == 'p')
		char_printed += ft_putptr(va_arg(vl, unsigned long));
	else if (str == 'd' || str == 'i')
		char_printed += ft_putnbr(va_arg(vl, int));
	else if (str == 'u')
		char_printed += ft_putunsigned(va_arg(vl, unsigned int));
	else if (str == 'x' || str == 'X')
		char_printed += ft_puthex(va_arg(vl, unsigned int), str);
	else if (str == '%')
		char_printed += ft_putchar('%');
	return (char_printed);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	vl;
	int		char_printed;

	i = 0;
	char_printed = 0;
	va_start(vl, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			char_printed += ft_conversion(vl, str[i + 1]);
			i++;
		}
		else
			char_printed += ft_putchar(str[i]);
		i++;
	}
	va_end(vl);
	return (char_printed);
}
