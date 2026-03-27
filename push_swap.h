/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 22:57:26 by mkotan            #+#    #+#             */
/*   Updated: 2026/03/27 17:21:52 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct s_ops
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
	int				total;
}					t_ops;

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

/* parsing */
t_node				*parse_args(int argc, char **argv, t_config *cfg);
void				assign_index(t_node *stack);
void				error_exit(t_node **a, t_node **b);
char				**handle_split(char **argv, int *ac);

/* parse helpers */
int					is_flag(char *s, t_config *cfg);
int					is_valid_number(char *s);
long				ft_atol(char *s);
int					has_duplicate(t_node *stack, int value);

/* stack */
t_node				*stack_new(int value);
void				stack_add_back(t_node **stack, t_node *node);
int					stack_size(t_node *stack);
void				free_stack(t_node **stack);
int					is_sorted(t_node *stack);

/* operations */
void				sa(t_node **a, t_ops *ops);
void				sb(t_node **b, t_ops *ops);
void				ss(t_node **a, t_node **b, t_ops *ops);
void				pa(t_node **a, t_node **b, t_ops *ops);
void				pb(t_node **a, t_node **b, t_ops *ops);
void				ra(t_node **a, t_ops *ops);
void				rb(t_node **b, t_ops *ops);
void				rr(t_node **a, t_node **b, t_ops *ops);
void				rra(t_node **a, t_ops *ops);
void				rrb(t_node **b, t_ops *ops);
void				rrr(t_node **a, t_node **b, t_ops *ops);

/* algorithms */
void				simple_sort(t_node **a, t_node **b, t_ops *ops);
void				chunk_sort(t_node **a, t_node **b, t_ops *ops);
void				radix_sort(t_node **a, t_node **b, t_ops *ops);
void				adaptive_sort(t_node **a, t_node **b, t_ops *ops);
void				run_strategy(t_node **a, t_node **b, t_ops *ops,
						t_config *cfg);
char				*strategy_name(t_config *cfg);
char				*strategy_complexity(t_node *a, t_config *cfg);

/* helpers */
t_node				*find_min(t_node *stack);
t_node				*find_max(t_node *stack);
int					node_position(t_node *stack, t_node *node);

/* metrics */
double				compute_disorder(t_node *a);

/* benchmark */
void				print_benchmark(double disorder, char *name,
						char *complexity, t_ops *ops);

#endif
