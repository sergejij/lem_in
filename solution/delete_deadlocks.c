#include "../lem_in.h"

int    ft_find_end_lock(t_map *nest, int index_lock, int i)
{
    while (++i < nest->rooms[index_lock].num_of_links)
    {
        // надо найти точку пересечения (то есть отметить всю линию)Жц
        if (nest->rooms[nest->rooms[index_lock].links[i]].weght - 1 == nest->rooms[index_lock].links[i])
        {
            nest->rooms[index_lock].invisib = 1;
        }
    }
}

void    ft_deadlock_breaker(t_map *nest, int index_lock, int i)
{
    int index_lockend;

    index_lockend = ft_find_end_lock(nest, index_lock, -1);
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