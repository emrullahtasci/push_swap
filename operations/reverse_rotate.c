/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:46:38 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/25 17:04:44 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate_stack(t_node **s)
{
	t_node	*prev;
	t_node	*last;

	if (!*s || !(*s)->next)
		return ;
	prev = NULL;
	last = *s;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *s;
	*s = last;
}

void	rra(t_node **a, t_ops *ops)
{
	reverse_rotate_stack(a);
	write(1, "rra\n", 4);
	ops->rra++;
	ops->total++;
}

void	rrb(t_node **b, t_ops *ops)
{
	reverse_rotate_stack(b);
	write(1, "rrb\n", 4);
	ops->rrb++;
	ops->total++;
}

void	rrr(t_node **a, t_node **b, t_ops *ops)
{
	reverse_rotate_stack(a);
	reverse_rotate_stack(b);
	write(1, "rrr\n", 4);
	ops->rrr++;
	ops->total++;
}
