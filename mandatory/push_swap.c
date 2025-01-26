/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:27:50 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/25 19:42:59 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		str = valid_input(argv);
		ft_fill(&a, str);
		ft_free(str);
		if (a != NULL && a->next == NULL)
			return (ft_lstclear(&a), 0);
		if (!ft_sorted(&a))
			return (ft_lstclear(&a), 0);
		ft_sorting(&a, &b);
		ft_lstclear(&a);
	}
	else
		return (1);
}
