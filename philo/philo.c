/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:19:36 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/24 12:33:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

static void	ft_end(t_philo *philo)
{
	int	count;

	if (philo->forks)
	{
		count = -1;
		while (++count < philo->nbr_phs)
			pthread_mutex_destroy(&philo->forks[count]);
		free(philo->forks);
	}
	pthread_mutex_destroy(&philo->pencil);
	if (philo->phs)
		free (philo->phs);
}

static int	ft_set_dinner(t_philo *philo)
{
	if (ft_set_pencil(philo))
		return (1);
	if (ft_set_forks(philo))
		return (1);
	if (ft_set_phils(philo))
		return (1);
	if (ft_start_phils(philo))
		return (1);
	return (0);
}

int	main(int argc, char **args)
{
	t_philo	philo;

	if (ft_check_args(argc, args, &philo))
		return (1);
	if (ft_set_dinner(&philo))
	{
		ft_end(&philo);
		return (1);
	}
	pthread_join(*philo.watcher, NULL);
	ft_end(&philo);
	return (0);
}
