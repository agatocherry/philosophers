/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agcolas <agcolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:21:26 by agcolas           #+#    #+#             */
/*   Updated: 2022/03/24 15:21:53 by agcolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	free_mutexes(pthread_mutex_t **mutex, int n)
{
	while (n-- > 0)
		free(mutex[n]);
	free(mutex);
}
