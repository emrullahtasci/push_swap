/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 17:23:18 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/25 17:23:25 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*strategy_name(t_config *cfg)
{
	if (cfg->strategy == SIMPLE)
		return ("Simple");
	if (cfg->strategy == MEDIUM)
		return ("Medium");
	if (cfg->strategy == COMPLEX)
		return ("Complex");
	return ("Adaptive");
}

char	*strategy_complexity(t_node *a, t_config *cfg, double disorder)
{
	if (cfg->strategy == SIMPLE)
		return ("O(n^2)");
	if (cfg->strategy == MEDIUM)
		return ("O(n*sqrt(n))");
	if (cfg->strategy == COMPLEX)
		return ("O(n log n)");
	if (stack_size(a) <= 5 || disorder < 0.2)
		return ("O(n^2)");
	if (disorder < 0.5)
		return ("O(n*sqrt(n))");
	return ("O(n log n)");
}

void	run_strategy(t_node **a, t_node **b, t_ops *ops, t_config *cfg)
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
