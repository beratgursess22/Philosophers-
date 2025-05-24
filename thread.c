/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:21:40 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:57:45 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_thread(t_program *program)
{
	pthread_t	azrael;
	int			i;

	if (pthread_create(&azrael, NULL, &autentication, program->philo) != 0)
	{
		printf("Error: Thread creation failed\n");
		return ;
	}
	i = 0;
	while (i < program->number_of_philos)
	{
		if (pthread_create(&program->philo[i].thread, NULL, &philo_routing,
				&program->philo[i]) != 0)
		{
			printf("Error: Thread creation failed\n");
			return ;
		}
		i++;
	}
	pthread_join(azrael, NULL);
	i = -1;
	while (++i < program->number_of_philos)
		pthread_join(program->philo[i].thread, NULL);
}
