/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:10:40 by souchen           #+#    #+#             */
/*   Updated: 2021/12/03 15:36:55 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	checklines(char **str, char **line)
{
	char	*tmp_str;
	int		i;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	if ((*str)[i] == '\0')
		return (0);
	*line = ft_substr(*str, 0, i + 1);
	tmp_str = ft_strdup(&(*str)[i + 1]);
	free(*str);
	*str = NULL;
	*str = tmp_str;
	if (*str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

static char	*checkstatic(char **str, char *line)
{
	if (*str)
	{
		if (ft_strchr(*str, '\n'))
		{
			checklines(str, &line);
			return (line);
		}
		else
		{
			line = ft_strdup(*str);
			free (*str);
			*str = NULL;
			return (line);
		}
	}
	return (NULL);
}

static void	func(char **str, char *buf, int nb)
{
	char	*test;

	buf[nb] = '\0';
	if (*str != NULL)
	{
		test = *str;
		*str = ft_strjoin(*str, buf);
		free(test);
		test = NULL;
	}
	else
		*str = ft_strdup(buf);
}

static int	allocation(char **buf, int fd)
{
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (1);
	*buf = malloc(BUFFER_SIZE + 1);
	if (!(*buf))
		return (1);
	return (0);
}

char	*get_next_line(int fd)
{
	int				nb;
	char			*line;
	static char		*str;
	char			*buf;

	nb = 1;
	if (allocation(&buf, fd))
		return (NULL);
	while (nb > 0)
	{
		nb = read(fd, buf, BUFFER_SIZE);
		if (nb <= 0)
			break ;
		func(&str, buf, nb);
		if (checklines(&str, &line))
		{
			free(buf);
			return (line);
		}
	}
	free(buf);
	return (checkstatic(&str, line));
}
