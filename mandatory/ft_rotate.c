/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:26:53 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/26 23:52:49 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra_rotate(t_stack **a, int flag)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (ft_lenstack(*a) >= 2)
	{
		tmp = *a;
		*a = (*a)->next;
		bottom = last_node(*a);
		tmp->next = NULL;
		bottom->next = tmp;
		node_index(a);
		if (!flag)
			return (ft_putstr("ra\n"));
	}
	else
		return ;
}

void	ft_rb_rotate(t_stack **b, int flag)
{
	t_stack	*tmp;
	t_stack	*bottom;

	if (ft_lenstack(*b) >= 2)
	{
		tmp = *b;
		*b = (*b)->next;
		bottom = last_node(*b);
		tmp->next = NULL;
		bottom->next = tmp;
		node_index(b);
		if (!flag)
			return (ft_putstr("rb\n"));
	}
	else
		return ;
}

void	ft_rr_rotate(t_stack **a, t_stack **b)
{
	ft_ra_rotate(a, 1);
	ft_rb_rotate(b, 1);
	ft_putstr("rr\n");
}

void	ft_rotation_case(t_stack **a, t_stack **b, t_stack *tp)
{
	if (tp->x < ft_lenstack(*b) / 2 && tp->target->x < ft_lenstack(*a) / 2)
	{
		while (*a != tp->target && *b != tp)
			ft_rr_rotate(a, b);
	}
	else if (tp->x >= ft_lenstack(*b) / 2
		&& tp->target->x >= ft_lenstack(*a) / 2)
	{
		while (*a != tp->target && *b != tp)
			ft_rrr_rrotate(a, b);
	}
	if (*b != tp)
	{
		while (*b != tp)
		{
			if (tp->x < ft_lenstack(*b) / 2)
				ft_rb_rotate(b, 0);
			else
				ft_reverse_rot_b(b, 0);
		}
	}
}
