/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_move2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:01:51 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/07 13:38:48 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_philo *head)
{
	t_philo	*curr;
	t_philo	*temp;
	int		i;
	int		total;

	if (!head)
		return ;
	total = head->stats->philo_amount;
	curr = head;
	i = 0;
	while (i < total)
	{
		temp = curr->next;
		pthread_mutex_destroy(&curr->fork);
		pthread_mutex_destroy(&curr->eat_mutex);
		pthread_mutex_destroy(&curr->time_mutex);
		free(curr);
		curr = temp;
		i++;
	}
}

void	remove_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->eat_mutex);
	if (philo->meals > 0)
	{
		philo->meals--;
	}
	pthread_mutex_unlock(&philo->eat_mutex);
}

void	philo_eat2(t_philo *philo)
{
	print_msg("is eating", philo);
	pthread_mutex_lock(&philo->time_mutex);
	philo->last_meal = get_current_time();
	pthread_mutex_unlock(&philo->time_mutex);
	usleep(philo->eat_t * 1000);
	pthread_mutex_unlock(&philo->next->fork);
	pthread_mutex_unlock(&philo->fork);
	remove_meal(philo);
}
