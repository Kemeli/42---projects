/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 18:49:42 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/08/02 22:15:48 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

void	ft_putnbr(int n)
{
	unsigned int	num;

	num = n;
	if (n < 0)
	{
		ft_putchar('-');
		num = n * -1;
	}
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

void	ft_putnbr_unsigned(unsigned int n)
{
	unsigned int	num;

	num = n;
	if (num > 9)
		ft_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
}

int	ft_putptr(unsigned long n)
{
	int		len;
	char	*str;

	if (!n)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	str = ft_itoa((size_t)n);
	ft_putstr("0x");
	ft_putstr(str);
	len = ft_strlen(str) + 2;
	free(str);
	return (len);
}
