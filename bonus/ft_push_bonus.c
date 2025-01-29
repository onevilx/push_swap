/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:43:29 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/29 19:37:42 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push_a(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = tmp;
	node_index(b);
	if (!flag)
		ft_putstr("pa\n");
}

void	ft_push_b(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = tmp;
	node_index(a);
	if (!flag)
		ft_putstr("pb\n");
}
