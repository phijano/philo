/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_phils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:25:40 by phijano-          #+#    #+#             */
/*   Updated: 2022/11/02 15:08:14 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

void	ft_set_phils(t_philo *philo)
{
	sem_unlink("/turn");
	sem_unlink("/forks");
	sem_unlink("/pencil");
	philo->ph.pencil = sem_open("/pencil", O_CREAT, 0644, 1);
	philo->ph.turn = sem_open("/turn", O_CREAT, 0644, 1);
	philo->ph.forks = sem_open("/forks", O_CREAT, 0644, philo->nbr_phs);
	philo->ph.nbr = 0;
	philo->ph.last_meal_time = 0;
	philo->ph.nbr_phs = philo->nbr_phs;
	philo->ph.start_time = ft_get_time();
}

int	ft_start_phils(t_philo *philo)
{
	int	count;

	philo->pids = malloc(sizeof(pid_t) * philo->nbr_phs);
	if (!philo->pids)
	{
		printf("Error\n");
		return (1);
	}
	count = -1;
	while (++count < philo->nbr_phs)
	{
		philo->ph.nbr++;
		philo->pids[count] = fork();
		if (philo->pids[count] == -1)
		{
			printf("Error\n");
			return (1);
		}
		else if (philo->pids[count] == 0)
			ft_phil(&philo->ph);
	}
	return (0);
}
