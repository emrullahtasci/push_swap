/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:11:01 by mkotan            #+#    #+#             */
/*   Updated: 2026/02/04 00:18:57 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	len_count(long int nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
	{
		len = 1;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	size_t		len;
	char		*str;

	nbr = n;
	if (nbr == 0)
		return (ft_strdup("0"));
	len = len_count(nbr);
	if (nbr < 0)
		nbr = -nbr;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nbr > 0)
	{
		str[--len] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
