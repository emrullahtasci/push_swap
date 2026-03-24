/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:46:41 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 18:35:34 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_stack(t_node **s)
{
	t_node	*first;
	t_node	*last;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	last = *s;
	while (last->next)
		last = last->next;
	*s = first->next;
	first->next = NULL;
	last->next = first;
}

void	ra(t_node **a, t_ops *ops)
{
	rotate_stack(a);
	write(1, "ra\n", 3);
	ops->ra++;
	ops->total++;
}

void	rb(t_node **b, t_ops *ops)
{
	rotate_stack(b);
	write(1, "rb\n", 3);
	ops->rb++;
	ops->total++;
}

void	rr(t_node **a, t_node **b, t_ops *ops)
{
	rotate_stack(a);
	rotate_stack(b);
	write(1, "rr\n", 3);
	ops->rr++;
	ops->total++;
}
