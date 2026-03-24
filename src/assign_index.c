/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:23:32 by etasci            #+#    #+#             */
/*   Updated: 2026/03/24 17:31:48 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_node *stack)
{
	t_node	*cur;
	t_node	*min;
	int		size;
	int		i;

	size = stack_size(stack);
	cur = stack;
	while (cur)
	{
		cur->index = -1;
		cur = cur->next;
	}
	i = 0;
	while (i < size)
	{
		cur = stack;
		min = NULL;
		while (cur)
		{
			if (cur->index == -1 && (!min || cur->value < min->value))
				min = cur;
			cur = cur->next;
		}
		if (min)
			min->index = i;
		i++;
	}
}
