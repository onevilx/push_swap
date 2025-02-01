/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:36:37 by yaboukir          #+#    #+#             */
/*   Updated: 2025/02/01 20:13:41 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check(char *argv, char *str)
{
	int	x;
	int	checker;

	x = 0;
	checker = 0;
	while (argv[x])
	{
		if (argv[x] >= '0' && argv[x] <= '9')
			checker = 1;
		x++;
	}
	if (checker == 0)
		return (write(2, "Error\n", 6), free(str), exit(1));
}

char	*ft_join_args(char **argv, char *str)
{
	int		i;
	char	*tmp;

	i = 1;
	str = ft_strdup("");
	if (str == NULL)
		return (NULL);
	while (argv[i])
	{
		ft_check(argv[i], str);
		tmp = str;
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		if (argv[i + 1])
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free(tmp);
		}
		if (str == NULL)
			break ;
		i++;
	}
	return (str);
}

char	**valid_input(char **argv)
{
	char	*str;
	char	**res;

	str = NULL;
	str = ft_join_args(argv, str);
	res = ft_split(str, ' ');
	if (!res || !*res)
		return (NULL);
	free(str);
	ft_parsing(res);
	return (res);
}
