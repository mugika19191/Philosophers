/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imugica- <imugica-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 13:16:36 by imugica-          #+#    #+#             */
/*   Updated: 2025/05/07 11:49:55 by imugica-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	throw_thread(t_philo *p_head, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (p_head->id % 2 == 0)
			usleep(500);
		pthread_create(&(p_head->thread), NULL, philo_loop, (void *)p_head);
		p_head = p_head->next;
		i++;
	}
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

t_philo	*ft_philotnew(int id, char **args, t_stats *stats, int mode)
{
	t_philo	*mylist;

	mylist = malloc(sizeof(struct s_philo));
	if (!mylist)
		return (NULL);
	mylist->next = mylist;
	mylist->id = id;
	mylist->die_t = ft_atoi(args[2]);
	mylist->eat_t = ft_atoi(args[3]);
	mylist->sleep_t = ft_atoi(args[4]);
	mylist->meals = -1;
	if (mode)
	{
		if (ft_atoi(args[5]) > 0)
			mylist->meals = ft_atoi(args[5]);
	}
	mylist->stats = stats;
	mylist->start_time = stats->start_time;
	mylist->last_meal = stats->start_time;
	pthread_mutex_init(&(mylist->time_mutex), NULL);
	pthread_mutex_init(&mylist->fork, NULL);
	pthread_mutex_init(&mylist->eat_mutex, NULL);
	return (mylist);
}

void	ft_philoadd_back(t_philo **lst, t_philo *new_elem)
{
	if (!new_elem || !lst)
		return ;
	if (!*lst)
	{
		*lst = new_elem;
		return ;
	}
	ft_philolast(*lst)->next = new_elem;
	new_elem->next = *lst;
}

t_philo	*ft_philolast(t_philo *lst)
{
	t_philo	*lst_cpy;

	lst_cpy = lst->next;
	if (!lst)
		return (NULL);
	if (lst == lst_cpy)
		return (lst);
	while (lst_cpy->next != lst)
		lst_cpy = lst_cpy->next;
	return (lst_cpy);
}
