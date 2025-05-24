/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 14:34:52 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:52:00 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_argumans(t_philo *philo, char **argv)
{
	philo->number_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->number_of_meals = ft_atoi(argv[5]);
	else
		philo->number_of_meals = -1;
}

void	initialize_philo(t_program *program, char **argv)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		program->philo[i].id = i + 1;
		init_argumans(&program->philo[i], argv);
		program->philo[i].meal_count = 0;
		program->philo[i].eating_flag = 0;
		program->philo[i].start_time = current_time();
		program->philo[i].last_meal_time = current_time();
		program->philo[i].dead_flag = &program->dead_flag;
		program->philo[i].dead_mutex = &program->dead_mutex;
		program->philo[i].meal_mutex = &program->meal_mutex;
		program->philo[i].write_mutex = &program->write_mutex;
		program->philo[i].left_forks = &program->forks_mutex[i];
		if (i == 0)
			program->philo[i].right_forks = &program->forks_mutex
			[program->number_of_philos - 1];
		else
			program->philo[i].right_forks = &program->forks_mutex[i - 1];
		i++;
	}
}

void	initialize_forks(t_program *program)
{
	int	i;

	i = 0;
	while (i < program->number_of_philos)
	{
		pthread_mutex_init(&program->forks_mutex[i], NULL);
		i++;
	}
}

void	initialize_arg(t_program *program, char **argv)
{
	program->dead_flag = 0;
	program->number_of_philos = ft_atoi(argv[1]);
	pthread_mutex_init(&program->write_mutex, NULL);
	pthread_mutex_init(&program->dead_mutex, NULL);
	pthread_mutex_init(&program->meal_mutex, NULL);
	initialize_forks(program);
	initialize_philo(program, argv);
}
