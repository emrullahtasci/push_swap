/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 21:02:45 by etasci            #+#    #+#             */
/*   Updated: 2026/03/24 21:02:48 by etasci           ###   ########.fr       */
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
