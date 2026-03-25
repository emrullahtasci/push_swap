/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:02:45 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:04:50 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	run_strategy(t_node **a, t_node **b, t_ops *ops, t_config *cfg)
{
	double	disorder;
	int		size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	disorder = compute_disorder(*a);
	if (cfg->strategy == SIMPLE)
		simple_sort(a, b, ops);
	else if (cfg->strategy == MEDIUM)
		chunk_sort(a, b, ops);
	else if (cfg->strategy == COMPLEX)
		radix_sort(a, b, ops);
	else
		adaptive_sort(a, b, ops);
	(void)disorder;
}

static char	*strategy_name(t_config *cfg)
{
	if (cfg->strategy == SIMPLE)
		return ("Simple");
	if (cfg->strategy == MEDIUM)
		return ("Medium");
	if (cfg->strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

static char	*strategy_complexity(t_node *a, t_config *cfg)
{
	double	disorder;

	if (cfg->strategy == SIMPLE)
		return ("O(n^2)");
	if (cfg->strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	if (cfg->strategy == COMPLEX)
		return ("O(n log n)");
	disorder = compute_disorder(a);
	if (disorder < 0.2)
		return ("O(n^2)");
	if (disorder < 0.5)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_ops		ops;
	t_config	cfg;
	double		disorder;
	char		*name;
	char		*complexity;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv, &cfg);
	if (!a)
		return (0);
	b = NULL;
	ops.sa = 0;
	ops.sb = 0;
	ops.ss = 0;
	ops.pa = 0;
	ops.pb = 0;
	ops.ra = 0;
	ops.rb = 0;
	ops.rr = 0;
	ops.rra = 0;
	ops.rrb = 0;
	ops.rrr = 0;
	ops.total = 0;
	assign_index(a);
	disorder = compute_disorder(a);
	name = strategy_name(&cfg);
	complexity = strategy_complexity(a, &cfg);
	run_strategy(&a, &b, &ops, &cfg);
	if (cfg.bench)
		print_benchmark(disorder, name, complexity, &ops);
	free_stack(&a);
	free_stack(&b);
}
