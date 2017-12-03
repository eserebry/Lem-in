/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 20:46:28 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 02:30:05 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		counter;
	char	*ptr;

	counter = 0;
	if (!s1)
		return (NULL);
	while (s1[counter] != '\0')
		counter++;
	ptr = (char*)ft_memalloc(sizeof(char) * counter + 1);
	counter = 0;
	while (s1[counter] != '\0')
	{
		ptr[counter] = s1[counter];
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
