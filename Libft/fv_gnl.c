/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fv_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 14:43:27 by fvoicu            #+#    #+#             */
/*   Updated: 2024/01/02 14:46:02 by fvoicu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	gnl_checkbuf(char *tmp)
{
	if (tmp)
	{
		if (gnl_strlen_nl(tmp) >= 0)
			return (1);
	}
	return (0);
}

static int	gnl_make_temp(char **tmp, char *buf)
{
	char	*ptr;

	ptr = NULL;
	if (buf == NULL)
		return (-1);
	if (*tmp)
		ptr = gnl_strjoin(*tmp, buf);
	else
		ptr = gnl_strndup(buf, gnl_strlen(buf, '\0'));
	if (ptr == NULL)
		return (-1);
	free(*tmp);
	*tmp = ptr;
	return (0);
}

static int	gnl_make(char **line, char **tmp, char c)
{
	t_ldata		data;

	data.str = NULL;
	if (*tmp == NULL)
		return (-1);
	data.plen = 0;
	data.len = gnl_strlen(*tmp, c);
	data.str = gnl_strndup(*tmp, data.len);
	if (data.str == NULL)
		return (-1);
	data.plen = gnl_strlen(*tmp, '\0');
	if (data.len + 1 < data.plen)
		gnl_memcpy(*tmp, (*tmp + data.len + 1), (data.plen - data.len));
	else
	{
		free(*tmp);
		*tmp = NULL;
	}
	*line = data.str;
	if (c == '\n')
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	t_data			data;
	static char		*tmp[1024];

	if (fd < 0 || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (gnl_checkbuf(tmp[fd]))
		return (gnl_make(line, &tmp[fd], '\n'));
	else
		data.ret = read(fd, data.buf, BUFFER_SIZE);
	if (data.ret <= 0 && tmp[fd] == NULL)
	{
		if (data.ret == 0)
			*line = gnl_strndup("", 1);
		if (data.ret == 0)
			return (0);
		return (-1);
	}
	data.buf[data.ret] = '\0';
	if (gnl_make_temp(&tmp[fd], data.buf) == -1)
		return (-1);
	if (data.ret == 0)
		return (gnl_make(line, &tmp[fd], '\0'));
	else if (gnl_strlen_nl(tmp[fd]) >= 0)
		return (gnl_make(line, &tmp[fd], '\n'));
	return (get_next_line(fd, line));
}