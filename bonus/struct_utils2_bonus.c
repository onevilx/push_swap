/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 23:34:50 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/29 17:29:53 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
	{
		a = a->next;
	}
	return (a);
}

void	*pre_last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next && a->next->next)
		a = a->next;
	return (a);
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!stack)
		return ;
	node = *stack;
	while (node != NULL)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	*stack = NULL;
}

int	ft_sorted(t_stack	**a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	ft_strlen2(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
