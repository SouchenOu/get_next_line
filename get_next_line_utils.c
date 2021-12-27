/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:49:47 by souchen           #+#    #+#             */
/*   Updated: 2021/12/03 13:42:22 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int ch)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)ch)
	{
		if (s[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return ((char *) s + i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*test;
	int		j;

	j = 0;
	if (!s1)
	{
		return (NULL);
	}
	test = (char *)malloc (sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (test == NULL)
	{
		return (NULL);
	}
	while (*s1 != '\0')
	{
		test[j] = *(s1++);
		j++;
	}
	while (*s2 != '\0')
	{
		test[j++] = *(s2++);
	}
	test[j] = '\0';
	return (test);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	int		i;

	i = 0;
	while (src[i])
		i++;
	dup = (char *)malloc(sizeof(char) * i + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*test;
	size_t	j;
	size_t	i;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	if (len > ft_strlen(s + start))
	{
		len = ft_strlen(s + start);
	}
	test = (char *) malloc ((len + 1) * sizeof(char));
	if (test == NULL)
	{
		return (NULL);
	}
	while (i < ft_strlen(s) && j < len)
	{
		test[j++] = s[i++];
	}
	test[j] = '\0';
	return (test);
}
