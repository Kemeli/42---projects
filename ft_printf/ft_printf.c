/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 14:41:36 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/08/01 22:14:30 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_symbols(va_list ptr, const char symbols)
{
	int	len;

	len = 0;
	if (symbols == 'c')
		len = ft_putchar(va_arg(ptr, int));
	else if (symbols == 's')
		len = ft_putstr(va_arg(ptr, char *));
	else if (symbols == 'p')
		len = ft_putptr(va_arg(ptr, unsigned long));
	else if (symbols == 'd')
		len = ft_printnbr(va_arg(ptr, int));
	else if (symbols == 'i')
		len = ft_printnbr(va_arg(ptr, unsigned int));
	else if (symbols == 'u')
		len = ft_print_unsigned((unsigned int)va_arg(ptr, unsigned int));
	else if (symbols == 'x')
		len = ft_print_hexa((unsigned int)va_arg(ptr, int), 0);
	else if (symbols == 'X')
		len = ft_print_hexa((unsigned int)va_arg(ptr, int), 1);
	else if (symbols == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *symbols, ...)
{
	va_list	ptr;
	int		size;
	int		i;

	va_start(ptr, symbols);
	i = 0;
	size = 0;
	if (!symbols)
		return (-1);
	while (symbols && symbols[i])
	{
		if (symbols[i] == '%')
		{
			i++;
			size += ft_symbols(ptr, symbols[i]);
		}
		else
			size += ft_putchar(symbols[i]);
		i++;
	}
	va_end(ptr);
	return (size);
}
