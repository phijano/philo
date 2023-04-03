/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:49:33 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/10 10:49:14 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo.h"

static void	ft_init_philo(t_philo *philo, char **args)
{
	philo->nbr_phs = ft_atoi(args[1]);
	philo->t_die = ft_atoi(args[2]);
	philo->t_eat = ft_atoi(args[3]);
	philo->t_sleep = ft_atoi(args[4]);
	if (args[5])
		philo->nbr_meals = ft_atoi(args[5]);
	else
		philo->nbr_meals = -1;
}

static int	ft_check_error(char *str)
{
	int	error;

	error = 0;
	if (ft_strlen(str) > 2)
		error = 1;
	else if (ft_strlen(str) == 2 && ((str[0] != '+' && str[0] != '-')
			|| str[1] != '0'))
		error = 1;
	else if (ft_strlen(str) == 1 && str[0] != '0')
		error = 1;
	return (error);
}

int	ft_check_args(int argc, char **args, t_philo *philo)
{
	if (argc < 5 || argc > 6)
	{
		printf("Error\n");
		return (1);
	}
	argc = 0;
	while (args[++argc])
	{
		if (!ft_atoi(args[argc]) && ft_check_error(args[argc]))
		{
			printf("Error\n");
			return (1);
		}
	}
	ft_init_philo(philo, args);
	if (philo->nbr_phs < 1 || philo->t_die < 0 || philo->t_eat < 0
		|| philo->t_sleep < 0 || (args[5] && philo->nbr_meals < 1))
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
