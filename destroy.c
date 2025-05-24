/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 15:13:07 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:48:39 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_all_mutex(t_program *program)
{
	int	i;

	i = -1;
	while (++i < program->number_of_philos)
		pthread_mutex_destroy(&program->forks_mutex[i]);
	pthread_mutex_destroy(&program->dead_mutex);
	pthread_mutex_destroy(&program->write_mutex);
	pthread_mutex_destroy(&program->meal_mutex);
	free(program);
}
