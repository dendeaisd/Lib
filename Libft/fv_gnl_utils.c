/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:44:41 by fvoicu            #+#    #+#             */
/*   Updated: 2024/01/02 14:45:11 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int32_t	gnl_strlen_nl(char *str)
{
	int32_t		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '\n')
			return (i);
	}
	return (-1);
}

void	*gnl_memcpy(char *dst, char *src, size_t n)
{
	int32_t		i;

	i = 0;
	if (dst == 0 && src == 0)
		return (0);
	while (n > 0)
	{
		dst[i] = src[i];
		++i;
		--n;
	}
	dst[i] = '\0';
	return (dst);
}

size_t	gnl_strlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c)
		++i;
	return (i);
}

char	*gnl_strndup(char *s1, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	ret = malloc(sizeof(*s1) * (len + 1));
	if (ret == NULL)
		return (0);
	while (i < len)
	{
		ret[i] = s1[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen(s1, '\0') + gnl_strlen(s2, '\0');
	if (s1 == NULL)
		return (NULL);
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (*s1)
	{
		new[i] = *s1;
		++s1;
		++i;
	}
	while (*s2)
	{
		new[i] = *s2;
		++s2;
		++i;
	}
	new[i] = '\0';
	return (new);
}