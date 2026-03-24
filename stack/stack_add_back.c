/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 05:16:12 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 05:20:35 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
void stack_add_back(t_node **stack, t_node *new_node)
{
	t_node *tmp;
	if (!new)
	{
		return;
	}
	if (!*stack)
	{
		*stack = new;
		return;
	}
	tmp = *stack;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}
