/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkotan <mkotan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 17:45:08 by etasci            #+#    #+#             */
/*   Updated: 2026/03/25 17:18:51 by mkotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	write_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
}

static void	write_int(int n)
{
	char	*str;

	str = ft_itoa(n);
	if (!str)
		return ;
	write_str(str);
	free(str);
}

static void	write_percent(double d)
{
	int		whole;
	int		frac;
	char	*s;

	whole = (int)(d * 100);
	frac = (int)(d * 10000) % 100;
	s = ft_itoa(whole);
	if (!s)
		return ;
	write_str(s);
	free(s);
	write(2, ".", 1);
	if (frac < 10)
		write(2, "0", 1);
	s = ft_itoa(frac);
	if (!s)
		return ;
	write_str(s);
	free(s);
}

static void	write_ops(t_ops *ops)
{
	write(2, "[bench] sa: ", 12);
	write_int(ops->sa);
	write(2, "  sb: ", 6);
	write_int(ops->sb);
	write(2, "  ss: ", 6);
	write_int(ops->ss);
	write(2, "  pa: ", 6);
	write_int(ops->pa);
	write(2, "  pb: ", 6);
	write_int(ops->pb);
	write(2, "\n", 1);
	write(2, "[bench] ra: ", 12);
	write_int(ops->ra);
	write(2, "  rb: ", 6);
	write_int(ops->rb);
	write(2, "  rr: ", 6);
	write_int(ops->rr);
	write(2, "  rra: ", 7);
	write_int(ops->rra);
	write(2, "  rrb: ", 7);
	write_int(ops->rrb);
	write(2, "  rrr: ", 7);
	write_int(ops->rrr);
	write(2, "\n", 1);
}

void	print_benchmark(double disorder, char *name, char *complexity,
		t_ops *ops)
{
	write(2, "[bench] disorder: ", 18);
	write_percent(disorder);
	write(2, "%\n", 2);
	write(2, "[bench] strategy: ", 18);
	write_str(name);
	write(2, " / ", 3);
	write_str(complexity);
	write(2, "\n", 1);
	write(2, "[bench] total_ops: ", 19);
	write_int(ops->total);
	write(2, "\n", 1);
	write_ops(ops);
}
