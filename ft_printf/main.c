#include "ft_printf.h"
#include <libc.h>
#include <limits.h>
#include <stdio.h>

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q a.out");
// }

int	main(void)
{
	char	*fmt;

	fmt = "%c,%s,%p,%d,%i,%u,%x,%X,%%";
	printf(" return:%d\n", printf(fmt, 65, "test_s", "test_p", 0, INT_MIN, 42, UINT_MAX));
	ft_printf(" return:%d\n", ft_printf(fmt, 65, "test_s", "test_p", 0, INT_MIN, 42, UINT_MAX));
	return (0);
}

/*
cc -Wall -Wextra -Werror libftprintf.a main.c
*/
