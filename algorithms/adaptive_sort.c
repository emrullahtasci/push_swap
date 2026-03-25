/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:04:03 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 16:00:37 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	adaptive_sort(t_node **a, t_node **b, t_ops *ops)
{
	int		size;
	double	disorder;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size <= 5)
	{
		simple_sort(a, b, ops);
		return ;
	}
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
		simple_sort(a, b, ops);
	else if (disorder < 0.5)
		chunk_sort(a, b, ops);
	else
		radix_sort(a, b, ops);
}
