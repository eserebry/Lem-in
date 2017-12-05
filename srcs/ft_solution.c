/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_solution_path.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:04:51 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 00:26:58 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*start_search(t_room *room)
{
	t_room *tmp;

	tmp = room;
	while (tmp)
	{
		if (tmp->start == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_room	*rooms_search(t_room *rooms, int pos)
{
	t_room *tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->pos == pos)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

/*
**looking for a posiible solition path
*/

void	create_solution_path(t_lemin *lemin, t_room *rooms)
{
	t_room	*tmp;
	t_room	*next;
	int		pos;

	pos = 1;
	lemin->way = start_search(rooms);
	next = rooms_search(rooms, pos);
	tmp = lemin->way;
	tmp->prev = NULL;
	while (next->end == 0)
	{
		next->prev = tmp;
		tmp->way = next;
		tmp = tmp->way;
		pos++;
		next = rooms_search(rooms, pos);
	}
	next->prev = tmp;
	tmp->way = next;
}
