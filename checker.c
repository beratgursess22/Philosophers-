/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:00:05 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:46:33 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_checker_number(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] < '0' || argv[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	ft_helper_for_arg_five(char **argv)
{
	if (argv[5] && (ft_atoi(argv[5]) < 0 || ft_checker_number(argv[5])))
	{
		printf("Invalid number of philo must eat\n");
		return (1);
	}
	return (0);
}

int	ft_checker_argumans(char **argv)
{
	if ((ft_atoi(argv[1]) > MAX_PHILO_NUMBER) || ft_atoi(argv[1]) < 0
		|| ft_checker_number(argv[1]))
	{
		printf("Invalid number of philo\n");
		return (1);
	}
	if (ft_atoi(argv[2]) < 0 || ft_checker_number(argv[2]))
	{
		printf("Invalid number of die\n");
		return (1);
	}
	if (ft_atoi(argv[3]) < 0 || ft_checker_number(argv[3]))
	{
		printf("Invalid number of eat\n");
		return (1);
	}
	if (ft_atoi(argv[4]) < 0 || ft_checker_number(argv[4]))
	{
		printf("Invalid number of sleep\n");
		return (1);
	}
	if (ft_helper_for_arg_five(argv))
		return (1);
	return (0);
}
