/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:08:09 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 02:22:34 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		room_end(t_lemin *lemin, t_room *tmp, int y)
{
	tmp->path = 1;
	tmp->pos = y + 1;
	return (1);
}

int		recursion(t_lemin *lemin, t_room *tmp, int y)
{
	int x;

	x = -1;
	while (tmp->door_names[++x])
	{
		if ((searching_path(lemin, tmp->door_names[x], y + 1)) == 1)
			return (room_end(lemin, tmp, y));
	}
	return (0);
}

int		searching_path(t_lemin *lemin, char *door_name, int y)
{
	t_room	*tmp;

	tmp = lemin->rooms;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, door_name) == 0)
		{
			if (tmp->checked == 1)
				return (0);
			tmp->checked = 1;
			if (tmp->end == 1)
				return (room_end(lemin, tmp, y));
			else
			{
				if (recursion(lemin, tmp, y))
					return (1);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

/*
**looking for a possible path,  if it's exist
*/

int		validate_path(t_lemin *lemin, t_room *rooms)
{
	t_room	*tmp;
	int		x;
	int		y;

	tmp = start_search(rooms);
	y = 0;
	tmp->checked = 1;
	tmp->pos = y;
	tmp->path = 1;
	if (tmp->doors_num == 0)
		return (0);
	x = -1;
	while (tmp->door_names[++x])
	{
		if (searching_path(lemin, tmp->door_names[x], y))
			return (1);
	}
	return (0);
}
