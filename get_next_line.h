/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souchen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:36:09 by souchen           #+#    #+#             */
/*   Updated: 2021/12/03 15:41:08 by souchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int ch);

#endif
