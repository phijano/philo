/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_status_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:24:25 by phijano-          #+#    #+#             */
/*   Updated: 2022/10/25 11:24:29 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_exit_status(int status)
{
	int	exit;

	exit = 0;
	if (((status) & 0x7f) == 0)
		exit = 1;
	return (exit);
}

int	ft_exit_code(int status)
{
	return (((status) & 0xff00) >> 8);
}
