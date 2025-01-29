/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:05:34 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/26 23:51:26 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_middle_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	len;
	int	min_index;

	len = ft_lenstack(*a);
	node_index(a);
	i = len;
	while (i-- > 3)
	{
		min_index = min_value(*a);
		while (min_index != 0)
		{
			if (min_index <= len / 2)
				ft_ra_rotate(a, 0);
			else
				ft_reverse_rot_a(a, 0);
			min_index = min_value(*a);
		}
		ft_push_b(a, b);
	}
	if (ft_sorted(a) > 0)
		ft_three_case(a);
	ft_push_a(a, b);
	ft_push_a(a, b);
}

void	ft_large_sort(t_stack **a, t_stack **b)
{
	int		mid;
	int		max;
	t_stack	*least;

	mid = ft_get_median(a);
	max = max_value(*a);
	ft_prepare(a, b, mid, max);
	ft_three_case(a);
	node_index(a);
	node_index(b);
	while (ft_lenstack(*b) != 0)
		ft_combination(a, b);
	least = min_node(*a);
	while (least->x != 0)
	{
		if (least->x < ft_lenstack(*a) / 2)
			ft_ra_rotate(a, 0);
		else
			ft_reverse_rot_a(a, 0);
	}
}

void	ft_best_case(t_stack **a, t_stack **b)
{
	t_stack	*tp;

	tp = ft_find_best(b);
	ft_rotation_case(a, b, tp);
	if (*a != tp->target)
	{
		while (*a != tp->target)
		{
			if (tp->target->x < ft_lenstack(*a) / 2)
				ft_ra_rotate(a, 0);
			else
				ft_reverse_rot_a(a, 0);
		}
	}
	ft_push_a(a, b);
}

void	ft_sorting(t_stack **a, t_stack **b)
{
	int	num;

	num = ft_lenstack(*a);
	if (num == 2)
		ft_sa_swap(a, 0);
	if (num == 3)
		ft_three_case(a);
	if (num == 5 || num == 4)
		ft_middle_sort(a, b);
	if (num >= 6)
		ft_large_sort(a, b);
}
