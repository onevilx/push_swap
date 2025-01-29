/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:34:55 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/29 17:31:57 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_prepare(t_stack **a, t_stack **b, int mid, int max)
{
	int	len;

	len = ft_lenstack(*a);
	while (len > 3)
	{
		if ((*a)->value != max)
		{
			ft_push_b(a, b, 0);
			if ((*b)->value >= mid)
				ft_rb_rotate(b, 0);
		}
		else
			ft_ra_rotate(a, 0);
		len = ft_lenstack(*a);
	}
}

void	ft_get_value(t_stack **a)
{
	int		len;
	t_stack	*tmp;

	tmp = *a;
	len = ft_lenstack(tmp);
	while (tmp)
	{
		tmp->price = tmp->x;
		if (tmp->x < len / 2)
			tmp->price = tmp->x;
		else
			tmp->price = len - tmp->x;
		tmp = tmp->next;
	}
}

void	ft_get_target(t_stack *a, t_stack *b)
{
	int		current_max;
	t_stack	*tmp;
	t_stack	*res;

	while (b)
	{
		res = NULL;
		current_max = INT_MAX;
		tmp = a;
		while (tmp)
		{
			if (tmp->value > b->value && tmp->value < current_max)
			{
				current_max = tmp->value;
				res = tmp;
			}
			tmp = tmp->next;
		}
		b->target = res;
		b->budget = b->price + b->target->price;
		b = b->next;
	}
}

void	ft_combination(t_stack **a, t_stack **b)
{
	ft_get_value(b);
	ft_get_value(a);
	ft_get_target(*a, *b);
	ft_best_case(a, b);
}

t_stack	*ft_find_best(t_stack **stack)
{
	int		res;
	t_stack	*empty;
	t_stack	*tmp;

	tmp = *stack;
	res = INT_MAX;
	empty = *stack;
	while (empty)
	{
		if (empty->budget < res)
		{
			res = empty->budget;
			tmp = empty;
		}
		empty = empty->next;
	}
	return (tmp);
}
