/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:24:13 by agcolas           #+#    #+#             */
/*   Updated: 2022/03/24 15:44:23 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_err(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		write(2, &str[len], 1);
		len++;
	}
}

static int	check_nb_args(int ac)
{
	if (ac < 5 || ac > 6)
	{
		print_err("Error: five or six arguments is required.\n");
		return (0);
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (check_nb_args(ac) == 0)
		return (0);
	while (i < ac)
	{
		if (!av[i])
		{
			print_err("Error: one arguments is empty.\n");
			return (0);
		}
		if (!av[i][0])
		{
			print_err("Error: one arguments is empty.\n");
			return (0);
		}
		if (!ft_is_only_digits(av[i]))
		{
			print_err("Error: one argument is not a number.\n");
			return (0);
		}
		i++;
	}
	return (1);
}
