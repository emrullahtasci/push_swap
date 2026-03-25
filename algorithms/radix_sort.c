/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:13:37 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:18:20 by mkotan           ###   ########.fr       */
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

static void	radix_pass(t_node **a, t_node **b, t_ops *ops, int bit)
{
	int	size;
	int	j;

	size = stack_size(*a);
	j = 0;
	while (j < size)
	{
		if (((*a)->index >> bit) & 1)
			ra(a, ops);
		else
			pb(a, b, ops);
		j++;
	}
	while (*b)
		pa(a, b, ops);
}

void	radix_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	i;
	int	max_bits;

	if (is_sorted(*a))
		return ;
	if (stack_size(*a) <= 100)
	{
		chunk_sort(a, b, ops);
		return ;
	}
	max_bits = get_max_bits(*a);
	i = 0;
	while (i < max_bits)
		radix_pass(a, b, ops, i++);
}
