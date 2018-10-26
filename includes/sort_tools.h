/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tools.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmickael <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/22 17:21:53 by bmickael           #+#    #+#             */
/*   Updated: 2018/07/22 17:21:56 by bmickael          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_TOOLS_H
# define SORT_TOOLS_H

# include <stdlib.h>
# include <errno.h>

# include "chained_tools.h"
# include "custom_allocator.h"

# define FALSE		0
# define TRUE		1

struct	s_info
{
	int			offset;
	int			(*cmp)(void *, void *);
};

int		fusion_merge_chain_list(
		struct s_list *lst,
		int (*cmp)(void *, void *),
		struct s_custom_memory_fn *mem);

int		fusion_merge_tab(
		void ***t1,
		int len,
		int (*cmp)(void *, void *),
		struct s_custom_memory_fn *mem);

#endif
