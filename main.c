/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llegrand <llegrand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 15:34:13 by llegrand          #+#    #+#             */
/*   Updated: 2023/05/11 15:34:13 by llegrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int	fd;
	int i;

	printf("BUFFER_SIZE:%i\nFILE:%s\nFILE_CONTENT:\n", BUFFER_SIZE, argv[1]);

	fd = open(argv[1], O_RDONLY);
	for (i = 26; i > 0; i--)
		printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
