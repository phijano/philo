/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:21:47 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/25 11:21:51 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	ft_log_time(long long start_time)
{
	return (ft_get_time() - start_time);
}

void	ft_sleep(long long start_time, int time_sleep)
{
	long long	sleep_start;

	sleep_start = ft_log_time(start_time);
	while (ft_log_time(start_time) - sleep_start < time_sleep)
		usleep(250);
}
