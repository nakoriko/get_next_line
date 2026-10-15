/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:48:28 by nakoriko          #+#    #+#             */
/*   Updated: 2024/02/28 11:48:29 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *str);
char	*ft_calloc(size_t nbytes, size_t size);
char	*ft_strjoin(char *stack, char *buffer);
char	*ft_strcpy(char *line, const char *stack);
char	*ft_strchr(const char *s, int c);
void	*ft_bzero(void *s, size_t n);

#endif
