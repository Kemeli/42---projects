/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaiane- < kdaiane-@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 03:37:32 by kdaiane-          #+#    #+#             */
/*   Updated: 2022/07/17 21:12:03 by kdaiane-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] != (c % 256) && s[i] != '\0')
	{
		s++;
	}
	if (s[i] == '\0' && (c % 256) != '\0')
	{
		return (0);
	}
	return ((char *) s);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	if (!s)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	hold1;
	size_t	hold2;
	char	*new;

	hold1 = ft_strlen(s1);
	hold2 = ft_strlen(s2);
	new = malloc(sizeof(char) * (hold1 + hold2 + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
	{
		new[i] = s1[i];
	}
	j = 0;
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		i++;
		j++;
	}	
	new[i] = '\0';
	return (new);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dst != src && n)
	{
		while (++i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		}
	}
	return (dst);
}

char	*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*new;

	len = ft_strlen(s);
	new = malloc((len + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new = ft_memcpy(new, s, len);
	new[len] = '\0';
	return (new);
}
