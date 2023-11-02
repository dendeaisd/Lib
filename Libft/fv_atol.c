/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:10:56 by fvoicu            #+#    #+#             */
/*   Updated: 2023/11/02 21:57:09 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	fv_atol(const char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (fv_is_space(*str))
		++str;
	if (*str == '-')
	{
		sign = -1;
		++str;
	}
	else if (*str == '+')
		++str;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		++str;
	}
	return (res * sign);
}
