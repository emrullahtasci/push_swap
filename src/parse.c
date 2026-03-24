/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:45:43 by etasci            #+#    #+#             */
/*   Updated: 2026/03/24 17:21:51 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:46:58 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 17:21:33 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *s, t_config *cfg)
{
	if (ft_strncmp(s, "--simple", 9) == 0)
	{
		cfg->strategy = SIMPLE;
		return (1);
	}
	if (ft_strncmp(s, "--medium", 9) == 0)
	{
		cfg->strategy = MEDIUM;
		return (1);
	}
	if (ft_strncmp(s, "--complex", 10) == 0)
	{
		cfg->strategy = COMPLEX;
		return (1);
	}
	if (ft_strncmp(s, "--adaptive", 11) == 0)
	{
		cfg->strategy = ADAPTIVE;
		return (1);
	}
	if (ft_strncmp(s, "--bench", 8) == 0)
	{
		cfg->bench = 1;
		return (1);
	}
	return (0);
}

static int	is_valid_number(char *s)
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

static long	ft_atoi(char *s)
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
		i++;
	}
	return (result * sign);
}

static int	has_duplicate(t_node *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_node	*parse_args(int argc, char **argv, t_config *cfg)
{
	t_node	*stack;
	long	val;
	int		i;

	stack = NULL;
	cfg->strategy = ADAPTIVE;
	cfg->bench = 0;
	i = 1;
	while (i < argc)
	{
		if (is_flag(argv[i], cfg))
		{
			i++;
			continue ;
		}
		if (!is_valid_number(argv[i]))
			error_exit(&stack, NULL);
		val = ft_atoi(argv[i]);
		if (val > 2147483647 || val < -2147483648)
			error_exit(&stack, NULL);
		if (has_duplicate(stack, (int)val))
			error_exit(&stack, NULL);
		stack_add_back(&stack, stack_new((int)val));
		i++;
	}
	return (stack);
}
