/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:40:11 by agcolas           #+#    #+#             */
/*   Updated: 2022/03/24 15:11:09 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	waiting(long value, t_philosopher *philo)
{
	long int	start_time;
	long int	time;
	long int	n;

	start_time = get_time();
	time = get_time();
	n = 2;
	while (time - start_time - value < 0)
	{
		pthread_mutex_lock(philo->write_lock);
		if (*(philo->one_dead))
		{
			pthread_mutex_unlock(philo->write_lock);
			break ;
		}
		pthread_mutex_unlock(philo->write_lock);
		usleep(value / n);
		time = get_time();
		n++;
	}
}
