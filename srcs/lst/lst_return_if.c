/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_return_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:44:38 by bmickael          #+#    #+#             */
/*   Updated: 2018/10/29 17:44:42 by bmickael         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	*ft_lst_return_if(void *start, int (*f)(void*))
{
	t_gen_lst *start_cast;

	start_cast = start;
	while (start_cast)
	{
		if ((f)(start_cast) == 1)
			return (start_cast);
		start_cast = start_cast->next;
	}
	return (NULL);
}

void	*ft_dlst_return_if(void *start, int (*f)(void*), int order)
{
	t_gen_dlst *start_cast;

	start_cast = start;
	while (start_cast)
	{
		if ((f)(start_cast) == 1)
			return (start_cast);
		if (order == 1)
			start_cast = start_cast->next;
		else if (order == 2)
			start_cast = start_cast->prev;
	}
	return (NULL);
}
