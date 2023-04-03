/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:09:02 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/24 12:41:28 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

static void	ft_write(t_phil *phil, long long time, char *str)
{
	pthread_mutex_lock(phil->pencil);
	if (!phil->end)
		printf("%lldms %d %s\n", time, phil->nbr, str);
	pthread_mutex_unlock(phil->pencil);
}

static void	ft_eat(t_phil *phil)
{
	if (phil->fst_fork)
		pthread_mutex_lock(phil->fst_fork);
	else
	{
		ft_write(phil, ft_log_time(phil->start_time), "has taken a fork");
		while (!phil->end)
			usleep(1000);
	}
	ft_write(phil, ft_log_time(phil->start_time), "has taken a fork");
	pthread_mutex_lock(phil->snd_fork);
	ft_write(phil, ft_log_time(phil->start_time), "has taken a fork");
	phil->last_meal_time = ft_log_time(phil->start_time);
	ft_write(phil, phil->last_meal_time, "is eating");
	phil->nbr_meals++;
	if (!phil->end)
		ft_sleep(phil->start_time, phil->t_eat);
	pthread_mutex_unlock(phil->snd_fork);
	if (phil->fst_fork)
		pthread_mutex_unlock(phil->fst_fork);
}

void	*ft_phil(void *arg)
{
	t_phil	*phil;

	phil = arg;
	if (phil->nbr % 2 == 0)
		usleep(50);
	while (!phil->end)
	{
		ft_eat(phil);
		ft_write(phil, ft_log_time(phil->start_time), "is sleeping");
		if (!phil->end)
			ft_sleep(phil->start_time, phil->t_sleep);
		ft_write(phil, ft_log_time(phil->start_time), "is thinking");
	}
	return (NULL);
}

static int	ft_check_end(t_philo *philo, long long time)
{
	int			count;
	int			phs_end_meals;

	count = -1;
	phs_end_meals = 0;
	while (++count < philo->nbr_phs)
	{
		if (time - philo->phs[count].last_meal_time > philo->t_die)
		{
			pthread_mutex_lock(&philo->pencil);
			printf("%lldms %d died\n", time, count + 1);
			return (1);
		}
		if (philo->phs[count].nbr_meals >= philo->nbr_meals
			&& philo->nbr_meals > 0)
			phs_end_meals++;
	}
	if (phs_end_meals == philo->nbr_phs)
	{
		pthread_mutex_lock(&philo->pencil);
		return (1);
	}
	return (0);
}

void	*ft_watch(void *arg)
{
	t_philo		*philo;
	long long	time;
	int			end;
	int			count;

	philo = arg;
	end = 0;
	while (!end)
	{
		time = ft_log_time(philo->start_time);
		end = ft_check_end(philo, time);
	}
	count = -1;
	while (++count < philo->nbr_phs)
		philo->phs[count].end = 1;
	pthread_mutex_unlock(&philo->pencil);
	count = -1;
	while (++count < philo->nbr_phs)
		pthread_join(philo->phs[count].ph, NULL);
	return (NULL);
}
