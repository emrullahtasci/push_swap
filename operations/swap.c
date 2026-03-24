/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:46:44 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 18:23:31 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_stack(t_node **s)
{
	t_node	*first;
	t_node	*second;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*s = second;
}

void	sa(t_node **a, t_ops *ops)
{
	swap_stack(a);
	write(1, "sa\n", 3);
	ops->sa++;
	ops->total++;
}

void	sb(t_node **b, t_ops *ops)
{
	swap_stack(b);
	write(1, "sb\n", 3);
	ops->sb++;
	ops->total++;
}

void	ss(t_node **a, t_node **b, t_ops *ops)
{
	swap_stack(a);
	swap_stack(b);
	write(1, "ss\n", 3);
	ops->ss++;
	ops->total++;
}
