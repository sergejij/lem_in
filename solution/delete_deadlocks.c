#include "../lem_in.h"

void    ft_find_end_lock(t_map *nest, int index_lock, int i)
{
    while (++i < nest->rooms[index_lock].num_of_links)
    {
        // надо найти точку пересечения (то есть отметить всю линию)
        if (nest->rooms[index_lock].weght - 1 == nest->rooms[nest->rooms[index_lock].links[i]].weght
        && !nest->rooms[nest->rooms[index_lock].links[i]].invisib)
        {
            nest->rooms[index_lock].hide = 1;
            nest->ways[ft_find_index_ways(nest, index_lock, nest->rooms[index_lock].links[i])].invisible = 1;
            index_lock = nest->rooms[index_lock].links[i];
            i = -1;
        }
        if (nest->rooms[index_lock].start)
            break;
    }
}

void    ft_deadlock_breaker(t_map *nest, int index_lock, int i)
{
    ft_find_end_lock(nest, index_lock, -1);
}

void    ft_delete_deadlocks(t_map *nest, int i)
{
    while (++i < nest->num_of_rooms)
    {
        if (nest->rooms[i].num_of_links == 1 && !nest->rooms[i].start && !nest->rooms[i].end)
        {
            ft_deadlock_breaker(nest, i,-1);
        }
    }
}