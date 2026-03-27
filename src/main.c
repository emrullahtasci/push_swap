/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:02:45 by etasci            #+#    #+#             */
/*   Updated: 2026/03/27 17:19:22 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	init_ops(t_ops *ops)
{
	ops->sa = 0;
	ops->sb = 0;
	ops->ss = 0;
	ops->pa = 0;
	ops->pb = 0;
	ops->ra = 0;
	ops->rb = 0;
	ops->rr = 0;
	ops->rra = 0;
	ops->rrb = 0;
	ops->rrr = 0;
	ops->total = 0;
}

static void	benchmark_if_needed(t_node *a, t_config *cfg, t_ops *ops,
		double disorder)
{
	char	*name;
	char	*complexity;

	if (!cfg->bench)
		return ;
	name = strategy_name(cfg);
	complexity = strategy_complexity(a, cfg);
	print_benchmark(disorder, name, complexity, ops);
}

static void	free_split_args(char **args, int is_split)
{
	int	i;

	if (!is_split || !args)
		return ;
	i = 1;
	while (args[i])
		free(args[i++]);
	free(args);
}

static void	run_all(t_node **a, t_node **b, t_ops *ops, t_config *cfg)
{
	double	disorder;

	assign_index(*a);
	disorder = compute_disorder(*a);
	run_strategy(a, b, ops, cfg);
	benchmark_if_needed(*a, cfg, ops, disorder);
}

int	main(int ac, char **av)
{
	t_node		*a;
	t_node		*b;
	t_ops		ops;
	t_config	cfg;
	int			is_split;

	if (ac < 2)
		return (0);
	is_split = (ac == 2);
	if (is_split)
		av = handle_split(av, &ac);
	if (!av)
		return (0);
	a = parse_args(ac, av, &cfg);
	free_split_args(av, is_split);
	if (!a)
		return (0);
	b = NULL;
	init_ops(&ops);
	run_all(&a, &b, &ops, &cfg);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
