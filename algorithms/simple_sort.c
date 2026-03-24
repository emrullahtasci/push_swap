/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 18:15:04 by etasci            #+#    #+#             */
/*   Updated: 2026/03/24 18:19:18 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:46:21 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 03:48:17 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_min(t_node *stack)
{
	t_node	*min;

	min = stack;
	stack = stack->next;
	while (stack)
	{
		if (stack->value < min->value)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

static void	sort_three(t_node **a, t_ops *ops)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if (first > second && second < third && first < third)
		sa(a, ops);
	else if (first > second && second > third)
	{
		sa(a, ops);
		rra(a, ops);
	}
	else if (first > second && second < third && first > third)
		ra(a, ops);
	else if (first < second && second > third && first < third)
	{
		sa(a, ops);
		ra(a, ops);
	}
	else if (first < second && second > third && first > third)
		rra(a, ops);
}

static void	sort_five(t_node **a, t_node **b, t_ops *ops)
{
	t_node	*min_node;
	int		pos;
	int		size;

	while (stack_size(*a) > 3)
	{
		min_node = find_min(*a);
		size = stack_size(*a);
		pos = node_position(*a, min_node);
		if (pos <= size / 2)
			while ((*a)->value != min_node->value)
				ra(a, ops);
		else
			while ((*a)->value != min_node->value)
				rra(a, ops);
		pb(a, b, ops);
	}
	sort_three(a, ops);
	while (*b)
		pa(a, b, ops);
}

void	simple_sort(t_node **a, t_node **b, t_ops *ops)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		sa(a, ops);
	else if (size == 3)
		sort_three(a, ops);
	else
		sort_five(a, b, ops);
}
