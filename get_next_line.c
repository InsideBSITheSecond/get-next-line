/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:29:59 by llegrand          #+#    #+#             */
/*   Updated: 2023/05/11 15:29:59 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*cut_to_nl(char *str)
{
	int	i;

 	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (ft_substr(str, 0, i + 1));
		}
		i++;
	}
	return ("\0");
}

void	read_line(int fd, char **line)
{
	static char buffer[BUFFER_SIZE];
	int			size;
	int			nli;
	
	size = read(fd, buffer, BUFFER_SIZE);
	nli = ft_strichr(buffer, '\n');
	if (nli != -1)
		*line = cut_to_nl(buffer);
	else
		*line = ft_strdup("no newline in buffer\n");
}

char *get_next_line(int fd)
{
	char		*line;

	read_line(fd, &line);
	return (line);
}
