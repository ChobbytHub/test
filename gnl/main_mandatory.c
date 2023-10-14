/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niwasaki <niwasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:56:35 by niwasaki          #+#    #+#             */
/*   Updated: 2023/10/14 14:17:57 by niwasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open("test1.txt", O_RDONLY);
	line = get_next_line(fd);
	i = 1;
	while (line)
	{
		printf("[line %zd] ----------\n", i);
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	fd = close(fd);
	return (0);
}

// int	main(void)
// {
// 	char	*line;

// 	line = get_next_line(STDIN_FILENO);
// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(STDIN_FILENO);
// 	}
// 	return (0);
// }

/*
cc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main_mandatory.c -D BUFFER_SIZE=1
*/
