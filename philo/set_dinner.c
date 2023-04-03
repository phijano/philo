/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dinner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 12:56:09 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/10 13:09:03 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

int	ft_set_forks(t_philo *philo)
{
	pthread_mutex_t	*forks;
	int				count;

	forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * philo->nbr_phs);
	if (!forks)
		return (1);
	philo->forks = forks;
	count = -1;
	while (++count < philo->nbr_phs)
	{
		if (pthread_mutex_init(&forks[count], NULL))
		{
			while (--count > -1)
				pthread_mutex_destroy(&forks[count]);
			return (1);
		}
	}
	return (0);
}

int	ft_set_pencil(t_philo *philo)
{
	if (pthread_mutex_init(&philo->pencil, NULL))
		return (1);
	return (0);
}
