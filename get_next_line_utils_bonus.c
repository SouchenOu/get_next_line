/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:58:31 by souchen           #+#    #+#             */
/*   Updated: 2021/11/29 16:08:31 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *src)
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
	char	*str;
	size_t	i;

	i = 0;
	if ((long int)len < 0 || !s)
		return (NULL);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	str = (char *)malloc (sizeof(char) * len + 1);
	if (!str)
		return (0);
	if (start > ft_strlen(s))
	{
		str[0] = '\0';
		return (str);
	}
	while (i < len && s[start])
	{
		str[i] = s[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
