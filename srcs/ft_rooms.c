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

void	init_room(t_lemin *lemin, char *line, int x)
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
	if (lemin->start_on == 1)
	{
		lemin->rooms->start = 1;
		lemin->start_on = 0;
	}
	if (lemin->end_on == 1)
	{
		lemin->rooms->end = 1;
		lemin->end_on = 0;
	}
}

void	init_next_room(t_lemin *lemin, char *line, int x)
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
	if (lemin->start_on == 1)
	{
		tmp->next->start = 1;
		lemin->start_on = 0;
	}
	if (lemin->end_on == 1)
	{
		tmp->next->end = 1;
		lemin->end_on = 0;
	}
}

void	add_room(t_lemin *lemin, char *line)
{
	int		x;

	x = -1;
	while (line[++x] != ' ')
		;
	if (!lemin->rooms)
		init_room(lemin, line, x);
	else
		init_next_room(lemin, line, x);
}
