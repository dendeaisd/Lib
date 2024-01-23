/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:49:17 by fvoicu            #+#    #+#             */
/*   Updated: 2024/01/02 22:03:45 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	fv_matchc(char *str, char *accept)
{
	size_t	ret;

	ret = -1;
	if (accept[0] == '\0')
		return (ft_strlen(str));
	while (str[++ret] != '\0')
	{
		if (ft_strchr(accept, str[ret]))
			return (ret);
	}
	return (ft_strlen(str));
}

size_t	fv_match(char *str, char *accept)
{
	size_t	size;
	size_t	ret;

	ret = 0;
	size = -1;
	while (str[++size] != '\0')
	{
		if (!(ft_strchr(accept, str[size])))
			return (ret);
		else
			++ret;
	}
	return (ret);
}