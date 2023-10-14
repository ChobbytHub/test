/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niwasaki <niwasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:56:35 by niwasaki          #+#    #+#             */
/*   Updated: 2023/10/14 14:18:29 by niwasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

__attribute__((destructor)) static void destructor()
{
	system("leaks -q a.out");
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*line1;
	char	*line2;
	char	*line3;
	size_t	i;

	fd1 = open("test1.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	fd3 = open("test3.txt", O_RDONLY);
	i = 1;
	while (1)
	{
		printf("[%zd] ----------\n", i);
		line1 = get_next_line(fd1);
		if (line1)
		{
			printf("fd:%d\nline1:%s", fd1, line1);
			free(line1);
		}
		line2 = get_next_line(fd2);
		if (line2)
		{
			printf("fd:%d\nline2:%s", fd2, line2);
			free(line2);
		}
		line3 = get_next_line(fd3);
		if (line3)
		{
			printf("fd:%d\nline3:%s", fd3, line3);
			free(line3);
		}
		if (!line1 && !line2 && !line3)
			break ;
		i++;
	}
	fd1 = close(fd1);
	fd2 = close(fd2);
	fd3 = close(fd3);
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
cc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c -D BUFFER_SIZE=1
*/
