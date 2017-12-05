/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:16:03 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 02:15:52 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	first_room_init(t_lemin *lemin, char *line, int x)
{
	lemin->rooms = (t_room *)ft_memalloc(sizeof(t_room));
	lemin->rooms->next = NULL;
	lemin->rooms->name = ft_strsub(line, 0, x);
	lemin->rooms->start = 0;
	lemin->rooms->end = 0;
	lemin->rooms->checked = 0;
	lemin->rooms->path = 0;
	lemin->rooms->pos = -1;
	lemin->rooms->ants_num = 0;
	if (lemin->check_start == 1)
	{
		lemin->rooms->start = 1;
		lemin->check_start = 0;
	}
	if (lemin->check_end == 1)
	{
		lemin->rooms->end = 1;
		lemin->check_end = 0;
	}
}

void	next_room_init(t_lemin *lemin, char *line, int x)
{
	t_room *tmp;

	tmp = lemin->rooms;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (t_room *)ft_memalloc(sizeof(t_room));
	tmp->next->name = ft_strsub(line, 0, x);
	tmp->next->next = NULL;
	tmp->next->start = 0;
	tmp->next->end = 0;
	tmp->next->checked = 0;
	tmp->next->path = 0;
	tmp->next->pos = -1;
	tmp->next->ants_num = 0;
	if (lemin->check_start == 1)
	{
		tmp->next->start = 1;
		lemin->check_start = 0;
	}
	if (lemin->check_end == 1)
	{
		tmp->next->end = 1;
		lemin->check_end = 0;
	}
}

void	parce_room(t_lemin *lemin, char *line)
{
	int		x;

	x = -1;
	while (line[++x] != ' ')
		;
	if (!lemin->rooms)
		first_room_init(lemin, line, x);
	else
		next_room_init(lemin, line, x);
}

/*
**if line starts with # (comment) or with the L (path) skiping the line
**if not, and there are to spases - it's a room
*/

int		check_for_room(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	else if ((ft_space(line)) == 2)
		return (1);
	return (0);
}

int		add_rooms(t_lemin *lemin, char *line)
{
	if (!check_for_room(line))
		return (0);
	parce_room(lemin, line);
	lemin->rooms_num++;
	return (1);
}
