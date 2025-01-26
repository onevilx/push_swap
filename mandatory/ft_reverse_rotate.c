/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:20:21 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/25 20:06:31 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rot_a(t_stack **a, int flag)
{
	t_stack	*pre_last;
	t_stack	*tmp;

	if (ft_lenstack(*a) >= 2)
	{
		tmp = last_node((*a));
		pre_last = pre_last_node((*a));
		pre_last->next = NULL;
		tmp->next = *a;
		*a = tmp;
		node_index(a);
		if (!flag)
			return (ft_putstr("rra\n"));
	}
	else
		return;
}

void	ft_reverse_rot_b(t_stack **b, int flag)
{
	t_stack	*pre_last;
	t_stack	*tmp;

	if (ft_lenstack(*b) >= 2)
	{
		tmp = last_node((*b));
		pre_last = pre_last_node((*b));
		pre_last->next = NULL;
		tmp->next = *b;
		*b = tmp;
		node_index(b);
		if (!flag)
			return (ft_putstr("rrb\n"));
	}
	else
		return ;
}

void	ft_rrr_rrotate(t_stack **a, t_stack **b)
{
	ft_reverse_rot_a(a, 1);
	ft_reverse_rot_b(b, 1);
	ft_putstr("rrr\n");
}
