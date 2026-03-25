/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:02:45 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:22:30 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	benchmark_if_needed(t_node *a, t_config *cfg, t_ops *ops)
{
	double	disorder;
	char	*name;
	char	*complexity;

	if (!cfg->bench)
		return ;
	disorder = compute_disorder(a);
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
	{
		free(args[i]);
		i++;
	}
	free(args);
}

static char	**handle_split(char **argv, int *new_argc)
{
	char	**split;
	char	**new_argv;
	int		i;

	split = ft_split(argv[1], ' ');
	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
		i++;
	*new_argc = i + 1;
	new_argv = malloc(sizeof(char *) * (*new_argc + 1));
	if (!new_argv)
		return (NULL);
	new_argv[0] = argv[0];
	i = 0;
	while (split[i])
	{
		new_argv[i + 1] = split[i];
		i++;
	}
	new_argv[*new_argc] = NULL;
	free(split);
	return (new_argv);
}

int	main(int argc, char **argv)
{
	t_node		*a;
	t_node		*b;
	t_ops		ops;
	t_config	cfg;
	int			is_split;

	if (argc < 2)
		return (0);
	is_split = (argc == 2);
	if (is_split)
		argv = handle_split(argv, &argc);
	if (!argv)
		return (0);
	a = parse_args(argc, argv, &cfg);
	free_split_args(argv, is_split);
	if (!a)
		return (0);
	b = NULL;
	init_ops(&ops);
	assign_index(a);
	run_strategy(&a, &b, &ops, &cfg);
	benchmark_if_needed(a, &cfg, &ops);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
