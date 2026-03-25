/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:07:24 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 16:37:20 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_max(t_node *stack)
{
	t_node	*max;

	max = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->index > max->index)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

int	node_position(t_node *stack, t_node *node)
{
	int	pos;

	pos = 0;
	while (stack && stack != node)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

static void	push_chunk(t_node **a, t_node **b, t_ops *ops, int min_idx,
		int max_idx)
{
	t_node	*cur;
	int		pos;
	int		half;

	while (1)
	{
		cur = *a;
		pos = 0;
		while (cur)
		{
			if (cur->index >= min_idx && cur->index <= max_idx)
				break ;
			cur = cur->next;
			pos++;
		}
		if (!cur)
			break ;
		half = stack_size(*a) / 2;
		if (pos <= half)
			while ((*a)->index < min_idx || (*a)->index > max_idx)
				ra(a, ops);
		else
			while ((*a)->index < min_idx || (*a)->index > max_idx)
				rra(a, ops);
		pb(a, b, ops);
	}
}

static void	pull_all(t_node **a, t_node **b, t_ops *ops)
{
	t_node	*max_node;
	int		pos;
	int		size;

	while (*b)
	{
		max_node = find_max(*b);
		size = stack_size(*b);
		pos = node_position(*b, max_node);
		if (pos <= size / 2)
			while ((*b)->index != max_node->index)
				rb(b, ops);
		else
			while ((*b)->index != max_node->index)
				rrb(b, ops);
		pa(a, b, ops);
	}
}

static int	get_chunk_count(int size)
{
	if (size <= 10)
		return (2);
	if (size <= 50)
		return (5);
	if (size <= 200)
		return (8);
	return (11);
}

void	chunk_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	size;
	int	chunk_count;
	int	chunk_size;
	int	min_idx;
	int	max_idx;
	int	i;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 5)
	{
		simple_sort(a, b, ops);
		return ;
	}
	chunk_count = get_chunk_count(size);
	chunk_size = size / chunk_count;
	min_idx = 0;
	i = 0;
	while (i < chunk_count)
	{
		if (i == chunk_count - 1)
			max_idx = size - 1;
		else
			max_idx = min_idx + chunk_size - 1;
		push_chunk(a, b, ops, min_idx, max_idx);
		min_idx = max_idx + 1;
		i++;
	}
	pull_all(a, b, ops);
}
