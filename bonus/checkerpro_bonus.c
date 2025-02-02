/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerpro_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:36:05 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/02 17:58:47 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_program(char *line, t_stack **a, t_stack **b)
{
	if (ft_strcmp(line, "sa\n") == 0)
		ft_sa_swap(a, 1);
	else if (ft_strcmp(line, "sb\n") == 0)
		ft_sb_swap(b, 1);
	else if (ft_strcmp(line, "ss\n") == 0)
		ft_ss_swap(a, b, 1);
	else if (ft_strcmp(line, "ra\n") == 0)
		ft_ra_rotate(a, 1);
	else if (ft_strcmp(line, "rb\n") == 0)
		ft_rb_rotate(b, 1);
	else if (ft_strcmp(line, "rr\n") == 0)
		ft_rr_rotate(a, b, 1);
	else if (ft_strcmp(line, "rra\n") == 0)
		ft_reverse_rot_a(a, 1);
	else if (ft_strcmp(line, "rrb\n") == 0)
		ft_reverse_rot_b(b, 1);
	else if (ft_strcmp(line, "rrr\n") == 0)
		ft_rrr_rrotate(a, b, 1);
	else if (ft_strcmp(line, "pa\n") == 0)
		ft_push_a(a, b, 1);
	else if (ft_strcmp(line, "pb\n") == 0)
		ft_push_b(a, b, 1);
	else
		return (write(2, "Error\n", 6), exit(1));
}

void	ft_check_gnl(t_stack **a, t_stack **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!line)
			break ;
		ft_check_program(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	free(line);
}

void	ft_answer(t_stack **a, t_stack **b)
{
	if ((!b || !*b) && ft_sorted(a) == 0)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	ft_lstclear(a);
	if (*b)
		ft_lstclear(b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	if (argc > 1)
	{
		str = valid_input(argv);
		if (!str || !*str)
			return (0);
		ft_fill(&a, str);
		ft_free(str);
		ft_check_gnl(&a, &b);
		ft_answer(&a, &b);
	}
	else
		return (0);
}
