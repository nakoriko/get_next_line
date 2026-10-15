/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:40:49 by nakoriko          #+#    #+#             */
/*   Updated: 2024/03/11 12:40:50 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}

void	*ft_bzero(void *s, size_t n)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

char	*ft_strjoin(char *stack, char *buffer)
{
	size_t		i;
	size_t		j;
	char		*p;
	int			slen;

	slen = ft_strlen(stack);
	p = (char *)malloc(sizeof(char) * (slen + ft_strlen(buffer) + 1));
	if (p == 0)
	{
		free(p);
		free(stack);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (stack && stack[i])
	{
		p[i] = stack[i];
		i++;
	}
	while (buffer && buffer[j])
		p[i++] = buffer[j++];
	p[i] = '\0';
	free(stack);
	return (p);
}

char	*ft_strcpy(char *line, const char *stack)
{
	int	i;

	i = 0;
	while (stack[i] != '\n' && stack[i])
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
