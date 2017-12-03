/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_doors_to_rooms.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:02:57 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/26 03:11:03 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
**counting number of the doors, using a room name
*/

void	count_doors(t_room *rooms, t_link *links)
{
	t_room	*tmp;
	t_link	*tmp2;

	tmp = rooms;
	while (tmp)
	{
		tmp2 = links;
		while (tmp2)
		{
			if (ft_strcmp(tmp->name, tmp2->name1) == 0)
				tmp->doors_num++;
			if (ft_strcmp(tmp->name, tmp2->name2) == 0)
				tmp->doors_num++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

/*
**creating doors
*/

int		doors(t_room *tmp, t_link *tmp2, int i)
{
	if (ft_strcmp(tmp->name, tmp2->name1) == 0)
	{
		tmp->door_names[i] = ft_strdup(tmp2->name2);
		i++;
	}
	if (ft_strcmp(tmp->name, tmp2->name2) == 0)
	{
		tmp->door_names[i] = ft_strdup(tmp2->name1);
		i++;
	}
	return (i);
}

void	get_doors(t_room *rooms, t_link *links)
{
	t_room	*tmp;
	t_link	*tmp2;
	int		i;

	tmp = rooms;
	tmp2 = links;
	while (tmp)
	{
		if (tmp->doors_num > 0)
		{
			tmp->door_names = (char **)ft_memalloc(sizeof(char*)
				* (tmp->doors_num + 1));
			tmp->door_names[tmp->doors_num] = 0;
		}
		tmp2 = links;
		i = 0;
		while (tmp2)
		{
			i = doors(tmp, tmp2, i);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	add_doors(t_lemin *lemin)
{
	count_doors(lemin->rooms, lemin->links);
	get_doors(lemin->rooms, lemin->links);
}
