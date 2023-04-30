/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoro-sa <imoro-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 11:04:48 by imoro-sa          #+#    #+#             */
/*   Updated: 2023/02/19 15:47:42 by imoro-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>

char		*get_next_line(int fd);
char		*ft_read(int fd, char *static_buffer);
char		*ft_return_line(char *static_buffer);
char		*ft_return_static_buffer(char *static_buffer);

size_t		ft_strlen(const char *s);
char		*ft_malloc(size_t nmemb);
char		*ft_strchr(const char *s, int c);
char		*ft_strjoin(char *s1, char *s2, long int bytes_read);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*ft_memcpy(char *src);

#endif