/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_libft_criterion.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lboertie <lboertie@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 12:53:18 by lboertie       #+#    #+#                */
/*   Updated: 2019/11/14 16:00:00 by lboertie      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <criterion/criterion.h>
#include <limits.h>
#include <string.h>

static char test(unsigned int i, char c) {
	i = 0;
	return (toupper(c));
}

// PART 1:

Test(isx, isalpha) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isalpha(c), ft_isalpha(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isalpha(c), ft_isalpha(c));
		c++;
	}
}

Test(isx, isalnum) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isalnum(c), ft_isalnum(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isalnum(c), ft_isalnum(c));
		c++;
	}
}

Test(isx, isascii) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isascii(c), ft_isascii(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isascii(c), ft_isalpha(c));
		c++;
	}
}

Test(isx, isdigit) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isdigit(c), ft_isdigit(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isdigit(c), ft_isdigit(c));
		c++;
	}
}

Test(isx, isprint) {
	int	c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(isprint(c), ft_isprint(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, isprint(c), ft_isprint(c));
		c++;
	}
}

Test(tox, tolower) {
	int c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(tolower(c), ft_tolower(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, tolower(c), ft_tolower(c));
		c++;
	}
}

Test(tox, toupper) {
	int c;

	c = -10;
	while (c <= 130)
	{
		cr_expect_eq(toupper(c), ft_toupper(c), \
		"value passed: [%c]\nlibc: %d\nlibft: %d", c, toupper(c), ft_toupper(c));
		c++;
	}
}

Test(str, strlen_regular_input) {
	char *str = "0123456";
	cr_expect_eq(strlen(str), ft_strlen(str), \
	"value passed: [%s]\nlibc: %zu\nlibft: %zu", str, strlen(str), ft_strlen(str));
	str = "";
	cr_expect_eq(strlen(str), ft_strlen(str), \
	"value passed: [%s]\nlibc: %zu\nlibft: %zu", str, strlen(str), ft_strlen(str));
	cr_expect_eq(strlen(str), ft_strlen(str), \
	"value passed: [%s]\nlibc: %zu\nlibft: %zu", str, strlen(str), ft_strlen(str));
}

Test(str, strlen_null_input, .signal = SIGSEGV) {
	cr_expect(ft_strlen(NULL), "strlen does not segfault with input NULL");
}

Test(str, strncmp) {
	char *str = "0123456789";
	char *str1 = "01234567";
	cr_expect_eq(strncmp(str, str, 10), ft_strncmp(str, str, 10), \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str, str, strncmp(str, str, 10), ft_strncmp(str, str, 10));
	cr_expect_lt(ft_strncmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, strncmp(str1, str, 10), ft_strncmp(str1, str, 10));
	str = "01234567";
	str1 = "0123456789";
	cr_expect_gt(ft_strncmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, strncmp(str1, str, 10), ft_strncmp(str1, str, 10));
	cr_expect_eq(strncmp(str, str, 0), ft_strncmp(str, str, 0), \
	"values passed: [%s|%s|0]\nlibc: %d\nlibft: %d", str, str, strncmp(str, str, 0), ft_strncmp(str, str, 0));
	cr_expect_eq(strncmp(NULL, NULL, 0), ft_strncmp(NULL, NULL, 0), \
	"values passed: [NULL|NULL|0]\nlibc: %d\nlibft: %d", strncmp(NULL, NULL, 0), ft_strncmp(NULL, NULL, 0));
}

Test(str, strncmp_null, .signal = SIGSEGV) {
	ft_strncmp(NULL, "str", 4);
}

Test(convert, atoi) {
	char *str = "";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-0";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "+0";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "   +.";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-+";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-123 3";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-2147483648";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "-922337203685477590000999";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
	str = "922337203685999999999";
	cr_expect_eq(atoi(str), ft_atoi(str), \
	"value passed: [%s]\nlibc: %d\nlibft: %d", str, atoi(str), ft_atoi(str));
}

Test(convert, atoi_null, .signal = SIGSEGV) {
	cr_expect(ft_atoi(NULL), "ft_atoi does not segfault with input NULL");
}

Test(str, strchr) {
	char *str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char c = 'x';
	cr_expect_str_eq(strchr(str, c), ft_strchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strchr(str, c), ft_strchr(str, c));
	c = '\0';
	cr_expect_str_eq(strchr(str, c), ft_strchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strchr(str, c), ft_strchr(str, c));
	c = '1';
	cr_expect_null(ft_strchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strchr(str, c), ft_strchr(str, c));
}

Test(str, strchr_null, .signal = SIGSEGV) {
	char *str = NULL;
	char c = 'x';
	cr_expect_str_eq(ft_strchr(str, c), \
	"ft_strchr does not segfault with input NULL");
}

Test(str, strrchr) {
	char *str = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char c = 'x';
	cr_expect_str_eq(strrchr(str, c), ft_strrchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strrchr(str, c), ft_strrchr(str, c));
	c = '\0';
	cr_expect_str_eq(strrchr(str, c), ft_strrchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strrchr(str, c), ft_strrchr(str, c));
	c = '1';
	cr_expect_null(ft_strrchr(str, c), \
	"values passed: [%s|%c]\nlibc: %s\nlibft: %s", str, c, strrchr(str, c), ft_strrchr(str, c));
}

Test(str, strrchr_null, .signal = SIGSEGV) {
	char *str = NULL;
	char c = 'x';
	cr_expect_str_eq(ft_strrchr(str, c), \
	"ft_strrchr does not segfault with input NULL");
}

Test(str, strnstr) {
	char *str = "we're about to go searching in this hecking string\0DONOTSEARCHHERE";
	char *str1 = "this";
	cr_expect_str_eq(strnstr(str, str1, strlen(str)), strnstr(str, str1, strlen(str)), \
	"values passed: [%s|%s|%lu]\nlibc: %s\nlibft: %s", str, str1, strlen(str), strnstr(str, str1, strlen(str)), ft_strnstr(str, str1, strlen(str)));
	cr_expect_null(ft_strnstr(str, str1, 20), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, str1, 20, strnstr(str, str1, 20), ft_strnstr(str, str1, 20));
	cr_expect_null(ft_strnstr(str, str1, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, str1, 0, strnstr(str, str1, 0), ft_strnstr(str, str1, 0));
	str1 = "DONOT";
	cr_expect_null(ft_strnstr(str, str1, 65), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, str1, 65, strnstr(str, str1, 65), ft_strnstr(str, str1, 65));
}

Test(str, strnstr_null, .signal = SIGSEGV) {
	char *str = NULL;
	ft_strnstr(str, str, 20);
}

Test(str, strlcpy) {
	char *str = malloc(sizeof(char) * 10 + 1);
	char *str1 = malloc(sizeof(char) * 10 + 1);
	size_t ret = 0;
	size_t ret1 = 0;
	ret = strlcpy(str, "0123456789", 10);
	ret1 = ft_strlcpy(str1, "0123456789", 10);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, "0123456789", 10, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, "0123456789", 10, ret, ret1);
	ret = strlcpy(str, "0123456789", 0);
	ret1 = ft_strlcpy(str1, "0123456789", 0);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, "0123456789", 0, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, "0123456789", 10, ret, ret1);
	ret = strlcpy(str, "0123456789", 20);
	ret1 = ft_strlcpy(str1, "0123456789", 20);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, "0123456789", 20, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, "0123456789", 10, ret, ret1);
	free(str);
	free(str1);
}

Test(str, strlcpy_null, .signal = SIGSEGV) {
	ft_strlcpy(NULL, NULL, 6);
}

Test(str, strlcat) {
	char *str = strdup("start");
	char *str1 = strdup("start");
	char *app = "append";
	size_t ret = 0;
	size_t ret1 = 0;
	ret = strlcat(str, app, 11);
	ret1 = ft_strlcat(str1, app, 11);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, app, 11, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, app, 11, ret, ret1);
	ret = strlcat(str, app, 0);
	ret1 = ft_strlcat(str1, app, 0);
	cr_expect_str_eq(str, str1, \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", str, app, 0, str, str1);
	cr_expect_eq(ret, ret1, \
	"values passed: [%s|%s|%d]\nlibc: %zu\nlibft: %zu", str, app, 0, ret, ret1);
	free(str);
	free(str1);
}

Test(str, strlcat_null, .signal = SIGSEGV) {
	ft_strlcat(NULL, NULL, 0);
}

Test(mem, memcmp) {
	char *str = "0123456789";
	char *str1 = "01234567";
	cr_expect_eq(memcmp(str, str, 10), ft_memcmp(str, str, 10), \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str, str, memcmp(str, str, 10), ft_memcmp(str, str, 10));
	cr_expect_lt(ft_memcmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, memcmp(str1, str, 10), ft_memcmp(str1, str, 10));
	str = "01234567";
	str1 = "0123456789";
	cr_expect_gt(ft_memcmp(str1, str, 10), 0, \
	"values passed: [%s|%s|10]\nlibc: %d\nlibft: %d", str1, str, memcmp(str1, str, 10), ft_memcmp(str1, str, 10));
	cr_expect_eq(memcmp(str, str, 0), ft_memcmp(str, str, 0), \
	"values passed: [%s|%s|0]\nlibc: %d\nlibft: %d", str, str, memcmp(str, str, 0), ft_memcmp(str, str, 0));
	cr_expect_eq(memcmp(NULL, NULL, 0), ft_memcmp(NULL, NULL, 0), \
	"values passed: [NULL|NULL|0]\nlibc: %d\nlibft: %d", memcmp(NULL, NULL, 0), ft_memcmp(NULL, NULL, 0));
}

Test(mem, memcmp_null, .signal = SIGSEGV) {
	ft_memcmp(NULL, "str", 4);
}

Test(mem, memchr) {
	char *mem = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
	char c = 'x';
	cr_expect_str_eq(memchr(mem, c, 26), ft_memchr(mem, c, 26), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", mem, c, 26, memchr(mem, c, 26), ft_memchr(mem, c, 26));
	cr_expect_null(ft_memchr(mem, c, 0), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", mem, c, 0, memchr(mem, c, 0), ft_memchr(mem, c, 0));
	c = '\0';
	cr_expect_null(ft_memchr(mem, c, 26), \
	"values passed: [%s|(null)|%d]\nlibc: %s\nlibft: %s", mem, 26, memchr(mem, c, 26), ft_memchr(mem, c, 26));
	c = '1';
	cr_expect_null(ft_memchr(mem, c, 26), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", mem, c, 26, memchr(mem, c, 26), ft_memchr(mem, c, 26));
}

Test(mem, memchr_null, .signal = SIGSEGV) {
	char *mem = NULL;
	char c = 'x';
	cr_expect_null(memchr(mem, c, 26), \
	"ft_memchr does not segfault with input NULL");
}

Test(mem, memmove) {
	char *ret = strdup("this_is_the_memory_area");
	char *ret1 = strdup(ret);
	char *edit = strdup("copythis");
	cr_expect_str_eq(memmove(ret, edit, 23), ft_memmove(ret1, edit, 23), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret, edit, 23, memmove(ret, edit, 23), ft_memmove(ret1, edit, 23));
	cr_expect_str_eq(memmove(ret, ret + 5, 15), ft_memmove(ret1, ret1 + 5, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1, ret1 + 5, 15, memmove(ret, ret + 5, 15), ft_memmove(ret1, ret1 + 5, 15));
	cr_expect_str_eq(memmove(ret + 5, ret, 15), ft_memmove(ret1 + 5, ret1, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1 + 5, ret1, 15, memmove(ret + 5, ret, 15), ft_memmove(ret1 + 5, ret1, 15));
	cr_expect_str_eq(memmove(edit, NULL, 0), ft_memmove(edit, NULL, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memmove(edit, NULL, 0), ft_memmove(edit, NULL, 0));
	cr_expect_null(ft_memmove(NULL, edit, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memmove(edit, NULL, 0), ft_memmove(edit, NULL, 0));
	free(ret);
	free(ret1);
	free(edit);
}

Test(mem, memmove_null, .signal = SIGSEGV) {
	char *str = strdup("string");
	ft_memmove(str, NULL, 6);
}

Test(mem, memset) {
	char *str = malloc(10);
	char *str1 = malloc(10);
	char c = 'd';
	int len = 8;
	char *ret = memset(str, c, len);
	char *ret1 = ft_memset(str, c, len);
	cr_expect_str_eq(memset(str, c, len), ft_memset(str, c, len), \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	len = 0;
	c = 'a';
	ret = memset(str, c, len);
	ret1 = ft_memset(str, c, len);
	cr_expect_str_eq(ret, ret1, \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	ret = memset(NULL, c, len);
	ret1 = ft_memset(NULL, c, len);
	cr_expect_null(ret1, \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	len = 10;
	c = '\0';
	ret = memset(str, c, len);
	ret1 = ft_memset(str, c, len);
	cr_expect_str_eq(ret, ret1, \
	"values passed: [%s|%c|%d]\nlibc: %s\nlibft: %s", str, c, len, ret, ret1);
	free(str);
	free(str1);
}

Test(mem, memset_null, .signal = SIGSEGV) {
	ft_memset(NULL, 'c', 9);
}

Test(mem, bzero) {
	char str[20] = "epicstring";
	char str1[20] = "epicstring";
	int i = 0;
	int j = 0;
	int len = 5;
	bzero(str, (0));
	ft_bzero(str1, (0));
	cr_assert_str_eq(str, str1, \
	"values passed: [%s|%d]:\nlibc: %s\nlibft: %s", str, 0, str, str1);
	ft_bzero(NULL, 0);
	bzero(str, len);
	ft_bzero(str1, len);
	while (str[i] == '\0')
		i++;
	cr_assert_eq(i, len, \
	"did not set the right amount to 0");
}

Test(mem, bzero_null, .signal = SIGSEGV) {
	ft_bzero(NULL, 7);
}

Test(mem, memcpy) {
	char *ret = strdup("this_is_the_memory_area");
	char *ret1 = strdup(ret);
	char *edit = strdup("copythis");
	cr_expect_str_eq(memcpy(ret, edit, 23), ft_memcpy(ret1, edit, 23), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret, edit, 23, memcpy(ret, edit, 23), ft_memcpy(ret1, edit, 23));
	cr_expect_str_eq(memcpy(ret, ret + 5, 15), ft_memcpy(ret1, ret1 + 5, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1, ret1 + 5, 15, memcpy(ret, ret + 5, 15), ft_memcpy(ret1, ret1 + 5, 15));
	cr_expect_str_eq(memcpy(ret + 5, ret, 15), ft_memcpy(ret1 + 5, ret1, 15), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", ret1 + 5, ret1, 15, memcpy(ret + 5, ret, 15), ft_memcpy(ret1 + 5, ret1, 15));
	cr_expect_str_eq(memcpy(edit, NULL, 0), ft_memcpy(edit, NULL, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memcpy(edit, NULL, 0), ft_memcpy(edit, NULL, 0));
	cr_expect_null(ft_memcpy(NULL, edit, 0), \
	"values passed: [%s|%s|%d]\nlibc: %s\nlibft: %s", edit, NULL, 0, memcpy(edit, NULL, 0), ft_memcpy(edit, NULL, 0));
	free(ret);
	free(ret1);
	free(edit);
}

Test(mem, memcpy_null, .signal = SIGSEGV) {
	char *str = strdup("string");
	ft_memcpy(str, NULL, 6);
}

Test(mem, memccpy) {
	char dst[21] = "0123456789abcdefghij";
	char dst1[21] = "0123456789abcdefghij";
	char src[21] = "abcdefghij0123456789";
	char *ret = ft_memccpy(dst1, src, 'A', 4);
	char *ret1 = memccpy(dst, src, 'A', 4);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'A', 4, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'A', 4, dst, dst1);
	ret = ft_memccpy(dst1, src, 'f', 5);
	ret1 = memccpy(dst, src, 'f', 5);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 5, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 5, dst, dst1);
	ret = ft_memccpy(dst1, src, 'f', 8);
	ret1 = memccpy(dst, src, 'f', 8);
	cr_expect_str_eq(ret, ret1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 8, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", "0123456789abcdefghij", src, 'f', 8, dst, dst1);
	ret = ft_memccpy(NULL, src, 'f', 0);
	ret1 = memccpy(NULL, src, 'f', 0);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", NULL, src, 'f', 0, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", NULL, src, 'f', 0, dst, dst1);
	ret = ft_memccpy(src, NULL, 'f', 0);
	ret1 = memccpy(src, NULL, 'f', 0);
	cr_expect_null(ret, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", src, NULL, 'f', 0, ret1, ret);
	cr_expect_str_eq(dst, dst1, \
	"values passed: [%s|%s|%c|%d]\nlibc: %s\nlibft: %s", src, NULL, 'f', 0, dst, dst1);
}

Test(mem, memccpy_null_src, .signal = SIGSEGV) {
	char str[40] = "very cool";
	ft_memccpy(NULL, str, 'a', 6);

}

Test(mem, memccpy_null_dst, .signal = SIGSEGV) {
	char str[40] = "very cool";
	ft_memccpy(str, NULL, 'a', 6);

}

Test(stralloc, calloc) {
	char *str = ft_calloc(5, 5);
	char *str1 = calloc(5, 5);
	int cool = 1;
	int i = 0;
	while (i > 25)
	{
		if (str[i] != 0)
			cool = 0;
		i++;
	}
	cr_expect(cool, \
	"values passed: [%d|%d]\n libc: %s\n libft: %s", 5, 5, str, str1);
	cr_expect_str_eq(str1, str, \
	"values passed: [%d|%d]\n libc: %s\n libft: %s", 5, 5, str, str1);
	free(str);
	free(str1);
}

Test(stralloc, strdup) {
	char *dup = "duplicate this";
	char *dup1 = "";
	char *str1 = ft_strdup(dup);
	char *str2 = strdup(dup);
	cr_assert_str_eq(str1, str2, \
	"value passed: [%s]\nlibc: %s\nlibft: %s", dup, str1, str2);
	free(str1);
	free(str2);
	str1 = ft_strdup(dup1);
	str2 = strdup(dup1);
	cr_assert_str_eq(str1, str2, \
	"value passed: [%s]\nlibc: %s\nlibft: %s", dup1, str1, str2);
	free(str1);
	free(str2);
}

Test(stralloc, strdup_null, .signal = SIGSEGV) {
	char *str = ft_strdup(NULL);
}

// PART 2:

Test(convert, itoa) {
	int n = 0;
	char *ret;

	ret = ft_itoa(n);
	cr_expect_str_eq("0", ret, \
	"value passed: [%d]\nlibft: %s", n, ret);
	free(ret);
	n = INT_MIN;
	ret = ft_itoa(n);
	cr_expect_str_eq("-2147483648", ret, \
	"value passed: [%d]\nlibft: %s", n, ret);
	free(ret);
	n = INT_MAX;
	ret = ft_itoa(n);
	cr_expect_str_eq("2147483647", ret, \
	"value passed: [%d]\nlibft: %s", n, ret);
	free(ret);
	n = -45390001;
	ret = ft_itoa(n);
	cr_expect_str_eq("-45390001", ret, \
	"value passed: [%d]\nlibft: %s", n, ret);
	free(ret);
	n = 45390001;
	ret = ft_itoa(n);
	cr_expect_str_eq("45390001", ret, \
	"value passed: [%d]\nlibft: %s", n, ret);
	free(ret);
	n = 1000;
	ret = ft_itoa(n);
	cr_expect_str_eq("1000", ret, \
	"value passed: [%d]\nlibft: %s", n, ret);

}

Test(stralloc, substr) {
	int start = 0;
	int len = 6;
	char *str = "please6make1some6substrings";
	char *str1 = ft_substr(str, start, len);
	cr_expect_str_eq(str1, "please", \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", str, start, len, "please", str1);
	free(str1);
	start = 6;
	len = 1;
	str1 = ft_substr(str, start, len);
	cr_expect_str_eq(str1, "6", \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", str, start, len, "6", str1);
	free(str1);
	start = 6;
	len = 0;
	str1 = ft_substr(str, start, len);
	cr_expect_str_eq(str1, "", \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", str, start, len, "", str1);
	free(str1);
	start = 26;
	len = 5;
	str1 = ft_substr(str, start, len);
	cr_expect_str_eq(str1, "s", \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", str, start, len, "s", str1);
	free(str1);
	str1 = ft_substr("", 0, 5);
	cr_expect_str_empty(str1, \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", "", 0, 5, "s", str1);
	free(str1);
	str1 = ft_substr("0123557", 10, 5);
	cr_expect_str_empty(str1, \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", "", 0, 5, "s", str1);
	free(str1);
	str1 = ft_substr(NULL, 0, 5);
	cr_expect_null(str1, \
	"values passed: [%s|%d|%d]\nexpected: %s\nlibft: %s", "", 0, 5, "(null)", str1);
	free(str1);
}

Test(stralloc, strjoin) {
	char *str = "you're ";
	char *str1 = "valid <3";
	char *expected = "you're valid <3";
	char *joined = ft_strjoin(str, str1);
	cr_expect_str_eq(joined, expected, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", str, str1, expected, joined);
	free(joined);
	expected = "valid <3";
	joined = ft_strjoin("", str1);
	cr_expect_str_eq(joined, expected, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", "", str1, expected, joined);
	free(joined);
	expected = "you're ";
	joined = ft_strjoin(str, "");
	cr_expect_str_eq(joined, expected, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", str, str1, expected, joined);
	free(joined);
	expected = "";
	joined = ft_strjoin("", "");
	cr_expect_str_eq(joined, expected, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", str, str1, expected, joined);
	free(joined);
	cr_expect_null(ft_strjoin(NULL, "aaa"), \
	"does not protect against null input");
	cr_expect_null(ft_strjoin("aaa", NULL), \
	"does not protect against null input");
	cr_expect_null(ft_strjoin(NULL, NULL), \
	"does not protect against null input");
}

Test(stralloc, strtrim) {
	char *set = "abcd";
	char *totrim = "abcbbcbabcbThis will be leftbabbcbcbadd";
	char *expected = "This will be left";
	char *trimmed = ft_strtrim(totrim, set);
	cr_expect_str_eq(expected, trimmed, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", totrim, set, expected, trimmed);
	free(trimmed);
	set = "";
	trimmed = ft_strtrim(totrim, set);
	expected = totrim;
	cr_expect_str_eq(expected, trimmed, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", totrim, set, expected, trimmed);
	free(trimmed);
	set = "123";
	trimmed = ft_strtrim(totrim, set);
	cr_expect_str_eq(expected, trimmed, \
	"values passed: [%s|%s]\nexpected: %s\nlibft: %s", totrim, set, expected, trimmed);
	free(trimmed);
	cr_expect_null(ft_strtrim(NULL, "123"), \
	"does not protect against null input");
	cr_expect_null(ft_strtrim("123", NULL), \
	"does not protect against null input");
}

Test(stralloc, split) {
	char *tosplit = "     this    string  will     be split     !   ";
	char delim = ' ';
	char expected[7][50] = {"this", "string", "will", "be", "split", "!"};
	char **split = ft_split(tosplit, delim);
	int i = 0;
	while (i < 6)
	{
		cr_assert_str_eq(expected[i], split[i], \
		"values passed: [%s|%c] (curr_word = %d)\nexpected: %s\nlibft: %s", tosplit, delim, i, expected[i], split[i]);
		i++;
	}
	i++;
	cr_expect_null(split[i], \
	"did not set the last pointer to NULL");
	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
	cr_expect_null(ft_split(NULL, ' '), \
	"does not protect against null input");
	split = ft_split(tosplit, '\0');
	cr_expect_str_eq(tosplit, split[0], \
	"does not return full string in case of null byte delimiter");
	cr_expect_null(split[1], \
	"did not set the last pointer to NULL (in case of one word)");
	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
	split = ft_split(tosplit, 'Z');
	cr_expect_str_eq(tosplit, split[0], \
	"does not work if delimiter not in string to split");
	cr_expect_null(split[1], \
	"did not set the last pointer to NULL (in case of one word)");
	i = 0;
	while (split[i])
	{
		if (split[i])
			free(split[i]);
		i++;
	}
	free(split);
}

Test(stralloc, strmapi) {
	char *str = "*string intensifies*";
	char *expected = "*STRING INTENSIFIES*";
	char *ret = ft_strmapi(str, &test);
	cr_assert_str_eq(ret, expected, \
	"values passed [%s|%s]\nexpected: %s\nlibft: %s", str, "&toupper", expected, ret);
	free(ret);
	cr_expect_null(ft_strmapi(NULL, &test), \
	"does not protect against null input arg0");
	cr_expect_null(ft_strmapi(str, NULL), \
	"does not protect against null input");
}

Test(output, putchar_fd) {
	char buf[1];
	int p[2];
	char *c = "a";
	pipe(p);
	ft_putchar_fd(c[0], p[1]);
	read(p[0], buf, 1);
	cr_expect(strcmp(buf, c), \
	"your putchar does not put the right char");
}

Test(output, putstr_fd) {
	char buf[11];
	int p[2];
	char *c = "0123456789";
	pipe(p);
	ft_putstr_fd(c, p[1]);
	read(p[0], buf, 11);
	cr_expect_str_eq(buf, c, \
	"your putstr does not put the correct string");
}

Test(output, putendl_fd) {
	char buf[12];
	int p[2];
	char *c = "0123456789";
	pipe(p);
	ft_putstr_fd(c, p[1]);
	read(p[0], buf, 12);
	c = "0123456789\n";
	cr_expect(strcmp(buf, c), \
	"your putendl did not put a newline");
}

Test(output, putnbr_fd) {
	char buf[11];
	int p[2];
	int n = INT_MIN;
	char *c = "-2147483648";
	pipe(p);
	ft_putnbr_fd(n, p[1]);
	read(p[0], buf, 11);
	cr_expect(strcmp(buf, c), \
	"your putnbr does not handle min int");
	c = "-420";
	n = -420;
	ft_putnbr_fd(n, p[1]);
	read(p[0], buf, 4);
	cr_expect(strcmp(buf, c), \
	"your putnbr does not handle negative numbers");
	c = "420";
	n = 420;
	ft_putnbr_fd(n, p[1]);
	read(p[0], buf, 4);
	cr_expect(strcmp(buf, c), \
	"your putnbr does not handle regular input");
	c = "0";
	n = 0;
	ft_putnbr_fd(n, p[1]);
	read(p[0], buf, 4);
	cr_expect(strcmp(buf, c), \
	"your putnbr does not handle '0' input");
}

// BONUS:

Test(lst, lstnew) {
	t_list *cool;

	cool = ft_lstnew("amazing");
	cr_expect_null(cool->next, \
	"your lstnew does not set next to null");
	cr_expect_str_eq(cool->content, "amazing", \
	"lstnew does not set the content correctly");
	free(cool);
	cool = ft_lstnew((void*)0);
	cr_expect_null(cool->next, \
	"your lstnew does not set next to null");
	cr_expect_null(cool->content, \
	"lstnew does not set the content correctly if content given is null");
	free(cool);
}

Test(lst, lstadd_front) {
	t_list *head;
	t_list *new;
	char *str;
	char *str1;

	str = "will be at the front";
	str1 = "should be at the back";
	new = ft_lstnew(str);
	head = ft_lstnew(str1);
	ft_lstadd_front(&head, new);
	cr_expect_str_eq(head->content, str, \
	"values passed: &head, new\nhead->content: %s\nexpected: %s", head->content, str);
	cr_expect_str_eq(head->next->content, str1, \
	"values passed: &head, new\nhead->content: %s\nexpected: %s", head->next->content, str1);
	free(head->next);
	free(head);
}

Test(lst, lstsize) {
	t_list *head;
	t_list *new;
	t_list *store;
	char *str;
	char *str1;
	int	i;

	str = "will be at the front";
	str1 = "should be at the back";
	new = ft_lstnew(str);
	store = new;
	while (new)
	{
		i++;
		new = new->next;
	}
	cr_expect_eq(i, 1, \
	"lstsize does not work with one list node");
	head = ft_lstnew(str1);
	ft_lstadd_front(&head, store);
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
	}
	cr_expect_eq(i, 2, \
	"lstsize does not work on basic input");
	free(store);
	free(head);
}

Test(lst, lstlast) {
	t_list *head;
	t_list *new;
	t_list *last;
	char *str;
	char *str1;

	str = "will be at the front";
	str1 = "should be at the back";
	new = ft_lstnew(str);
	head = ft_lstnew(str1);
	ft_lstadd_front(&head, new);
	last = ft_lstlast(head);
	cr_expect_null(last->next, \
	"lstlast return->next is not null");
	cr_expect_str_eq(str1, last->content, \
	"lstlast does not return the right node");
}

Test(lst, lstadd_back) {
	t_list *head;
	t_list *new;
	char *str;
	char *str1;

	str = "will be at the front";
	str1 = "should be at the back";
	new = ft_lstnew(str1);
	head = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	cr_expect_str_eq(head->content, str, \
	"values passed: &head, new\nhead->content: %s\nexpected: %s", head->content, str);
	cr_expect_str_eq(head->next->content, str1, \
	"values passed: &head, new\nhead->content: %s\nexpected: %s", head->next->content, str1);
	free(head->next);
	free(head);
}

void	wordupper(void *thing)
{
	char *str;
	int i;

	i = 0;
	str = (char *)thing;
	while(str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	thing = str;
}

Test(lst, lstiter) {
	t_list *head;
	t_list *new;
	char *str;
	char *str1;

	str = strdup("will be at the front");
	str1 = strdup("should be at the back");
	new = ft_lstnew(str1);
	head = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	ft_lstiter(head, &wordupper);
	cr_expect_str_eq(head->content, "WILL BE AT THE FRONT", \
	"head, &wordupper\nexpected: %s\nactual: %s", "WILL BE AT THE FRONT", head->content);
	cr_expect_str_eq(head->next->content,  "SHOULD BE AT THE BACK", \
	"head, &wordupper\nexpected: %s\nactual: %s", "SHOULD BE AT THE BACK", head->next->content);
	ft_lstclear(&head, &free);
}

void	*wordupper_ret(void *thing)
{
	char *str;
	char *ret;
	int i;

	i = 0;
	str = (char *)thing;
	ret = malloc(sizeof(char *) * ft_strlen(thing) + 1);
	while(str[i])
	{
		ret[i] = ft_toupper(str[i]);
		i++;
	}
	return (ret);
}

Test(lst, lstmap) {
	t_list *head;
	t_list *new;
	t_list *dup;
	char *str;
	char *str1;
	char *str2;

	str = strdup("will be at the front");
	str1 = strdup("should be at the back");
	new = ft_lstnew(str1);
	head = ft_lstnew(str);
	ft_lstadd_back(&head, new);
	dup = ft_lstmap(head, &wordupper_ret, &free);
	str2 = wordupper_ret(head->content);
	cr_expect_str_eq(str2, dup->content, \
	"head->content, dup->content\nexpected: %s\nactual: %s", head->content, dup->content);
	free(str2);
	str2 = wordupper_ret(head->next->content);
	cr_expect_str_eq(str2,  dup->next->content, \
	"head, &ft_strdup\nexpected: %s\nactual: %s", head->next->content, dup->next->content);
	free(str2);
	ft_lstclear(&dup, &free);
	ft_lstclear(&head, &free);
}
