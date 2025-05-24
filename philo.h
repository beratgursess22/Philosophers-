/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igurses <igurses@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 13:57:31 by igurses           #+#    #+#             */
/*   Updated: 2025/05/22 15:45:52 by igurses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_PHILO_NUMBER 250

typedef struct s_philo
{
	int				id;

	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	int				eating_flag;
	int				meal_count;
	long			last_meal_time;
	long			start_time;

	int				*dead_flag;

	pthread_t		thread;
	pthread_mutex_t	*left_forks;
	pthread_mutex_t	*right_forks;
	pthread_mutex_t	*meal_mutex;
	pthread_mutex_t	*dead_mutex;
	pthread_mutex_t	*write_mutex;

}					t_philo;

typedef struct s_program
{
	int				dead_flag;
	int				number_of_philos;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	forks_mutex[MAX_PHILO_NUMBER];
	t_philo			philo[MAX_PHILO_NUMBER];

}					t_program;

int					ft_checker_number(char *argv);
int					ft_helper_for_arg_five(char **argv);
int					ft_checker_argumans(char **argv);

int					ft_atoi(const char *str);
long				current_time(void);
int					dead_loop(t_philo *philo);
void				print_message(t_philo *philo, char *message);
int					ft_sleep(size_t waiting_time);

void				initialize_arg(t_program *program, char **argv);
void				initialize_forks(t_program *program);
void				init_argumans(t_philo *philo, char **argv);
void				initialize_philo(t_program *program, char **argv);

void				thinking(t_philo *philo);
void				sleeping(t_philo *philo);
int					eating(t_philo *philo);
void				*philo_routing(void *arg);

void				*autentication(void *arg);
int					check_if_dead(t_philo *philo);
int					philo_dead_control(t_philo *philo);

void				create_thread(t_program *program);

void				destroy_all_mutex(t_program *program);

#endif