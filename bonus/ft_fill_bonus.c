/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:25:54 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/29 17:28:02 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	stack_sorted(t_stack **a)
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

void	first_node(t_stack **a, char **res, int data)
{
	*a = ft_lstnew(data);
	if (!(*a))
		return (ft_free(res), exit(1));
}

void	ft_free(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

int	check_double(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_fill(t_stack **a, char **res)
{
	long	r;
	int		size;
	int		i;
	t_stack	*tmp;

	i = 0;
	size = ft_strlen2(res);
	while (i < size)
	{
		if (ft_atoi(res[i]) > INT_MAX || ft_atoi(res[i]) < INT_MIN)
			return (ft_putstr("Error\n"), ft_free(res), exit(1));
		r = (int)ft_atoi(res[i]);
		if (i == 0)
			first_node(a, res, r);
		else
		{
			tmp = ft_lstnew(r);
			if (!tmp)
				return (free(a), ft_free(res), exit(1));
			ft_lstadd_back(a, tmp);
		}
		i++;
	}
}
