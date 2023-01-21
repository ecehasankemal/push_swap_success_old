/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hece <hece@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 20:00:55 by hece              #+#    #+#             */
/*   Updated: 2023/01/21 20:00:55 by hece             ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 37
# endif

char	*get_next_line(int fd);

// all utils
int		ft_abs(int num);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	count_words(const char *s, char c);
char	*ft_strcreate(const char *s, char c, size_t counter);
char	**ft_split(char const *s, char c);

#endif
