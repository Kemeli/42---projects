/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:45:58 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/08/01 18:32:30 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_tostr(char *str, size_t n, int size)
{
	const char	*map = "0123456789abcdef";

	while (size--)
	{
		str[size] = map[n % 16];
		n = n / 16;
	}
	return (str);
}

char	*ft_itoa(size_t n)
{
	char	*str;
	size_t	aux;
	int		size;

	size = 1;
	aux = n / 16;
	while (aux)
	{
		size++;
		aux = aux / 16;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	ft_tostr(str, n, size);
	return (str);
}

static char	*ft_tostr_x(char *str, unsigned int n, int size, char case_x)
{
	const char	*map_lower = "0123456789abcdef";
	const char	*map_upper = "0123456789ABCDEF";

	while (size--)
	{
		if (case_x == 0)
		{
			str[size] = map_lower[n % 16];
			n = n / 16;
		}
		else
		{
			str[size] = map_upper[n % 16];
			n = n / 16;
		}
	}
	return (str);
}

char	*ft_itoa_hexa(unsigned int n, char case_x)
{
	char	*str;
	size_t	aux;
	int		size;

	size = 1;
	aux = n / 16;
	while (aux)
	{
		size++;
		aux = aux / 16;
	}
	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	ft_tostr_x(str, n, size, case_x);
	return (str);
}
