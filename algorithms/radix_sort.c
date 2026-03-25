/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:13:37 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 16:38:51 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_node *a)
{
	int	max;
	int	bits;

	max = 0;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	i;
	int	j;
	int	size;
	int	max_bits;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size <= 100)
	{
		chunk_sort(a, b, ops);
		return ;
	}
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((*a)->index >> i) & 1)
				ra(a, ops);
			else
				pb(a, b, ops);
			j++;
		}
		while (*b)
			pa(a, b, ops);
		i++;
	}
}
