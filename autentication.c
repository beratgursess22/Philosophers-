/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autentication.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 18:13:47 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:44:19 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_if_eat(t_philo *philo)
{
	int	i;
	int	count_eat;

	i = 0;
	count_eat = 0;
	if (philo->number_of_meals == -1)
		return (0);
	while (i < philo->number_of_philos)
	{
		pthread_mutex_lock(philo->meal_mutex);
		if (philo[i].meal_count >= philo[i].number_of_meals)
			count_eat++;
		pthread_mutex_unlock(philo->meal_mutex);
		i++;
	}
	if (count_eat == philo->number_of_philos)
	{
		pthread_mutex_lock(philo->dead_mutex);
		*philo->dead_flag = 1;
		pthread_mutex_unlock(philo->dead_mutex);
		return (1);
	}
	return (0);
}

int	philo_dead_control(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_mutex);
	if (current_time()
		- philo->last_meal_time > philo->time_to_die & philo->eating_flag == 0)
	{
		pthread_mutex_unlock(philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_mutex);
	return (0);
}

int	check_if_dead(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philos)
	{
		if (philo_dead_control(&philo[i]))
		{
			print_message(&philo[i], "died");
			pthread_mutex_lock(philo->dead_mutex);
			*philo->dead_flag = 1;
			pthread_mutex_unlock(philo->dead_mutex);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*autentication(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (check_if_dead(philo) == 1 || check_all_if_eat(philo) == 1)
			break ;
	}
	return (arg);
}
