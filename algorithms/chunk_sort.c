/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:07:24 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:18:04 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

static void	push_chunk(t_node **a, t_node **b, t_ops *ops, int range[2])
{
	t_node	*cur;
	int		pos;

	cur = *a;
	while (cur && (cur->index < range[0] || cur->index > range[1]))
		cur = cur->next;
	while (cur)
	{
		pos = node_position(*a, cur);
		if (pos <= stack_size(*a) / 2)
			while ((*a)->index < range[0] || (*a)->index > range[1])
				ra(a, ops);
		else
			while ((*a)->index < range[0] || (*a)->index > range[1])
				rra(a, ops);
		pb(a, b, ops);
		cur = *a;
		while (cur && (cur->index < range[0] || cur->index > range[1]))
			cur = cur->next;
	}
}

void	chunk_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	size;
	int	chunks;
	int	range[2];
	int	i;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	if (size <= 5)
		return (simple_sort(a, b, ops));
	chunks = (size <= 10) * 2 + (size > 10 && size <= 50) * 5 + (size > 50
			&& size <= 200) * 8 + (size > 200) * 11;
	range[0] = 0;
	i = 0;
	while (i < chunks)
	{
		range[1] = (i == chunks - 1) * (size - 1) + (i != chunks - 1)
			* (range[0] + (size / chunks) - 1);
		push_chunk(a, b, ops, range);
		range[0] = range[1] + 1;
		i++;
	}
	pull_all(a, b, ops);
}
