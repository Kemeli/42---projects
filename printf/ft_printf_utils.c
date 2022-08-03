/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:28:37 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/08/01 18:34:06 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

unsigned long	ft_printnbr(int nbr)
{
	char	len;

	len = 0;
	if (nbr < 0)
		len++;
	ft_putnbr(nbr);
	if (nbr <= -2147483648)
		return (11);
	if (nbr >= 0 && nbr <= 9)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

int	ft_print_hexa(int n, int case_x)
{
	int		len;
	char	*str;

	str = ft_itoa_hexa((size_t)n, case_x);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}

unsigned long	ft_print_unsigned(unsigned int nbr)
{
	char	len;

	len = 0;
	ft_putnbr_unsigned(nbr);
	if (nbr >= 0 && nbr <= 9)
		return (1);
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}
