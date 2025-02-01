/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:06:11 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/01 20:17:28 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				x;
	int				price;
	int				budget;
	int				value;
	struct s_stack	*next;
	struct s_stack	*target;
}	t_stack;

int		is_digit(int x);
int		ft_strlen2(char **str);
int		ft_atoi(const char *str);
int		ft_sorted(t_stack	**a);
int		ft_lenstack(t_stack *stack);
int		max_value(t_stack *a);
int		min_value(t_stack *a);
int		ft_isspace(char **args);
int		ft_sorted(t_stack	**a);
int		stack_sorted(t_stack **a);
int		check_double(char **argv);
int		ft_get_median(t_stack **a);
int		ft_is_valid_digit(char **args);
char	*ft_itoa(int n);
char	**valid_input(char **argv);
char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);
char	*ft_join_args(char **argv, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putstr(char *str);
void	ft_free(char **argv);
void	ft_three_case(t_stack **a);
void	ft_push_a(t_stack **a, t_stack **b);
void	ft_push_b(t_stack **a, t_stack **b);
void	ft_sb_swap(t_stack **b, int flag);
void	ft_sa_swap(t_stack **a, int flag);
void	ft_ss_swap(t_stack **a, t_stack **b);
void	ft_ra_rotate(t_stack **a, int flag);
void	ft_rb_rotate(t_stack **b, int flag);
void	ft_rr_rotate(t_stack **a, t_stack **b);
void	ft_reverse_rot_a(t_stack **a, int flag);
void	ft_reverse_rot_b(t_stack **b, int flag);
void	ft_rrr_rrotate(t_stack **a, t_stack **b);
void	ft_parsing(char **argv);
void	ft_fill(t_stack **a, char **res);
void	first_node(t_stack **a, char **res, int data);
void	ft_rotation_case(t_stack **a, t_stack **b, t_stack *tp);
void	ft_prepare(t_stack **a, t_stack **b, int mid, int max);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_middle_sort(t_stack **a, t_stack **b);
void	ft_large_sort(t_stack **a, t_stack **b);
void	ft_best_case(t_stack **a, t_stack **b);
void	ft_sorting(t_stack **a, t_stack **b);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_combination(t_stack **a, t_stack **b);
void	ft_get_target(t_stack *a, t_stack *b);
void	ft_sorting_arr(int *res, int len);
void	ft_check(char *argv, char *str);
void	ft_lstclear(t_stack **stack);
void	*pre_last_node(t_stack *a);
void	ft_get_value(t_stack **a);
void	*last_node(t_stack *a);
void	node_index(t_stack **a);
t_stack	*ft_lstnew(int value);
t_stack	*min_node(t_stack *a);
t_stack	*get_big_node(t_stack *node);
t_stack	*ft_find_best(t_stack **stack);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
#endif
