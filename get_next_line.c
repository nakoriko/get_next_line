/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nakoriko <nakoriko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 15:53:02 by nakoriko          #+#    #+#             */
/*   Updated: 2024/03/08 10:15:38 by nakoriko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_free(char **buffer, char **stack)
{
	free(*buffer);
	free(*stack);
	*stack = NULL;
}

char	*ft_temp(char *stack, char *buffer, char *line)
{
	char	*temp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	temp = malloc(sizeof(char) * (((ft_strlen(stack)) - i + 1)));
	if (temp == NULL)
	{
		ft_free(&buffer, &stack);
		free(line);
		return (NULL);
	}
	i++;
	while (stack[i])
		temp[j++] = stack[i++];
	temp[j] = '\0';
	ft_free(&buffer, &stack);
	stack = temp;
	return (stack);
}

char	*ft_newline(char *stack, char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	while (stack[i] != '\n' && stack[i])
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (line == NULL)
	{
		ft_free(&buffer, &stack);
		return (NULL);
	}
	line = ft_strcpy(line, stack);
	return (line);
}

char	*ft_calloc(size_t nbytes, size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = malloc(nbytes * size);
	if (p == 0)
		return (NULL);
	while (i < size)
	{
		p[i] = '\0';
		i++;
	}
	return (p);
}

char	*get_next_line(int fd)
{
	static char	*stack = NULL;
	char		*buffer;
	char		*line;
	int			read_bytes;

	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (buffer == NULL || BUFFER_SIZE < 1 || fd < 0)
		return (free(buffer), NULL);
	read_bytes = 1;
	while ((read_bytes > 0) && (ft_strchr(buffer, '\n') == NULL))
	{
		ft_bzero(buffer, BUFFER_SIZE + 1);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		stack = ft_strjoin(stack, buffer);
	}
	if (ft_strlen(stack) == 0)
		return (ft_free(&buffer, &stack), NULL);
	line = ft_newline(stack, buffer);
	if ((ft_strlen(stack)) - (ft_strlen(line)) == 0)
		return (ft_free(&buffer, &stack), line);
	stack = ft_temp(stack, buffer, line);
	return (line);
}
/*int main()
{
	 int fd; 
	 char *line;
	 
	 fd = open("1.txt", O_RDONLY);
	  
	 line = get_next_line(fd);
	 printf("(%s)", line);
	 while (line != NULL)
	 {
	 	free(line);
	 	line = get_next_line(fd);
	 	printf("(%s)", line);
	 }
	 free(line);
	 close(fd);
	 return (0);
}*/
