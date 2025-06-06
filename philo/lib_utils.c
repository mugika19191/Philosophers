/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:17:04 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/07 11:35:51 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\r'
		|| c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while (is_space(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + (str[i++] - '0');
	return (res * neg);
}

void	init_stats(t_stats *stats, char **args)
{
	stats->is_over = 0;
	stats->start_time = get_current_time();
	stats->philo_amount = ft_atoi(args[1]);
	pthread_mutex_init(&stats->state_mutex, NULL);
	pthread_mutex_init(&stats->start_mutex, NULL);
	pthread_mutex_init(&stats->print_mutex, NULL);
	return ;
}

int	check_inputs(char **args, int count)
{
	int	i;
	int	j;

	j = 0;
	i = 1;
	while (i < count)
	{
		while (args[i][j])
		{
			if (!ft_isdigit(args[i][j]))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	join_all(t_philo *p_head, t_manager manager)
{
	if (p_head->stats->philo_amount > 1)
	{
		while (p_head->id)
		{
			pthread_join(p_head->thread, NULL);
			p_head = p_head->next;
			if (p_head->id == 1)
				break ;
		}
	}
	pthread_join(manager.thread, NULL);
}
