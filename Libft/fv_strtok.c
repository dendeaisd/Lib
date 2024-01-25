/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:28:47 by fvoicu            #+#    #+#             */
/*   Updated: 2024/01/25 19:38:19 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

char	*fv_strtok(char *str, const char *delim)
{
	static char	*buff;
	char		*token_start;

	if (str)
		buff = str;
	if (!buff || !delim)
		return (NULL);
	while (*buff && ft_strchr(delim, *buff))
		++buff;
	if (!(*buff))
		return (NULL);
	token_start = buff;
	while (*buff && !ft_strchr(delim, *buff))
		++buff;
	if (*buff)
	{
		*buff = '\0';
		++buff;
	}
	return (token_start);
}

char	*fv_strtok_r(char *str, const char *delim, char **saveptr)
{
	char	*end;

	if (!str)
		str = *saveptr;
	if (!str || !(*str))
		return (NULL);
	str += fv_strspn(str, delim);
	if (!(*str))
		return (NULL);
	end = str + fv_strcspn(str, delim);
	if (*end)
		return (*end = '\0', *saveptr = end + 1, str);
	else
		*saveptr = end;
	return (str);
}
