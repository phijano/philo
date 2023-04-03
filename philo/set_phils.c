/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_phils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:38:01 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/24 12:45:33 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

static void	ft_set_phil_forks(t_philo *philo, t_phil *phil, int nbr)
{
	if (nbr % 2 == 1)
	{
		phil->fst_fork = &philo->forks[nbr];
		if (nbr != philo->nbr_phs - 1)
			phil->snd_fork = &philo->forks[nbr + 1];
		else
			phil->snd_fork = &philo->forks[0];
	}
	else
	{
		if (philo->nbr_phs == 1)
			phil->fst_fork = NULL;
		else if (nbr != philo->nbr_phs - 1)
			phil->fst_fork = &philo->forks[nbr + 1];
		else
			phil->fst_fork = &philo->forks[0];
		phil->snd_fork = &philo->forks[nbr];
	}
}

int	ft_set_phils(t_philo *philo)
{
	t_phil	*phils;
	int		count;

	phils = (t_phil *)malloc(sizeof(t_phil) * philo->nbr_phs);
	if (!phils)
	{
		printf("Error\n");
		return (1);
	}
	philo->phs = phils;
	count = -1;
	while (++count < philo->nbr_phs)
	{
		phils[count].nbr = count + 1;
		phils[count].t_eat = philo->t_eat;
		phils[count].t_sleep = philo->t_sleep;
		phils[count].last_meal_time = 0;
		phils[count].nbr_meals = 0;
		phils[count].end = 0;
		phils[count].pencil = &philo->pencil;
		ft_set_phil_forks(philo, &phils[count], count);
	}
	return (0);
}

int	ft_start_phils(t_philo *philo)
{
	pthread_t	watcher;
	int			count;

	philo->watcher = &watcher;
	count = -1;
	philo->start_time = ft_get_time();
	while (++count < philo->nbr_phs)
		philo->phs[count].start_time = philo->start_time;
	count = -1;
	while (++count < philo->nbr_phs)
		if (pthread_create(&philo->phs[count].ph, NULL,
				ft_phil, &philo->phs[count]))
			return (1);
	if (pthread_create(&watcher, NULL, ft_watch, philo))
		return (1);
	return (0);
}
