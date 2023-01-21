/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 10:22:27 by hece              #+#    #+#             */
/*   Updated: 2023/01/21 10:22:28 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_gnl_strchr(char *str)
{
	int	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index])
	{
		if (str[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

static inline char	*ft_gnl_strjoin(char *s1, char *s2, int i, int j)
{
	char	*str;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char));
		s1[0] = '\0';
	}
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	str = (char *)malloc(sizeof(char) * (i + j + 1));
	i = -1;
	j = 0;
	if (!str)
		return (NULL);
	while (++i, s1[i])
		str[i] = s1[i];
	while (s2[j++] != '\0')
		str[i - 1 + j] = s2[j - 1];
	str[i + j - 1] = '\0';
	free(s1);
	return (str);
}

static inline char	*ft_new_create_buffer(char *buffer, int i, int j, int len)
{
	char	*res;

	while (buffer[len])
		len++;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	res = (char *)malloc(sizeof(char) * (len + 1 - i++));
	if (!res)
		return (NULL);
	while (buffer[i])
		res[j++] = buffer[i++];
	res[j] = '\0';
	free(buffer);
	return (res);
}

static inline char	*ft_cb(char *buffer, int buff_size, int fd, char *temp)
{
	if (!temp)
		return (NULL);
	while ((buff_size != 0 && !ft_gnl_strchr(buffer)))
	{
		buff_size = read(fd, temp, BUFFER_SIZE);
		if (buff_size == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[buff_size] = '\0';
		buffer = ft_gnl_strjoin(buffer, temp, 0, 0);
	}
	free(temp);
	if (buffer[0] == 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	int			index;
	static char	*buf;
	char		*line;

	index = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = ft_cb(buf, 1, fd, (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)));
	if (!buf)
		return (NULL);
	while (buf[index] && buf[index] != '\n')
		index++;
	line = (char *)malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	index = -1;
	while (buf[++index] && buf[index] != '\n')
		line[index] = buf[index];
	if (buf[++index - 1] == '\n')
		line[index - 1] = buf[index - 1];
	line[index] = '\0';
	buf = ft_new_create_buffer(buf, 0, 0, 0);
	return (line);
}
