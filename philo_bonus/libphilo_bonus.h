/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:52:52 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/25 11:03:31 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_BONUS_H
# define LIBPHILO_BONUS_H

# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_phil
{
	long long	start_time;
	int			nbr;
	int			last_meal_time;
	int			t_eat;
	int			t_sleep;
	int			t_die;
	int			nbr_meals;
	int			nbr_phs;
	sem_t		*pencil;
	sem_t		*turn;
	sem_t		*forks;
}	t_phil;

typedef struct s_philo
{
	int			nbr_phs;
	pid_t		*pids;
	t_phil		ph;
}	t_philo;

int			ft_check_args(int argc, char **args, t_philo *philo);
void		ft_set_phils(t_philo *philo);
int			ft_start_phils(t_philo *philo);
int			ft_set_forks(t_philo *philo);
int			ft_set_pencil(t_philo *philo);
void		*ft_phil(t_phil *phil);
void		*ft_watch(void *philo);
long long	ft_get_time(void);
long long	ft_log_time(long long start);
void		ft_sleep(long long start_time, int time_sleep);
int			ft_exit_status(int status);
int			ft_exit_code(int status);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);

#endif
