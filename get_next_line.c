/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:29:59 by llegrand          #+#    #+#             */
/*   Updated: 2023/06/20 16:44:02 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *memory, char *new_content)
{
	char	*tmp;

	tmp = ft_strjoin(memory, new_content);
	free(memory);
	return (tmp);
}

char	*get_to_nl(char *memory)
{
	char	*line;
	int		i;

	i = 0;
	if (!memory[i])
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (memory[i] && memory[i] != '\n')
	{
		line[i] = memory[i];
		i++;
	}
	if (memory[i] && memory[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*get_from_nl(char *memory)
{
	int		i;
	int		j;
	char	*rem;

	i = 0;
	while (memory[i] && memory[i] != '\n')
		i++;
	if (!memory[i])
	{
		free(memory);
		return (NULL);
	}
	rem = ft_calloc((ft_strlen(memory) - i + 1), sizeof(char));
	if (!rem)
		return (NULL);
	i++;
	j = 0;
	while (memory[i])
		rem[j++] = memory[i++];
	free(memory);
	return (rem);
}

char	*read_file_until_nl(int fd, char *memory)
{
	char	*new_content;
	int		bytes_read;

	if (!memory)
		memory = ft_calloc(1, 1);
	new_content = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_content || !memory)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, new_content, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_content);
			free(memory);
			return (NULL);
		}
		new_content[bytes_read] = 0;
		memory = join_free(memory, new_content);
		if (ft_strchr(memory, '\n'))
			break ;
	}
	free(new_content);
	return (memory);
}

char	*get_next_line(int fd)
{
	static char	*memory;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (BUFFER_SIZE > 2147483647)
		return (NULL);
	memory = read_file_until_nl(fd, memory);
	if (!memory)
		return (NULL);
	line = get_to_nl(memory);
	memory = get_from_nl(memory);
	return (line);
}
