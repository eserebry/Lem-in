/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 06:48:54 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/26 03:11:38 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_links(t_link *links)
{
	t_link *current;
	t_link *previous;

	previous = links;
	current = links;
	while (current)
	{
		current = current->next;
		ft_strdel(&previous->name1);
		ft_strdel(&previous->name2);
		ft_memdel((void*)&previous);
		previous = current;
	}
	ft_memdel((void*)&previous);
}

void	delete_rooms(t_room *rooms)
{
	int x;

	x = -1;
	if (!rooms->door_names)
		return ;
	while (rooms->door_names[++x])
		ft_strdel(&rooms->door_names[x]);
	ft_memdel((void*)&rooms->door_names);
}

void	free_rooms(t_lemin *lemin)
{
	t_room *tmp;

	tmp = lemin->rooms->next;
	while (tmp)
	{
		if (lemin->rooms->door_names)
			delete_rooms(lemin->rooms);
		if (lemin->rooms->name)
			ft_strdel(&lemin->rooms->name);
		ft_memdel((void*)&lemin->rooms);
		lemin->rooms = tmp;
		tmp = tmp->next;
	}
	if (lemin->rooms->name)
		ft_strdel(&lemin->rooms->name);
	delete_rooms(lemin->rooms);
	ft_memdel((void*)&lemin->rooms);
}

void	free_all(t_lemin *lemin)
{
	if (lemin->links)
		delete_links(lemin->links);
	if (lemin->rooms)
		free_rooms(lemin);
	ft_strdel(&lemin->input);
	ft_memdel((void*)&lemin);
}
