/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niwasaki <niwasaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 17:13:55 by niwasaki          #+#    #+#             */
/*   Updated: 2023/10/01 15:37:54 by niwasaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libc.h>

#define MAX_COMMAND_LENGTH 1024
#define MAX_OUTPUT_LENGTH 8192

//  _____                _     __            _       _  _              __                      _    _
// |  __ \              | |   /_ |          | |     (_)| |            / _|                    | |  (_)
// | |__) |  __ _  _ __ | |_   | |  ______  | |      _ | |__    ___  | |_  _   _  _ __    ___ | |_  _   ___   _ __   ___
// |  ___/  / _` || '__|| __|  | | |______| | |     | || '_ \  / __| |  _|| | | || '_ \  / __|| __|| | / _ \ | '_ \ / __|
// | |     | (_| || |   | |_   | |          | |____ | || |_) || (__  | |  | |_| || | | || (__ | |_ | || (_) || | | |\__ \
// |_|      \__,_||_|    \__|  |_|          |______||_||_.__/  \___| |_|   \__,_||_| |_| \___| \__||_| \___/ |_| |_||___/

int	check_ctype(int (*test)(int), int (*std)(int))
{
	int	c;

	c = -256;
	while (c < UCHAR_MAX + 1)
	{
		if (test(c) != std(c))
			return (0);
		c++;
	}
	return (1);
}

int	check_arr(char *test, char *std, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (test[i] != std[i])
			return (0);
		i++;
	}
	return (1);
}

void	put_result(int judge, int test_no, int end)
{
	if (test_no)
		printf("%d)", test_no);
	if (judge)
		printf("OK");
	else
		printf("error");
	if (end)
		printf("\n");
	else
		printf(", ");
}

void	test_isalpha(void)
{
	printf("[ft_isalpha]      : ");
	put_result(check_ctype(ft_isalpha, isalpha), 0, 1);
}

void	test_isdigit(void)
{
	printf("[ft_isdigit]      : ");
	put_result(check_ctype(ft_isdigit, isdigit), 0, 1);
}

void	test_isalnum(void)
{
	printf("[ft_isalnum]      : ");
	put_result(check_ctype(ft_isalnum, isalnum), 0, 1);
}

void	test_isascii(void)
{
	printf("[ft_isascii]      : ");
	put_result(check_ctype(ft_isascii, isascii), 0, 1);
}

void	test_isprint(void)
{
	printf("[ft_isprint]      : ");
	put_result(check_ctype(ft_isprint, isprint), 0, 1);
}

void	test_strlen(void)
{
	const char	*test1 = "";
	const char	*test2 = "Hello 42Tokyo!";

	printf("[ft_strlen]       : ");
	put_result(ft_strlen(test1) == strlen(test1), 1, 0);
	put_result(ft_strlen(test2) == strlen(test2), 2, 1);
}

void	test_memset(void)
{
	char	std[50];
	char	test[50];
	int		i;

	printf("[ft_memset]       : ");
	bzero(std, 50);
	bzero(test, 50);
	memset(test, 65, 0);
	put_result(test[0] == 0, 1, 0);
	memset(std, -200, 5);
	ft_memset(test, -200, 5);
	put_result(test[0] == std[0] && test[4] == std[4] && test[5] == std[5], 2, 0);
	ft_memset(test, 65, 10);
	i = 0;
	while (test[i] == 65)
		i++;
	put_result(i == 10 && test[i] == 0, 3, 1);
}

void	test_bzero(void)
{
	char	std[50];
	char	test[50];
	int		i;

	printf("[ft_bzero]        : ");
	memset(std, 65, 50);
	memset(test, 65, 50);
	ft_bzero(test, 0);
	put_result(test[0] == std[0], 1, 0);
	bzero(std, 5);
	ft_bzero(test, 5);
	put_result(test[0] == std[0] && test[4] == std[4] && test[5] == std[5], 2, 0);
	ft_bzero(test, 10);
	i = 0;
	while (test[i] == 0)
		i++;
	put_result(i == 10 && test[i] == 65, 3, 1);
}

void	test_memcpy(void)
{
	char		std[10];
	char		test[10];
	const char	*src = "test3";

	printf("[ft_memcpy]       : ");
	bzero(std, 10);
	bzero(test, 10);
	memcpy(std, NULL, 0);
	ft_memcpy(test, NULL, 0);
	put_result(test[0] == std[0], 1, 0);
	memcpy(std, "test2", 0);
	ft_memcpy(test, "test2", 0);
	put_result(test[0] == std[0], 2, 0);
	memcpy(std, src, 10);
	ft_memcpy(test, src, 10);
	put_result(check_arr(test, std, 10), 3, 0);
	put_result(ft_memcpy(NULL, NULL, 10) == memcpy(NULL, NULL, 10), 4, 1);
}

void	test_memmove(void)
{
	char		std[10];
	char		test[10];
	char		std4[10] = "test4xxx";
	char		test4[10] = "test4xxx";

	printf("[ft_memmove]      : ");
	bzero(std, 10);
	bzero(test, 10);
	memmove(std, NULL, 0);
	ft_memmove(test, NULL, 0);
	put_result(test[0] == std[0], 1, 0);
	memmove(std, "test2", 0);
	ft_memmove(test, "test2", 0);
	put_result(test[0] == std[0], 2, 0);
	memmove(std, "test3", 10);
	ft_memmove(test, "test3", 10);
	put_result(check_arr(test, std, 10), 3, 0);
	memmove(&std4[3], std4, 5);
	ft_memmove(&test4[3], test4, 5);
	put_result(check_arr(test4, std4, 10), 4, 0);
	put_result(ft_memmove(NULL, NULL, 10) == memmove(NULL, NULL, 10), 5, 1);
}

void	test_strlcpy(void)
{
	char		std[10];
	char		test[10];

	printf("[ft_strlcpy]      : ");
	bzero(std, 10);
	bzero(test, 10);
	put_result(ft_strlcpy(NULL, "test1", 0) == strlcpy(NULL, "test1", 0), 1, 0);
	put_result(ft_strlcpy(test, "test2", 0) == strlcpy(std, "test2", 0) && check_arr(test, std, 10), 2, 0);
	put_result(ft_strlcpy(test, "test1", 1) == strlcpy(std, "test1", 1) && check_arr(test, std, 10), 3, 0);
	bzero(std, 10);
	bzero(test, 10);
	put_result(ft_strlcpy(test, "test4", 5) == strlcpy(std, "test4", 5) && check_arr(test, std, 10), 4, 0);
	bzero(std, 10);
	bzero(test, 10);
	put_result(ft_strlcpy(test, "test5", 6) == strlcpy(std, "test5", 6) && check_arr(test, std, 10), 5, 0);
	bzero(std, 10);
	bzero(test, 10);
	put_result(ft_strlcpy(test, "", 10) == strlcpy(std, "", 10) && check_arr(test, std, 10), 6, 0);
	put_result(ft_strlcpy(test, "test7", 10) == strlcpy(std, "test7", 10) && check_arr(test, std, 10), 7, 1);
}

void	test_strlcat(void)
{
	char		std[20];
	char		test[20];

	printf("[ft_strlcat]      : ");
	put_result(ft_strlcat(NULL, "test1", 0) == strlcat(NULL, "test1", 0), 1, 0);
	bzero(std, 20);
	bzero(test, 20);
	put_result(ft_strlcat(test, "test2", 0) == strlcat(std, "test2", 0) && check_arr(test, std, 20), 2, 0);
	put_result(ft_strlcat(test, "test3", 20) == strlcat(std, "test3", 20) && check_arr(test, std, 20), 3 ,0);
	put_result(ft_strlcat(test, "test4", 20) == strlcat(std, "test4", 20) && check_arr(test, std, 20), 4, 0);
	put_result(ft_strlcat(test, "", 20) == strlcat(std, "", 20) && check_arr(test, std, 20), 5, 0);
	put_result(ft_strlcat(test, "test6", 5) == strlcat(std, "test6", 5) && check_arr(test, std, 20), 6, 0);
	put_result(ft_strlcat(test, "test7", 14) == strlcat(std, "test7", 14) && check_arr(test, std, 20), 7, 0);
	put_result(ft_strlcat(test, "test8xxxxx", 20) == strlcat(std, "test8xxxxx", 20) && check_arr(test, std, 20), 8, 1);
}

void	test_toupper(void)
{
	printf("[ft_toupper]      : ");
	put_result(check_ctype(ft_toupper, toupper), 0, 1);
}

void	test_tolower(void)
{
	printf("[ft_tolower]      : ");
	put_result(check_ctype(ft_tolower, tolower), 0, 1);
}

void	test_strchr(void)
{
	const char	*s = "Hello world!";
	const char	*s2 = "";

	printf("[ft_strchr]    	  : ");
	put_result(ft_strchr(s, 'H') == strchr(s, 'H'), 1, 0);
	put_result(ft_strchr(s, '!') == strchr(s, '!'), 2, 0);
	put_result(ft_strchr(s, 'l') == strchr(s, 'l'), 3, 0);
	put_result(ft_strchr(s, 'a') == strchr(s, 'a'), 4, 0);
	put_result(ft_strchr(s, 0) == strchr(s, 0), 5, 0);
	put_result(ft_strchr(s2, 0) == strchr(s2, 0), 6, 0);
	put_result(ft_strchr(s2, 'a') == strchr(s2, 'a'), 7, 0);
	put_result(ft_strchr(s, 'H' + 256) == strchr(s, 'H' + 256), 8, 1);
}

void	test_strrchr(void)
{
	const char	*s = "Hello world!";
	const char	*s2 = "";

	printf("[ft_strrchr]      : ");
	put_result(ft_strrchr(s, 'H') == strrchr(s, 'H'), 1, 0);
	put_result(ft_strrchr(s, '!') == strrchr(s, '!'), 2, 0);
	put_result(ft_strrchr(s, 'l') == strrchr(s, 'l'), 3, 0);
	put_result(ft_strrchr(s, 'a') == strrchr(s, 'a'), 4, 0);
	put_result(ft_strrchr(s, 0) == strrchr(s, 0), 5, 0);
	put_result(ft_strrchr(s2, 0) == strrchr(s2, 0), 6, 0);
	put_result(ft_strrchr(s2, 'a') == strrchr(s2, 'a'), 7, 0);
	put_result(ft_strrchr(s, 'H' + 256) == strrchr(s, 'H' + 256), 8, 1);
}

void	test_strncmp(void)
{
	char	test[2];

	printf("[ft_strncmp]      : ");
	put_result(ft_strncmp(NULL, NULL, 0) == strncmp(NULL, NULL, 0), 1, 0);
	bzero(test, 2);
	test[0] = -56;
	put_result(ft_strncmp(test, "a", 2) > 0 == strncmp(test, "a", 2) > 0, 2, 0);
	put_result(ft_strncmp("test", "test", 10) == strncmp("test", "test", 10), 3, 0);
	put_result(ft_strncmp("test4", "test", 10) > 0 == strncmp("test4", "test", 10) > 0, 4, 0);
	put_result(ft_strncmp("test", "test5", 10) > 0 == strncmp("test", "test5", 10) > 0, 5, 0);
	put_result(ft_strncmp("Test", "test", 10) > 0 == strncmp("Test", "test", 10) > 0, 6, 0);
	put_result(ft_strncmp("test", "Test", 10) > 0 == strncmp("test", "Test", 10) > 0, 7, 0);
	put_result(ft_strncmp("tesT", "test", 10) > 0 == strncmp("tesT", "test", 10) > 0, 8, 0);
	put_result(ft_strncmp("test", "tesT", 10) > 0 == strncmp("test", "tesT", 10) > 0, 9, 0);
	put_result(ft_strncmp("tEst", "test", 10) > 0 == strncmp("tEst", "test", 10) > 0, 10, 0);
	put_result(ft_strncmp("test", "tEst", 10) > 0 == strncmp("test", "tEst", 10) > 0, 11, 0);
	put_result(ft_strncmp("test12", "test", 4) == strncmp("test12", "test", 4), 12, 0);
	put_result(ft_strncmp("test13", "test ", 5) > 0 == strncmp("test13", "test ", 5) > 0, 13, 0);
	put_result(ft_strncmp("test14", "test", -1) > 0 == strncmp("test14", "test", -1) > 0, 14, 0);
	put_result(ft_strncmp("test15", "", 5) > 0 == strncmp("test15", "", 5) > 0, 15, 0);
	put_result(ft_strncmp("", "test16", 5) > 0 == strncmp("", "test16", 5) > 0, 16, 0);
	put_result(ft_strncmp("", "", 5) == strncmp("", "", 5), 17, 1);
}

void	test_memchr(void)
{
	const char	*s = "Hello world!";
	const char	*s2 = "";

	printf("[ft_memchr]    	  : ");
	put_result(ft_memchr(s, 'H', 13) == memchr(s, 'H', 13), 1, 0);
	put_result(ft_memchr(s, '!', 13) == memchr(s, '!', 13), 2, 0);
	put_result(ft_memchr(s, 'l', 13) == memchr(s, 'l', 13), 3, 0);
	put_result(ft_memchr(s, 'a', 13) == memchr(s, 'a', 13), 4, 0);
	put_result(ft_memchr(s, 0, 13) == memchr(s, 0, 13), 5, 0);
	put_result(ft_memchr(s2, 0, 13) == memchr(s2, 0, 13), 6, 0);
	put_result(ft_memchr(s2, 'a', 13) == memchr(s2, 'a', 13), 7, 0);
	put_result(ft_memchr(s, 'H' + 256, 13) == memchr(s, 'H' + 256, 13), 8, 0);
	put_result(ft_memchr(NULL, 'a', 0) == memchr(NULL, 'a', 0), 9, 0);
	put_result(ft_memchr(s, 'H', -1) == memchr(s, 'H', -1), 10, 0);
	put_result(ft_memchr(s, 0, 12) == memchr(s, 0, 12), 11, 0);
	put_result(ft_memchr(s, 1, SIZE_MAX) == memchr(s, 1, SIZE_MAX), 12, 0);
	put_result(ft_memchr(s, 'H', SIZE_MAX + 1) == memchr(s, 'H', SIZE_MAX + 1), 13, 0);
	put_result(ft_memchr(s, 'H', SIZE_MAX + 2) == memchr(s, 'H', SIZE_MAX + 2), 14, 1);
}

void	test_memcmp(void)
{
	char	test[2];

	printf("[ft_memcmp]	  : ");
	put_result(ft_memcmp(NULL, NULL, 0) == memcmp(NULL, NULL, 0), 1, 0);
	bzero(test, 2);
	test[0] = -56;
	put_result(ft_memcmp(test, "a", 2) > 0 == memcmp(test, "a", 2) > 0, 2, 0);
	put_result(ft_memcmp("test", "test", 10) == memcmp("test", "test", 10), 3, 0);
	put_result(ft_memcmp("test4", "test", 10) > 0 == memcmp("test4", "test", 10) > 0, 4, 0);
	put_result(ft_memcmp("test", "test5", 10) > 0 == memcmp("test", "test5", 10) > 0, 5, 0);
	put_result(ft_memcmp("Test", "test", 10) > 0 == memcmp("Test", "test", 10) > 0, 6, 0);
	put_result(ft_memcmp("test", "Test", 10) > 0 == memcmp("test", "Test", 10) > 0, 7, 0);
	put_result(ft_memcmp("tesT", "test", 10) > 0 == memcmp("tesT", "test", 10) > 0, 8, 0);
	put_result(ft_memcmp("test", "tesT", 10) > 0 == memcmp("test", "tesT", 10) > 0, 9, 0);
	put_result(ft_memcmp("tEst", "test", 10) > 0 == memcmp("tEst", "test", 10) > 0, 10, 0);
	put_result(ft_memcmp("test", "tEst", 10) > 0 == memcmp("test", "tEst", 10) > 0, 11, 0);
	put_result(ft_memcmp("test12", "test", 4) == memcmp("test12", "test", 4), 12, 0);
	put_result(ft_memcmp("test13", "test ", 5) > 0 == memcmp("test13", "test ", 5) > 0, 13, 0);
	put_result(ft_memcmp("test14", "test", -1) > 0 == memcmp("test14", "test", -1) > 0, 14, 0);
	put_result(ft_memcmp("test15", "", 5) > 0 == memcmp("test15", "", 5) > 0, 15, 0);
	put_result(ft_memcmp("", "test16", 5) > 0 == memcmp("", "test16", 5) > 0, 16, 0);
	put_result(ft_memcmp("", "", 5) == memcmp("", "", 5), 17, 1);
}

void	test_strnstr(void)
{
	char	*str = "abcaabcaabcdefg";
	char	*emp = "";

	printf("[ft_strnstr]      : ");
	put_result(ft_strnstr(NULL, str, 0) == strnstr(NULL, str, 0), 1, 0);
	put_result(ft_strnstr(NULL, "", 1) == strnstr(NULL, "", 1), 2, 0);
	put_result(ft_strnstr(NULL, "", -1) == strnstr(NULL, "", -1), 3, 0);
	put_result(ft_strnstr(str, "", 16) == strnstr(str, "", 16), 4, 0);
	put_result(ft_strnstr(str, "", -1) == strnstr(str, "", -1), 5, 0);
	put_result(ft_strnstr(str, "g", 13) == strnstr(str, "g", 13), 6, 0);
	put_result(ft_strnstr(str, "g", 14) == strnstr(str, "g", 14), 7, 0);
	put_result(ft_strnstr(str, "g", -1) == strnstr(str, "g", -1), 8, 0);
	put_result(ft_strnstr(str, "42", 0) == strnstr(str, "42", 0), 9, 0);
	put_result(ft_strnstr(str, "42", -1) == strnstr(str, "42", -1), 10, 0);
	put_result(ft_strnstr(str, "bca", -1) == strnstr(str, "bca", -1), 11, 0);
	put_result(ft_strnstr(str, "aabcd", -1) == strnstr(str, "aabcd", -1), 12, 0);
	put_result(ft_strnstr(emp, "", 1) == strnstr(emp, "", 1), 13, 0);
	put_result(ft_strnstr(emp, "", -1) == strnstr(emp, "", -1), 14, 0);
	put_result(ft_strnstr(emp, "abcd", 0) == strnstr(emp, "abcd", 0), 15, 0);
	put_result(ft_strnstr(emp, "abcd", -1) == strnstr(emp, "abcd", -1), 16, 1);
}

void	test_atoi(void)
{
	printf("[ft_atoi]	  : ");
	put_result(ft_atoi(" \t\n\v\f\r+42abc123") == atoi(" \t\n\v\f\r+42abc123"), 1, 0);
	put_result(ft_atoi(" \t\n\v\f\r-42abc123") == atoi(" \t\n\v\f\r-42abc123"), 2, 0);
	put_result(ft_atoi(" \t\n\v\f\r+000000000000000000042abc123") == atoi(" \t\n\v\f\r+000000000000000000042abc123"), 3, 0);
	put_result(ft_atoi(" \t\n\v\f\r-000000000000000000042abc123") == atoi(" \t\n\v\f\r-000000000000000000042abc123"), 4, 0);
	put_result(ft_atoi(" \t\n\v\f\r++42abc123") == atoi(" \t\n\v\f\r++42abc123"), 5, 0);
	put_result(ft_atoi(" \t\n\v\f\r--42abc123") == atoi(" \t\n\v\f\r--42abc123"), 6, 0);
	put_result(ft_atoi(" \t\n\v\f\r+-42abc123") == atoi(" \t\n\v\f\r+-42abc123"), 7, 0);
	put_result(ft_atoi(" \t\n\v\f\r-+42abc123") == atoi(" \t\n\v\f\r-+42abc123"), 8, 0);
	put_result(ft_atoi("a \t\n\v\f\r+42abc123") == atoi("a \t\n\v\f\r+42abc123"), 9, 0);
	put_result(ft_atoi(" \t\na\v\f\r+42abc123") == atoi(" \t\na\v\f\r+42abc123"), 10, 0);
	put_result(ft_atoi(" \t\n\v\f\ra+42abc123") == atoi(" \t\n\v\f\ra+42abc123"), 11, 0);
	put_result(ft_atoi(" \t\n\v\f\r+a42abc123") == atoi(" \t\n\v\f\r+a42abc123"), 12, 0);
	put_result(ft_atoi("+ \t\n\v\f\r42abc123") == atoi("+ \t\n\v\f\r42abc123"), 13, 0);
	put_result(ft_atoi("- \t\n\v\f\r42abc123") == atoi("- \t\n\v\f\r42abc123"), 14, 0);
	put_result(ft_atoi("1 \t\n\v\f\r42abc123") == atoi("1 \t\n\v\f\r42abc123"), 15, 0);
	put_result(ft_atoi("-1 \t\n\v\f\r42abc123") == atoi("-1 \t\n\v\f\r42abc123"), 16, 0);
	put_result(ft_atoi("2147483647") == atoi("2147483647"), 17, 0);		// INT_MAX
	put_result(ft_atoi("-2147483648") == atoi("-2147483648"), 18, 0);	// INT_MIN
	put_result(ft_atoi("2147483648") == atoi("2147483648"), 19, 0);		// INT_MAX + 1
	put_result(ft_atoi("-2147483649") == atoi("-2147483649"), 20, 0);	// INT_MIN - 1
	put_result(ft_atoi("9223372036854775807") == atoi("9223372036854775807"), 21, 0);		// LONG_MAX
	put_result(ft_atoi("-9223372036854775808") == atoi("-9223372036854775808"), 22, 0);		// LONG_MIN
	put_result(ft_atoi("9223372036854775808") == atoi("9223372036854775808"), 23, 0);		// LONG_MAX + 1
	put_result(ft_atoi("-9223372036854775809") == atoi("-9223372036854775809"), 24, 0);		// LONG_MIN - 1
	put_result(ft_atoi("19223372036854775807") == atoi("19223372036854775807"), 25, 0);		// OVER LONG_MAX
	put_result(ft_atoi("-19223372036854775808") == atoi("-19223372036854775808"), 25, 1);	// UNDER LONG_MIN
}

void	test_calloc(void)
{
	void	*test;
	void	*std;

	printf("[ft_calloc]	  : ");
	put_result(ft_calloc(SIZE_MAX, SIZE_MAX) == calloc(SIZE_MAX, SIZE_MAX), 1, 0);
	test = calloc(0, 0);
	std = calloc(0, 0);
	put_result(memcmp(test, std, 10) == 0, 2, 0);
	free(test);
	free(std);
	test = calloc(0, 1);
	std = calloc(0, 1);
	put_result(memcmp(test, std, 10) == 0, 3, 0);
	free(test);
	free(std);
	test = calloc(1, 0);
	std = calloc(1, 0);
	put_result(memcmp(test, std, 10) == 0, 4, 0);
	free(test);
	free(std);
	test = calloc(5, 2);
	std = calloc(5, 2);
	put_result(memcmp(test, std, 10) == 0, 5, 1);
	free(test);
	free(std);
}

void	test_strdup(void)
{
	void	*test;
	void	*std;

	printf("[ft_strdup]	  : ");
	test = ft_strdup("test1");
	std = strdup("test1");
	put_result(strcmp(test, std) == 0, 1, 0);
	free(test);
	free(std);
	test = ft_strdup("");
	std = strdup("");
	put_result(strcmp(test, std) == 0, 2, 1);
	free(test);
	free(std);
}

//  _____                _     ___                           _      _  _  _    _                       _    __                      _    _
// |  __ \              | |   |__ \               /\        | |    | |(_)| |  (_)                     | |  / _|                    | |  (_)
// | |__) |  __ _  _ __ | |_     ) |  ______     /  \     __| |  __| | _ | |_  _   ___   _ __    __ _ | | | |_  _   _  _ __    ___ | |_  _   ___   _ __   ___
// |  ___/  / _` || '__|| __|   / /  |______|   / /\ \   / _` | / _` || || __|| | / _ \ | '_ \  / _` || | |  _|| | | || '_ \  / __|| __|| | / _ \ | '_ \ / __|
// | |     | (_| || |   | |_   / /_            / ____ \ | (_| || (_| || || |_ | || (_) || | | || (_| || | | |  | |_| || | | || (__ | |_ | || (_) || | | |\__ \
// |_|      \__,_||_|    \__| |____|          /_/    \_\ \__,_| \__,_||_| \__||_| \___/ |_| |_| \__,_||_| |_|   \__,_||_| |_| \___| \__||_| \___/ |_| |_||___/

void	test_substr(void)
{
	void		*test;
	const char	*s = "Hello World!";

	printf("[ft_substr]	  : ");
	put_result(ft_substr(NULL, 0, 10) == NULL, 1, 0);
	test = ft_substr("", 0, 1);
	put_result(strcmp(test, "") == 0, 2, 0);
	free(test);
	test = ft_substr(s, 0, 5);
	put_result(strncmp(test, s, 5) == 0, 3, 0);
	free(test);
	test = ft_substr(s, 0, strlen(s));
	put_result(strncmp(test, s, strlen(s)) == 0, 4, 0);
	free(test);
	test = ft_substr(s, 0, -1);
	put_result(strncmp(test, s, strlen(s)) == 0, 5, 0);
	free(test);
	test = ft_substr(s, 5, strlen(s) - 5);
	put_result(strncmp(test, &s[5], strlen(s) - 5) == 0, 6, 0);
	free(test);
	test = ft_substr(s, 0, strlen(s) + 5);
	put_result(strncmp(test, s, strlen(s)) == 0, 7, 0);
	free(test);
	test = ft_substr(s, 5, strlen(s) + 5);
	put_result(strncmp(test, &s[5], strlen(s) - 5) == 0, 8, 0);
	free(test);
	test = ft_substr(s, strlen(s) + 5, strlen(s));
	put_result(strncmp(test, "", 1) == 0, 9, 0);
	free(test);
	test = ft_substr(s, 5, 5);
	put_result(strncmp(test, &s[5], 5) == 0, 10, 1);
	free(test);
}

void	test_strjoin(void)
{
	void		*test;
	const char	*s = "test";
	const char	*emp = "";

	printf("[ft_strjoin]	  : ");
	put_result(ft_strjoin(NULL, NULL) == NULL, 1, 0);
	put_result(ft_strjoin(s, NULL) == NULL, 2, 0);
	put_result(ft_strjoin(NULL, s) == NULL, 3, 0);
	test = ft_strjoin(s, emp);
	put_result(strcmp(test, s) == 0, 4, 0);
	free(test);
	test = ft_strjoin(emp, s);
	put_result(strcmp(test, s) == 0, 5, 0);
	free(test);
	test = ft_strjoin(emp, "");
	put_result(strcmp(test, "") == 0, 6, 0);
	free(test);
	test = ft_strjoin(s, "test7");
	put_result(strcmp(test, "testtest7") == 0, 7, 1);
	free(test);
}

void	test_strtrim(void)
{
	void		*test;
	const char	*s1 = "test";
	const char	*s2 = " \t\n\v\f\rtest \t\n\v\f\r";

	printf("[ft_strtrim]	  : ");
	put_result(ft_strtrim(NULL, NULL) == NULL, 1, 0);
	put_result(ft_strtrim(s1, NULL) == NULL, 2, 0);
	put_result(ft_strtrim(NULL, s1) == NULL, 3, 0);
	test = ft_strtrim(s1, "");
	put_result(strcmp(test, "test") == 0, 4, 0);
	free(test);
	test = ft_strtrim(s1, "test");
	put_result(strcmp(test, "") == 0, 5, 0);
	free(test);
	test = ft_strtrim(s1, "t");
	put_result(strcmp(test, "es") == 0, 6, 0);
	free(test);
	test = ft_strtrim(s2, " \t\n\v\f\r");
	put_result(strcmp(test, "test") == 0, 7, 0);
	free(test);
	test = ft_strtrim(s2, "abcde");
	put_result(strcmp(test, s2) == 0, 8, 0);
	free(test);
	test = ft_strtrim("", "test");
	put_result(strcmp(test, "") == 0, 9, 1);
	free(test);
}

int	free_all(char **result, size_t i)
{
	while (i > 0)
	{
		i--;
		free(result[i]);
		result[i] = NULL;
	}
	free(result);
	result = NULL;
	return (0);
}

void	test_split(void)
{
	char		**test;

	printf("[ft_split]	  : ");
	put_result(ft_split(NULL, ' ') == NULL, 1, 0);
	test = ft_split("", ' ');
	put_result(test[0] == NULL, 2, 0);
	free_all(test, 1);
	test = ft_split("        ", ' ');
	put_result(test[0] == NULL, 3, 0);
	free_all(test, 1);
	test = ft_split("HelloWorld!", ' ');
	put_result(strcmp(test[0], "HelloWorld!") == 0 && test[1] == NULL, 4, 0);
	free_all(test, 2);
	test = ft_split("   HelloWorld!   ", ' ');
	put_result(strcmp(test[0], "HelloWorld!") == 0 && test[1] == NULL, 5, 0);
	free_all(test, 2);
	test = ft_split("   Hello    World!   ", ' ');
	put_result(strcmp(test[0], "Hello") == 0 && strcmp(test[1], "World!") == 0 && test[2] == NULL, 6, 0);
	free_all(test, 3);
	test = ft_split("42 students struggled through coding problems late into the night.", ' ');
	put_result(strcmp(test[0], "42") == 0, 7, 0);
	put_result(strcmp(test[1], "students") == 0, 8, 0);
	put_result(strcmp(test[2], "struggled") == 0, 9, 0);
	put_result(strcmp(test[3], "through") == 0, 10, 0);
	put_result(strcmp(test[4], "coding") == 0, 11, 0);
	put_result(strcmp(test[5], "problems") == 0, 12, 0);
	put_result(strcmp(test[6], "late") == 0, 13, 0);
	put_result(strcmp(test[7], "into") == 0, 14, 0);
	put_result(strcmp(test[8], "the") == 0, 15, 0);
	put_result(strcmp(test[9], "night.") == 0, 16, 0);
	put_result(test[10] == NULL, 17, 1);
	free_all(test, 11);
}

void	test_itoa(void)
{
	char		*test;

	printf("[ft_itoa]	  : ");
	test = ft_itoa(0);
	put_result(strcmp(test, "0") == 0, 1, 0);
	free(test);
	test = ft_itoa(1);
	put_result(strcmp(test, "1") == 0, 2, 0);
	free(test);
	test = ft_itoa(-1);
	put_result(strcmp(test, "-1") == 0, 3, 0);
	free(test);
	test = ft_itoa(42);
	put_result(strcmp(test, "42") == 0, 4, 0);
	free(test);
	test = ft_itoa(-1234567890);
	put_result(strcmp(test, "-1234567890") == 0, 5, 0);
	free(test);
	test = ft_itoa(INT_MAX);
	put_result(strcmp(test, "2147483647") == 0, 6, 0);
	free(test);
	test = ft_itoa(INT_MIN);
	put_result(strcmp(test, "-2147483648") == 0, 7, 1);
	free(test);
}

char	test_f1(unsigned int i, char c)
{
	(void)i;
	if (isupper(c))
		return (tolower(c));
	else if (islower(c))
		return (toupper(c));
	else if (isdigit(c))
		return ('_');
	else if (isspace(c))
		return (c);
	else
		return ('.');
}

void	test_f2(unsigned int i, char *s)
{
	char	c;

	c = *s;
	(void)i;
	if (isupper(c))
		*s = tolower(c);
	else if (islower(c))
		*s = toupper(c);
	else if (isdigit(c))
		*s = '_';
	else if (isspace(c))
		*s = c;
	else
		*s = '.';
}

void	test_strmapi(void)
{
	char	*test;

	printf("[ft_strmapi]	  : ");
	put_result(ft_strmapi(NULL, NULL) == NULL, 1, 0);
	put_result(ft_strmapi("test", NULL) == NULL, 2, 0);
	put_result(ft_strmapi(NULL, test_f1) == NULL, 3, 0);
	test = ft_strmapi("", test_f1);
	put_result(strcmp(test, "") == 0, 4, 0);
	free(test);
	test = ft_strmapi("123 abc DEF ;:_+-~\a", test_f1);
	put_result(strcmp(test, "___ ABC def .......") == 0, 5, 1);
	free(test);
}

void	test_striteri(void)
{
	char	emp[] = "";
	char	test[] = "123 abc DEF ;:_+-~\a";

	printf("[ft_striteri]	  : ");
	put_result(ft_striteri(NULL, NULL) == NULL, 1, 0);
	put_result(ft_striteri("test", NULL) == NULL, 2, 0);
	put_result(ft_striteri(NULL, test_f2) == NULL, 3, 0);
	ft_striteri(emp, test_f2);
	put_result(strcmp(emp, "") == 0, 1, 0);
	ft_striteri(test, test_f2);
	put_result(strcmp(test, "___ ABC def .......") == 0, 2, 1);
}

void	test_putchar_fd(void)
{
	printf("[ft_putchar_fd]	  : ");

    // 一時的に標準出力をリダイレクトする
    int stdout_backup = dup(STDOUT_FILENO);
    int fd[2];
    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);

    char expected_output = 'A'; // 期待する出力文字
    ft_putchar_fd(expected_output, STDOUT_FILENO);

    // リダイレクトした出力を読み取る
    char buffer[2];
    read(fd[0], buffer, 2);
    buffer[1] = '\0'; // 文字列を終端する

    // リダイレクトを元に戻す
    dup2(stdout_backup, STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);

    // 出力を比較
    char *expected_string = "A";
	put_result(strcmp(buffer, expected_string) == 0, 1, 1);
}

void	test_putstr_fd(void)
{
	printf("[ft_putstr_fd]	  : ");

    // 一時的に標準出力をリダイレクトする
    int stdout_backup = dup(STDOUT_FILENO);
    int fd[2];
    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);

    char *expected_output = "Hello, world!"; // 期待する出力文字列
    ft_putstr_fd(expected_output, STDOUT_FILENO);

    // リダイレクトした出力を読み取る
    char buffer[256]; // 十分なサイズで初期化しておく
    ssize_t bytesRead = read(fd[0], buffer, sizeof(buffer));
    buffer[bytesRead] = '\0'; // 文字列を終端する

    // リダイレクトを元に戻す
    dup2(stdout_backup, STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);

    // 出力を比較
	put_result(strcmp(buffer, expected_output) == 0, 1, 1);
}

void	test_putendl_fd(void)
{
	printf("[ft_putendl_fd]	  : ");

    // 一時的に標準出力をリダイレクトする
    int stdout_backup = dup(STDOUT_FILENO);
    int fd[2];
    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);

    char *expected_output = "Hello, world!"; // 期待する出力文字列
    ft_putendl_fd(expected_output, STDOUT_FILENO);

    // リダイレクトした出力を読み取る
    char buffer[256]; // 十分なサイズで初期化しておく
    ssize_t bytesRead = read(fd[0], buffer, sizeof(buffer));
    buffer[bytesRead] = '\0'; // 文字列を終端する

    // リダイレクトを元に戻す
    dup2(stdout_backup, STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);

    // 出力を比較
    char *expected_with_newline = "Hello, world!\n";
	put_result(strcmp(buffer, expected_with_newline) == 0, 1, 1);
}

void test_putnbr_helper(int n, char *expected_output, int test_no, int end)
{
    // 一時的に標準出力をリダイレクトする
    int stdout_backup = dup(STDOUT_FILENO);
    int fd[2];
    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);

    ft_putnbr_fd(n, STDOUT_FILENO);

    // リダイレクトした出力を読み取る
    char buffer[256]; // 十分なサイズで初期化しておく
    ssize_t bytesRead = read(fd[0], buffer, sizeof(buffer));
    buffer[bytesRead] = '\0'; // 文字列を終端する

    // リダイレクトを元に戻す
    dup2(stdout_backup, STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);

    // 出力を比較
	put_result(strcmp(buffer, expected_output) == 0, test_no, end);
}

void	test_putnbr_fd(void)
{
	printf("[ft_putnbr_fd]	  : ");
	test_putnbr_helper(0, "0", 1, 0);
	test_putnbr_helper(1, "1", 2, 0);
	test_putnbr_helper(-1, "-1", 3, 0);
	test_putnbr_helper(42, "42", 4, 0);
	test_putnbr_helper(-1234567890, "-1234567890", 5, 0);
	test_putnbr_helper(INT_MAX, "2147483647", 6, 0);
	test_putnbr_helper(INT_MIN, "-2147483648", 7, 1);
}


//  ____                                                  _
// |  _ \                                                | |
// | |_) |  ___   _ __   _   _  ___   _ __    __ _  _ __ | |_
// |  _ <  / _ \ | '_ \ | | | |/ __| | '_ \  / _` || '__|| __|
// | |_) || (_) || | | || |_| |\__ \ | |_) || (_| || |   | |_
// |____/  \___/ |_| |_| \__,_||___/ | .__/  \__,_||_|    \__|
//                                   | |
//                                   |_|

void	test_lstnew(void)
{
	t_list	*list;
	int		test;

	printf("[ft_lstnew]	  : ");
	list = ft_lstnew(NULL);
	put_result(list->content == NULL && list->next == NULL, 1, 0);
	free(list);
	test = 42;
	list = ft_lstnew(&test);
	put_result(*(int *)(list->content) == 42 && list->next == NULL, 2, 0);
	free(list);
	list = ft_lstnew("test");
	put_result(strcmp(list->content, "test") == 0 && list->next == NULL, 3, 1);
	free(list);
}

void	test_lstadd_front(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;
	t_list	*list5;

	printf("[ft_lstadd_front] : ");
	list1 = ft_lstnew("list1");
	list2 = ft_lstnew("list2");
	list3 = ft_lstnew("list3");
	list4 = ft_lstnew("list4");
	list5 = ft_lstnew("list5");
	ft_lstadd_front(NULL, NULL);
	ft_lstadd_front(NULL, list1);
	ft_lstadd_front(&list1, NULL);
	put_result(list1->next == NULL, 1, 0);
	ft_lstadd_front(&list3, list2);
	put_result(strcmp(list2->next->content, "list3") == 0, 2, 0);
	list3 = list2->next;
	ft_lstadd_front(&list2, list1);
	put_result(strcmp(list1->next->content, "list2") == 0, 3, 0);
	list2 = list1->next;
	ft_lstadd_front(&list5, list4);
	put_result(strcmp(list4->next->content, "list5") == 0, 4, 0);
	list5 = list4->next;
	ft_lstadd_front(&list1, list4);
	put_result(strcmp(list4->next->content, "list1") == 0, 5, 1);
	list1 = list4->next;
	free(list1);
	free(list2);
	free(list3);
	free(list4);
	free(list5);
}

void	test_lstsize(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	printf("[ft_lstsize]	  : ");
	list1 = ft_lstnew("list1");
	list2 = ft_lstnew("list2");
	list3 = ft_lstnew("list3");
	put_result(ft_lstsize(NULL) == 0, 1, 0);
	put_result(ft_lstsize(list1) == 1 && ft_lstsize(list2) == 1 && ft_lstsize(list3) == 1, 2, 0);
	ft_lstadd_front(&list3, list2);
	list3 = list2->next;
	put_result(ft_lstsize(list2) == 2, 3, 0);
	ft_lstadd_front(&list2, list1);
	list2 = list1->next;
	put_result(ft_lstsize(list1) == 3, 4, 1);
	free(list1);
	free(list2);
	free(list3);
}

void	test_lstlast(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	printf("[ft_lstlast]	  : ");
	list1 = ft_lstnew("list1");
	list2 = ft_lstnew("list2");
	list3 = ft_lstnew("list3");
	put_result(ft_lstlast(NULL) == NULL, 1, 0);
	put_result(ft_lstlast(list1) == list1 && ft_lstlast(list2) == list2 && ft_lstlast(list3) == list3, 2, 0);
	ft_lstadd_front(&list3, list2);
	list3 = list2->next;
	put_result(ft_lstlast(list2) == list3, 3, 0);
	ft_lstadd_front(&list2, list1);
	list2 = list1->next;
	put_result(ft_lstlast(list1) == list3, 4, 1);
	free(list1);
	free(list2);
	free(list3);
}

void	test_lstadd_back(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*list4;
	t_list	*list5;

	printf("[ft_lstadd_back]  : ");
	list1 = ft_lstnew("list1");
	list2 = ft_lstnew("list2");
	list3 = ft_lstnew("list3");
	list4 = ft_lstnew("list4");
	list5 = ft_lstnew("list5");
	ft_lstadd_back(NULL, NULL);
	ft_lstadd_back(NULL, list1);
	ft_lstadd_back(&list1, NULL);
	put_result(list1->next == NULL, 1, 0);
	ft_lstadd_back(&list1, list2);
	put_result(list1->next == list2, 2, 0);
	ft_lstadd_back(&list1, list3);
	put_result(list2->next == list3, 3, 0);
	ft_lstadd_back(&list4, list5);
	ft_lstadd_back(&list1, list4);
	put_result(ft_lstlast(list1) == list5, 4, 1);
	free(list1);
	free(list2);
	free(list3);
	free(list4);
	free(list5);
}

void	test_lstdelone(void)
{
	t_list	*list1;
	t_list	*list2;

	printf("[ft_lstdelone]	  : ");
	list1 = ft_lstnew(strdup("list1"));
	list2 = ft_lstnew("list2");
	ft_lstadd_front(&list2, list1);
	list2 = list1->next;
	ft_lstdelone(list1, NULL);
	ft_lstdelone(NULL, free);
	put_result(strcmp(list1->content, "list1") == 0 && strcmp(list1->next->content, "list2") == 0, 1, 0);
	ft_lstdelone(list1, free);
	put_result(strcmp(list2->content, "list2") == 0, 2, 1);
	free(list2);
}

void	test_lstclear(void)
{
	t_list	*list1;

	printf("[ft_lstclear]	  : ");
	list1 = ft_lstnew(strdup("list1"));
	ft_lstadd_back(&list1, ft_lstnew(strdup("list2")));
	ft_lstadd_back(&list1, ft_lstnew(strdup("list3")));
	ft_lstclear(NULL, NULL);
	ft_lstclear(&list1, NULL);
	ft_lstclear(NULL, free);
	ft_lstclear(&(list1->next->next->next), free);
	put_result(strcmp(list1->content, "list1") == 0 && strcmp(list1->next->content, "list2") == 0 && strcmp(list1->next->next->content, "list3") == 0 && list1->next->next->next == NULL, 1, 0);
	ft_lstclear(&list1, free);
	put_result(list1 == NULL, 2, 1);
}

void	test_f3(void *ptr)
{
	char	*str;

	str = (char *)ptr;
	while (*str)
	{
		test_f2(0, str);
		str++;
	}
}

void	*test_f4(void *ptr)
{
	char	*str;

	str = (char *)ptr;
	while (*str)
	{
		test_f2(0, str);
		str++;
	}
	return ((void *)strdup((char *)ptr));
}

void	test_lstiter(void)
{
	t_list	*list1;

	printf("[ft_lstiter]	  : ");
	list1 = ft_lstnew(strdup("list1"));
	ft_lstadd_back(&list1, ft_lstnew(strdup("LIST2")));
	ft_lstadd_back(&list1, ft_lstnew(strdup(" ;:_+-~\a")));
	ft_lstiter(NULL, NULL);
	ft_lstiter(list1, NULL);
	ft_lstiter(NULL, test_f3);
	put_result(strcmp(list1->content, "list1") == 0 && strcmp(list1->next->content, "LIST2") == 0 && strcmp(list1->next->next->content, " ;:_+-~\a") == 0 && list1->next->next->next == NULL, 1, 0);
	ft_lstiter(list1, test_f3);
	put_result(strcmp(list1->content, "LIST_") == 0 && strcmp(list1->next->content, "list_") == 0 && strcmp(list1->next->next->content, " .......") == 0 && list1->next->next->next == NULL, 2, 1);
	ft_lstclear(&list1, free);
}

void	test_lstmap(void)
{
	t_list	*list1;
	t_list	*list2;

	printf("[ft_lstmap]	  : ");
	list1 = ft_lstnew(strdup("list1"));
	ft_lstadd_back(&list1, ft_lstnew(strdup("LIST2")));
	ft_lstadd_back(&list1, ft_lstnew(strdup(" ;:_+-~\a")));
	put_result(ft_lstmap(NULL, NULL, NULL) == NULL, 1, 0);
	put_result(ft_lstmap(list1, test_f4, NULL) == NULL, 2, 0);
	put_result(ft_lstmap(list1, NULL, free) == NULL, 3, 0);
	put_result(ft_lstmap(NULL, test_f4, free) == NULL, 4, 0);
	list2 = ft_lstmap(list1, test_f4, free);
	put_result(strcmp(list2->content, "LIST_") == 0 && strcmp(list2->next->content, "list_") == 0 && strcmp(list2->next->next->content, " .......") == 0 && list2->next->next->next == NULL, 5, 1);
	ft_lstclear(&list1, free);
	ft_lstclear(&list2, free);
}

void	norm(void)
{
    FILE *pipe;
    char command[MAX_COMMAND_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    // コマンドを構築
    sprintf(command, "norminette ft_*.c libft.h");

    // コマンドを実行し、出力を読み取る
    pipe = popen(command, "r");
    if (pipe == NULL) {
        perror("popen");
        return ;
    }

    // 出力を読み取り、表示
    while (fgets(output, sizeof(output), pipe) != NULL) {
        printf("%s", output);
    }

    // パイプを閉じる
    pclose(pipe);
}

void	check_external_functs(void)
{
    FILE *pipe;
    char command[MAX_COMMAND_LENGTH];
    char output[MAX_OUTPUT_LENGTH];

    // コマンドを構築
    sprintf(command, "nm -g libft.a | grep -v -e 'ft_' -e '__' -e '___' -e '^$' | sed 's/^.* U _//' | sort | uniq");

    // コマンドを実行し、出力を読み取る
    pipe = popen(command, "r");
    if (pipe == NULL) {
        perror("popen");
        return ;
    }

    // 出力を読み取り、表示
    while (fgets(output, sizeof(output), pipe) != NULL) {
        printf("%s", output);
    }

    // パイプを閉じる
    pclose(pipe);
}

__attribute__((destructor))
static void destructor() {
    system("leaks -q a.out");
}

int	main(void)
{
	printf("norminette\n");
	norm();
	printf("\n");

	printf("external functions\n");
	check_external_functs();
	printf("\n");

	printf("Part 1 - Libc functions\n");
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
	test_strlen();
	test_memset();
	test_bzero();
	test_memcpy();
	test_memmove();
	test_strlcpy();
	test_strlcat();
	printf("\n");
	test_toupper();
	test_tolower();
	test_strchr();
	test_strrchr();
	test_strncmp();
	test_memchr();
	test_memcmp();
	test_strnstr();
	test_atoi();
	printf("\n");
	test_calloc();
	test_strdup();
	printf("\n");

	printf("Part 2 - Additional functions\n");
	test_substr();
	test_strjoin();
	test_strtrim();
	test_split();
	test_itoa();
	printf("\n");
	test_strmapi();
	test_striteri();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();
	test_putnbr_fd();
	printf("\n");

	printf("Bonus part\n");
	test_lstnew();
	test_lstadd_front();
	test_lstsize();
	test_lstlast();
	test_lstadd_back();
	test_lstdelone();
	test_lstclear();
	test_lstiter();
	test_lstmap();

	return (0);
}

/*
[to do for review]
check Makefile
• 以下のルールは必須です。$(NAME), clean, fclean, re, all
• Makefile が relink を引き起こす場合、
  そのプロジェクトは機能要件を満たしていないとみなされます。
• マルチバイナリのプロジェクトの場合、上述のルールに加え、バイナリをコンパイルするルールも、
  コンパイルされた各バイナリへの具体的なルールと同様に存在しなければなりません。
• システムによるものではないライブラリ(例: Libft)の関数を使用するプロジェクトの場合、
  Makefile はこのライブラリを自動的にコンパイルしなくてはなりません。
• プロジェクト内でコンパイルされる必要があるソースファイルは全て、
  そのファイル名が Makefile に明記されていなければなりません。

cc -Wall -Wextra -Werror libft.a main.c

[norm]
https://github.com/42School/norminette/blob/master/pdf/ja.norm.pdf
[man]
http://linuxjm.osdn.jp/index.html
[tester]
https://github.com/usatie/libft-tester-tokyo
https://github.com/Tripouille/libftTester
https://github.com/alelievr/libft-unit-test
https://github.com/katataku/42/blob/main/libft/testmain.c
[glibc source]
https://github.com/bminor/glibc
*/
