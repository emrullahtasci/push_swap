/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 03:46:34 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 18:37:51 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_stack(t_node **src, t_node **dst)
{
	t_node	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dst;
	*dst = tmp;
}

void	pa(t_node **a, t_node **b, t_ops *ops)
{
	push_stack(b, a);
	write(1, "pa\n", 3);
	ops->pa++;
	ops->total++;
}

void	pb(t_node **a, t_node **b, t_ops *ops)
{
	push_stack(a, b);
	write(1, "pb\n", 3);
	ops->pb++;
	ops->total++;
}
