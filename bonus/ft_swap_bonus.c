/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:10:36 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/29 18:21:27 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_sa_swap(t_stack **a, int flag)
{
	int	tmp;

	if (ft_lenstack(*a) <= 1)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->x;
	(*a)->x = (*a)->next->x;
	(*a)->next->x = tmp;
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
	tmp = (*b)->x;
	(*b)->x = (*b)->next->x;
	(*b)->next->x = tmp;
	node_index(b);
	if (!flag)
		ft_putstr("sb\n");
}

void	ft_ss_swap(t_stack **a, t_stack **b, int flag)
{
	ft_sa_swap(a, 1);
	ft_sb_swap(b, 1);
	if (!flag)
		ft_putstr("ss\n");
}
