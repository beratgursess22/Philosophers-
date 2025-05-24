/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:57:27 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:33:43 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid  number of arguments\n");
		return (1);
	}
	program = malloc(sizeof(t_program));
	if (ft_checker_argumans(argv))
		return (1);
	initialize_arg(program, argv);
	create_thread(program);
	destroy_all_mutex(program);
	return (0);
}
