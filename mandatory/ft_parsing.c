/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaboukir <yaboukir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 21:26:28 by yaboukir          #+#    #+#             */
/*   Updated: 2025/01/26 23:45:42 by yaboukir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_is_valid_digit(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (!is_digit(args[i][j]))
			{
				if (args[i][j] == '-' || args[i][j] == '+')
				{
					if (is_digit(args[i][j - 1]) || !is_digit(args[i][j + 1]))
						return (0);
				}
				else
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_isspace(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] >= 9 && args[i][j] <= 13) || args[i][j] == 32)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_parsing(char **argv)
{
	int		i;
	char	*tmp;
	int		num;

	num = 0;
	i = 0;
	if (!ft_is_valid_digit(argv))
		return (ft_putstr("Error\n"), ft_free(argv), exit(1));
	if (!ft_isspace(argv))
		return (ft_putstr("Error\n"), ft_free(argv), exit(1));
	if (check_double(argv))
		return (ft_putstr("Error\n"), ft_free(argv), exit(1));
	while (argv[i])
	{
		num = ft_atoi(argv[i]);
		tmp = ft_itoa(num);
		if (!tmp)
			return (ft_putstr("Error\n"), ft_free(argv), exit(1));
		free(argv[i]);
		argv[i] = tmp;
		i++;
	}
}
