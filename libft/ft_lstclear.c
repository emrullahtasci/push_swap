/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 22:45:21 by mkotan            #+#    #+#             */
/*   Updated: 2026/02/04 00:11:37 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*current;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		tmp = current->next;
		ft_lstdelone(current, del);
		current = tmp;
	}
	*lst = NULL;
}
