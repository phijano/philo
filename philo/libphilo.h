/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 10:27:41 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/11 12:22:29 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_phil
{
	long long		start_time;
	int				nbr;
	pthread_mutex_t	*pencil;
	int				last_meal_time;
	int				t_eat;
	int				t_sleep;
	pthread_mutex_t	*fst_fork;
	pthread_mutex_t	*snd_fork;
	int				nbr_meals;
	int				end;
	pthread_t		ph;
}	t_phil;

typedef struct s_philo
{
	int				nbr_phs;
	int				t_die;
	int				nbr_meals;
	long long		start_time;
	int				t_eat;
	int				t_sleep;
	t_phil			*phs;
	pthread_t		*watcher;
	pthread_mutex_t	*forks;
	pthread_mutex_t	pencil;
}	t_philo;

int			ft_check_args(int argc, char **args, t_philo *philo);
int			ft_set_phils(t_philo *philo);
int			ft_start_phils(t_philo *philo);
int			ft_set_forks(t_philo *philo);
int			ft_set_pencil(t_philo *philo);
void		*ft_phil(void *phil);
void		*ft_watch(void *philo);
long long	ft_get_time(void);
long long	ft_log_time(long long start);
void		ft_sleep(long long start_time, int time_sleep);
int			ft_atoi(const char *str);
int			ft_strlen(char *str);

#endif
