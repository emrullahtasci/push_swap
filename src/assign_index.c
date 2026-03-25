/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:23:32 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:21:56 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reset_indexes(t_node *stack)
{
	t_node	*cur;

	cur = stack;
	while (cur)
	{
		cur->index = -1;
		cur = cur->next;
	}
}

static t_node	*find_min_unindexed(t_node *stack)
{
	t_node	*cur;
	t_node	*min;

	cur = stack;
	min = NULL;
	while (cur)
	{
		if (cur->index == -1 && (!min || cur->value < min->value))
			min = cur;
		cur = cur->next;
	}
	return (min);
}

void	assign_index(t_node *stack)
{
	int		size;
	int		i;
	t_node	*min;

	size = stack_size(stack);
	reset_indexes(stack);
	i = 0;
	while (i < size)
	{
		min = find_min_unindexed(stack);
		if (min)
			min->index = i;
		i++;
	}
}
