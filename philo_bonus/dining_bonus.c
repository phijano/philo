/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:21:02 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/25 11:21:07 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

static void	ft_write(t_phil *phil, long long time, char *str)
{
	sem_wait(phil->pencil);
	printf("%lldms %d %s\n", time, phil->nbr, str);
	sem_post(phil->pencil);
}

static void	ft_eat(t_phil *phil)
{
	sem_wait(phil->turn);
	sem_wait(phil->forks);
	ft_write(phil, ft_log_time(phil->start_time), "has taken a fork");
	if (phil->nbr_phs != 1)
		sem_wait(phil->forks);
	else
		while (1)
			usleep(1000);
	ft_write(phil, ft_log_time(phil->start_time), "has taken a fork");
	sem_post(phil->turn);
	phil->last_meal_time = ft_log_time(phil->start_time);
	ft_write(phil, phil->last_meal_time, "is eating");
	if (phil->nbr_meals > 0)
		phil->nbr_meals--;
	ft_sleep(phil->start_time, phil->t_eat);
	sem_post(phil->forks);
	sem_post(phil->forks);
}

void	*ft_phil(t_phil *phil)
{
	pthread_t	watcher;

	if (pthread_create(&watcher, NULL, ft_watch, phil))
		exit(1);
	while (1)
	{
		ft_eat(phil);
		ft_write(phil, ft_log_time(phil->start_time), "is sleeping");
		ft_sleep(phil->start_time, phil->t_sleep);
		ft_write(phil, ft_log_time(phil->start_time), "is thinking");
	}
}

void	*ft_watch(void *arg)
{
	t_phil		*phil;
	long long	time;

	phil = arg;
	while (1)
	{
		time = ft_log_time(phil->start_time);
		if (time - phil->last_meal_time > phil->t_die)
		{
			sem_wait(phil->pencil);
			printf("%lldms %d died\n", ft_log_time(phil->start_time),
				phil->nbr);
			exit(1);
		}
		else if (phil->nbr_meals == 0)
		{
			sem_post(phil->forks);
			sem_post(phil->forks);
			exit(0);
		}
	}
	return (NULL);
}
