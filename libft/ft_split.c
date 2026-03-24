/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:01:15 by mkotan            #+#    #+#             */
/*   Updated: 2026/02/04 00:18:22 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

static size_t	word_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
	{
		len++;
	}
	return (len);
}

static void	free_all(char **arr, size_t i)
{
	while (i > 0)
	{
		free(arr[i - 1]);
		i--;
	}
}

static int	func_x(const char *s, char **arr, size_t len, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		len = word_len(&s[i], c);
		arr[j] = malloc(sizeof(char) * (len + 1));
		if (!arr[j])
		{
			free_all(arr, j);
			return (0);
		}
		ft_strlcpy(arr[j], &s[i], len + 1);
		j++;
		i = i + len;
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	len;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!arr)
		return (NULL);
	len = 0;
	if (!func_x(s, arr, len, c))
	{
		return (NULL);
	}
	return (arr);
}
