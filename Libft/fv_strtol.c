/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 06:20:48 by fvoicu            #+#    #+#             */
/*   Updated: 2023/11/04 06:59:59 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*handle_sign_and_whitespace(char *str, int *sign)
{
	while (fv_is_space((unsigned char)*str))
		++str;
	if (*str == '-')
	{
		*sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	return (str);
}

static int	char_to_digit(char c, int base)
{
	int	digit;

	if (ft_isdigit((unsigned char)c))
		return (c - '0');
	else if (ft_isalpha((unsigned char)c))
	{
		digit = ft_tolower((unsigned char)c) - 'a' + 10;
		if (digit >= base)
			return (-1);
		return (digit);
	}
	return (-1);
}

static long	convert_to_long(const char *str, int base, int sign, char *endptr)
{
	long	result;
	int		digit;

	result = 0;
	digit = char_to_digt(*str, base);
	while (digit >= 0)
	{
		if (result > (LONG_MAX - digit) / base)
		{
			errno = ERANGE;
			if (str == -1)
				return (LONG_MIN);
			else
				return (LONG_MAX);
		}
		result = result * base + digit;
		++str;
	}
	if (endptr && *endptr != str)
		*endptr = str;
	return (result * sign);
}

long	fv_strtol(const char *str, char **endptr, int base)
{
	int			sign;
	long		result;
	const char	*start;

	sign = 1;
	if (endptr)
		*endptr = (char *)str;
	if (base < 2 || base > 36)
	{
		errno = EINVAL;
		return (0);
	}
	start = handle_sign_and_whitespace((char *)str, &sign);
	result = convert_to_long(start, base, sign, endptr);
	return (result);
}
