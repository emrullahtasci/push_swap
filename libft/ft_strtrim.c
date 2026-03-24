/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:20:31 by mkotan            #+#    #+#             */
/*   Updated: 2026/01/24 17:25:45 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
	{
		return (ft_strdup(""));
	}
	end = ft_strlen(s1) - 1;
	while (s1[start] && is_in_set(s1[start], set))
	{
		start++;
	}
	while (end > start && is_in_set(s1[end], set))
	{
		end--;
	}
	if (start > end)
	{
		return (ft_strdup(""));
	}
	return (ft_substr(s1, start, end - start + 1));
}
