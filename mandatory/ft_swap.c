/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:10:36 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/24 23:25:03 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa_swap(t_stack **a, int flag)
{
	int	tmp;

	if (ft_lenstack(*a) <= 1)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->X;
	(*a)->X = (*a)->next->X;
	(*a)->next->X = tmp;
	node_index(a);
	if (!flag)
		ft_putstr("sa\n");
}

void	ft_sb_swap(t_stack **b, int flag)
{
	int	tmp;

	if (ft_lenstack(*b) <= 1)
		return ;
	tmp = (*b)->value;
	(*b)->value = (*b)->next->value;
	(*b)->next->value = tmp;
	tmp = (*b)->X;
	(*b)->X = (*b)->next->X;
	(*b)->next->X = tmp;
	node_index(b);
	if (!flag)
		ft_putstr("sb\n");
}

void	ft_ss_swap(t_stack **a, t_stack **b)
{
	ft_sa_swap(a, 1);
	ft_sb_swap(b, 1);
	ft_putstr("ss\n");
}
