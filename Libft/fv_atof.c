/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 22:57:14 by fvoicu            #+#    #+#             */
/*   Updated: 2024/01/25 23:10:58 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0.0;
	while (**str >= '0' && **str <= '9')
	{
		result = result * 10.0 + (**str - '0');
		++(*str);
	}
	return (result);
}

static double	parse_fractional_part(const char **str)
{
	double	fraction;
	double	result;

	fraction = 0.1;
	result = 0.0;
	if (**str == '.')
	{
		++(*str);
		while (**str >= '0' && **str <= '9')
		{
			result += (**str - '0') * fraction;
			fraction *= 0.1;
			++(*str);
		}
	}
	return (result);
}

double	fv_atof(const char *str)
{
	double	sign;
	double	fraction;
	double	result;

	sign = 1.0;
	fraction = 0.1;
	result = 0.0;
	if (*str == '-')
	{
		sign = -1.0;
		++str;
	}
	else
		++str;
	result = parse_integer_part(&str);
	result += parse_fractional_part(&str);
	return (sign * result);
}
