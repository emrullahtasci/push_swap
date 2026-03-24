/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etasci <etasci@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 15:45:43 by etasci            #+#    #+#             */
/*   Updated: 2026/03/24 15:59:49 by etasci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int is_flag(char *s, t_config *cfg)
{
	if (ft_strncmp(s, "--simple",9) == 0)
	return(1);
}
if (ft_strncmp(s,"--medium", 9)==0)
{
	cfg->strategy = MEDİUM;
	return(1);
}
if (ft_strncmp(s, "--complex")==0)
{
	cfg->strategy = COMPLEX;
}
if (ft_strncmp(s,"--adaptive" ,11))
{
	cfg->strategy == ADAPTIVE;
	return(1);

}
if (ft_strncmp(s,"--bench",8) == 0)
{
	cfg->bench == 1;
	return (1);
}
return(0);
