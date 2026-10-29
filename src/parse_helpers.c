/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:23:29 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/25 17:23:40 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_flag(char *s, t_config *cfg)
{
	if (ft_strncmp(s, "--simple", 9) == 0)
		cfg->strategy = SIMPLE;
	else if (ft_strncmp(s, "--medium", 9) == 0)
		cfg->strategy = MEDIUM;
	else if (ft_strncmp(s, "--complex", 10) == 0)
		cfg->strategy = COMPLEX;
	else if (ft_strncmp(s, "--adaptive", 11) == 0)
		cfg->strategy = ADAPTIVE;
	else if (ft_strncmp(s, "--bench", 8) == 0)
	{
		cfg->bench = 1;
		return (1);
	}
	else
		return (0);
	return (1);
}

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (!s || !s[0])
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

long	ft_atol(char *s)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		if (result > 2147483648L)
			return (result * sign);
		i++;
	}
	return (result * sign);
}

int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
