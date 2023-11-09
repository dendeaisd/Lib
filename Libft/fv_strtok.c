/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:28:47 by fvoicu            #+#    #+#             */
/*   Updated: 2023/11/09 08:15:35 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *fv_strtok(char *str, const char *delim)
{
    static char *buff;
    char *token_start;
    char *token;

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
        *buff++ = '\0';
    token = ft_strdup(token_start);
    return token;
}
