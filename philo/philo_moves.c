/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:19:45 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/07 13:38:39 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->stats->state_mutex);
	if (philo->stats->is_over)
	{
		pthread_mutex_unlock(&philo->stats->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->stats->state_mutex);
	print_msg("is thinking", philo);
}

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(100);
	return (0);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->stats->state_mutex);
	if (philo->stats->is_over)
	{
		pthread_mutex_unlock(&philo->stats->state_mutex);
		return ;
	}
	pthread_mutex_unlock(&philo->stats->state_mutex);
	if (!philo_take_fork(philo, 1))
		return ;
	if (!philo_take_fork(philo, 0))
	{
		pthread_mutex_unlock(&philo->fork);
		return ;
	}
	pthread_mutex_lock(&philo->stats->state_mutex);
	if (philo->stats->is_over)
	{
		pthread_mutex_unlock(&philo->stats->state_mutex);
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(&philo->next->fork);
		return ;
	}
	pthread_mutex_unlock(&philo->stats->state_mutex);
	philo_eat2(philo);
}

void	*philo_sleep(void *philo)
{
	t_philo	*philo_c;

	philo_c = philo;
	pthread_mutex_lock(&philo_c->stats->state_mutex);
	if (philo_c->stats->is_over)
	{
		pthread_mutex_unlock(&philo_c->stats->state_mutex);
		return (NULL);
	}
	pthread_mutex_unlock(&philo_c->stats->state_mutex);
	print_msg("is sleeping", philo);
	usleep(((t_philo *)philo)->sleep_t * 1000);
	return (NULL);
}

void	dead_philo(t_philo *philo)
{
	print_msg("died", philo);
	return ;
}
