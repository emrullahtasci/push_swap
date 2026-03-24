/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 13:37:11 by mkotan            #+#    #+#             */
/*   Updated: 2026/02/04 00:17:50 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	create_sub(char **sub, const char *s, size_t real_len,
				size_t start);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	real_len;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		sub = malloc(1);
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > slen - start)
		real_len = slen - start;
	else
		real_len = len;
	if (create_sub(&sub, s, real_len, start) == 1)
		return (NULL);
	return (sub);
}

static int	create_sub(char **sub, const char *s, size_t real_len, size_t start)
{
	size_t	i;

	*sub = malloc(real_len + 1);
	if (!(*sub))
		return (1);
	i = 0;
	while (i < real_len)
	{
		(*sub)[i] = s[start + i];
		i++;
	}
	(*sub)[i] = '\0';
	return (0);
}
