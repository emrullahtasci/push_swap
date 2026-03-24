/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:57:26 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/24 16:49:55 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

#endif

typedef enum e_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}					t_strategy;

typedef struct s_config
{
	t_strategy		strategy;
	int				bench;
}					t_config;
