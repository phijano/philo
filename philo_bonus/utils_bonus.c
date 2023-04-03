/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:22:46 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/25 11:22:50 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libphilo_bonus.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_atoi(const char *str)
{
	unsigned long	num;
	unsigned int	count;
	int				sign;

	sign = 1;
	count = 0;
	num = 0;
	while (str[count] == ' ' || str[count] == '\t' || str[count] == '\f'
		|| str[count] == '\r' || str[count] == '\n' || str[count] == '\v')
		count++;
	if (str[count] == '+' || str[count] == '-')
		if (str[count++] == '-')
			sign = -1;
	while (str[count] >= '0' && str[count] <= '9')
		num = num * 10 + (str[count++] - '0');
	if (str[count])
		num = 0;
	if ((sign > 0 && num > 2147483647) || (sign < 0 && num > 2147483648))
		return (0);
	return ((int)(num * sign));
}
