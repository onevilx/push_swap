/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:34:58 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/27 21:20:44 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_big_node(t_stack *node)
{
	int		max_val;
	t_stack	*big_node;

	if (!node)
		return (NULL);
	max_val = INT_MIN;
	while (node)
	{
		if (node->value > max_val)
		{
			max_val = node->value;
			big_node = node;
		}
		node = node->next;
	}
	return (big_node);
}

t_stack	*min_node(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		if (a->value < tmp->value)
			tmp = a;
		a = a->next;
	}
	return (tmp);
}

int	max_value(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	min_value(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (a)
	{
		if (a->value < tmp->value)
			tmp = a;
		a = a->next;
	}
	return (tmp->x);
}

void	ft_three_case(t_stack **a)
{
	t_stack	*big_node;

	big_node = get_big_node(*a);
	if (*a == big_node)
		ft_ra_rotate(a, 0);
	else if ((*a)->next == big_node)
		ft_reverse_rot_a(a, 0);
	if ((*a)->value > (*a)->next->value)
		ft_sa_swap(a, 0);
}
