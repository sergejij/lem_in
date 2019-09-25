/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_turns.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:47:47 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/25 13:47:48 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

int 	calculate_turns(t_map *nest, t_lst *lst)
{
	t_sets		*cur_set;
	int 		i;

	cur_set = lst->sets;
	cur_set->turns = nest->ants + cur_set->len;
	i = 0;
	while (cur_set)
	{
		if (cur_set->next)
		{
			if (!cur_set->next->turns && cur_set->turns > cur_set->next->len)
			{
				--cur_set->turns;
				cur_set->next->turns = cur_set->next->len + 1;
			}
			while (cur_set->next->turns && cur_set->turns > cur_set->next->turns)
			{
				--cur_set->turns;
				++cur_set->next->turns;
			}
		}
		if (cur_set->turns >= i)
			i = cur_set->turns;
		cur_set = cur_set->next;
	}
	lst->sum = i;
	return (0);
}