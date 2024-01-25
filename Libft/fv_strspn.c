/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 19:33:50 by fvoicu            #+#    #+#             */
/*   Updated: 2024/01/25 19:37:21 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	fv_strspn(const char *str, const char *set)
{
	const char	*p;
	const char	*q;

	p = str;
	q = 0;
	while (*p)
	{
		q = set;
		while (*q)
		{
			if (*p == *q)
				break ;
			++q;
		}
		if (!*q)
			break ;
		++p;
	}
	return (p - str);
}

size_t	fv_strcspn(const char *str, const char *set)
{
	const char	*p;
	const char	*q;

	p = str;
	q = 0;
	while (*p)
	{
		q = set;
		while (*q)
		{
			if (*p == *q)
				return (p - str);
			++q;
		}
		++p;
	}
	return (p - str);
}
