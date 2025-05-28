/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibrahimberatgurses <ibrahimberatgurses@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 17:36:48 by igurses           #+#    #+#             */
/*   Updated: 2025/05/28 23:01:29 by ibrahimbera      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	thinking(t_philo *philo)
{
	print_message(philo, "is thinking");
}

void	sleeping(t_philo *philo)
{
	print_message(philo, "is sleeping");
	ft_sleep(philo->time_to_sleep);
}

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_forks);
	print_message(philo, "has taken a left fork");
	if (philo->number_of_philos == 1)
	{
		ft_sleep(philo->time_to_die);
		pthread_mutex_unlock(philo->left_forks);
		return (1);
	}
	pthread_mutex_lock(philo->right_forks);
	print_message(philo, "has taken a right fork");
	philo->eating_flag = 1;
	print_message(philo, "is eating");
	pthread_mutex_lock(philo->meal_mutex);
	philo->meal_count++;
	philo->last_meal_time = current_time();
	pthread_mutex_unlock(philo->meal_mutex);
	ft_sleep(philo->time_to_eat);
	philo->eating_flag = 0;
	pthread_mutex_unlock(philo->left_forks);
	pthread_mutex_unlock(philo->right_forks);
	return (0);
}

void	*philo_routing(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(1);
	while (!dead_loop(philo))
	{
		if (eating(philo) == 1)
			return (arg);
		sleeping(philo);
		thinking(philo);
	}
	return (arg);
}
