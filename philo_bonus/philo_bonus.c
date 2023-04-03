/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:51:09 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/25 11:02:15 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

static void	ft_end(t_philo *philo)
{
	sem_unlink("/turn");
	sem_unlink("/forks");
	sem_unlink("/pencil");
	if (philo->pids)
		free(philo->pids);
}

static void	ft_end_childs(t_philo *philo)
{
	int		status;
	int		count;

	count = -1;
	while (++count < philo->nbr_phs)
	{
		waitpid(-1, &status, 0);
		if (ft_exit_status(status))
		{
			if (ft_exit_code(status))
			{
				count = -1;
				while (++count < philo->nbr_phs)
					kill(philo->pids[count], 1);
				break ;
			}
		}
	}
}

static int	ft_set_dinner(t_philo *philo)
{
	ft_set_phils(philo);
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
	ft_end_childs(&philo);
	ft_end(&philo);
	return (0);
}
