/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helperfs2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:52:44 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/02 14:08:24 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	node_index(t_stack **a)
{
	int		j;
	t_stack	*tmp;

	j = 0;
	tmp = *a;
	while (tmp)
	{
		tmp->x = j;
		j++;
		tmp = tmp->next;
	}
}

void	ft_sorting_arr(int *res, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len -1)
	{
		j = i + 1;
		while (j < len)
		{
			if (res[i] < res[j])
			{
				tmp = res[i];
				res[i] = res[j];
				res[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_get_median(t_stack **a)
{
	int		len;
	int		mid;
	int		i;
	t_stack	*tmp;
	int		*res;

	i = 0;
	len = ft_lenstack(*a);
	tmp = *a;
	res = malloc(sizeof(int) * len);
	if (!res)
		return (exit(1), 0);
	while (tmp)
	{
		res[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	ft_sorting_arr(res, len);
	mid = res[len / 2];
	free(res);
	return (mid);
}

int	ft_strchr(const char *str, char c)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
