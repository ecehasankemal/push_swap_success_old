/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:21:28 by hece              #+#    #+#             */
/*   Updated: 2023/01/21 20:21:30 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (size > 0)
	{
		while (index < (size - 1) && src[index] != '\0')
		{
			dest[index] = src[index];
			index++;
		}
		dest[index] = '\0';
	}
	while (src[index] != '\0')
	{
		index++;
	}
	return (index);
}

size_t	count_words(const char *s, char c)
{
	int	index;
	int	count;
	int	trigger;

	index = 0;
	count = 0;
	trigger = 0;
	while (s[index] != '\0')
	{
		if (s[index] != c && trigger == 0)
		{
				trigger = 1;
				count++;
		}
		else if (s[index] == c)
				trigger = 0;
		index++;
	}
	return (count);
}

char	*ft_strcreate(const char *s, char c, size_t counter)
{
	size_t	len;
	size_t	tmp;

	len = 0;
	tmp = counter;
	while (s[tmp] != c && s[tmp] != '\0')
	{
		tmp++;
		len++;
	}	
	return (ft_substr(s, counter, len));
}

char	**ft_split(char const *s, char c)
{
	size_t	counter;
	size_t	iter;
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	counter = 0;
	iter = 0;
	while (s[counter] != '\0')
	{
		while (s[counter] == c && s[counter] != '\0')
			counter++;
		if (s[counter] != '\0')
		{
			res[iter] = ft_strcreate(s, c, counter);
			iter++;
		}
		while (s[counter] != c && s[counter] != '\0')
			counter++;
	}
	res[iter] = 0;
	return (res);
}
