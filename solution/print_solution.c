/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 12:38:25 by lshellie          #+#    #+#             */
/*   Updated: 2019/09/26 12:56:10 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem_in.h"

//void	make_step(t_lst *lst)
//{
//
//}

void	find_ends(t_lst *lst)
{
	t_nodes		*cur_node;
	t_sets		*set;

	set = lst->sets;
	while (set)
	{
		cur_node = set->nodes_start;
		while (cur_node->next)
			cur_node = cur_node->next;
		set->nodes_end = cur_node;
		set = set->next;
		++lst->num_of_sets;
	}
}

int 	print_solution(int num, t_lst *lst)
{
	t_nodes		*cur_node;
	t_sets		*cur_set;

	cur_set = lst->sets;
	find_ends(cur_set);
	while (1)
	{
//		make_step(lst);
		while (cur_set)
		{
			cur_node = cur_set->nodes_end;
			while (cur_node)
			{

				cur_node = cur_node->prev;
			}
			cur_set = cur_set->next;
		}
	}
}
