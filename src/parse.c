/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:45:43 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:22:45 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	parse_value(char *arg, t_node **stack)
{
	long	val;

	if (!is_valid_number(arg))
		return (0);
	val = ft_atol(arg);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	if (has_duplicate(*stack, (int)val))
		return (0);
	stack_add_back(stack, stack_new((int)val));
	return (1);
}

t_node	*parse_args(int argc, char **argv, t_config *cfg)
{
	t_node	*stack;
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
		if (!parse_value(argv[i], &stack))
			error_exit(&stack, NULL);
		i++;
	}
	return (stack);
}
