/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_number_hex.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaboga-d <jaboga-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:32:00 by marvin            #+#    #+#             */
/*   Updated: 2025/02/09 09:52:25 by jaboga-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int num, char str)
{
	int	len;

	len = 1;
	if (num == 0)
		return (write(1, "0", 1));
	if (num >= 16)
		len += ft_puthex(num / 16, str);
	if (num % 16 < 10)
		ft_putchar(num % 16 + '0');
	else
	{
		if (str == 'x')
			ft_putchar(num % 16 + 'a' - 10);
		else
			ft_putchar(num % 16 + 'A' - 10);
	}
	return (len);
}
