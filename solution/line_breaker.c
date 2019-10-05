#include "../lem_in.h"

int ft_find_intersections(t_map *nest, int index_forb, int i, int j)
{
	// у меня есть одна вершина, я подаю еЁ и еЁ связь в функцию, которая выдает индекс пути
	// тут же проверяю является ли это ребро запрещенным
	// если ((текущая запрещенная вершина - 1) == вершине) по связи и он форбиден,
	// значит это путь к старту, ищу пересечение
	// в таком же стиле иду до старта, но если встречаю вершину с более чем двумя связями, возвращяю её
	t_room *room;

	room = nest->rooms;
	while (++i < room[nest->index_end].weght)
	{
		while (++j < room[index_forb].num_of_links)
		{
			if (room[room[index_forb].links[j]].sh == room[index_forb].sh &&
				((room[index_forb].weght - 1) == room[room[index_forb].links[j]].weght)  &&
				(!nest->ways[ft_find_index_ways(nest, index_forb, room[index_forb].links[j])].invisible)) // не является ли связь в пересечении невидимой
			{
				index_forb = room[index_forb].links[j];
				j = 0;
			}
			if (room[room[index_forb].links[j]].sh == room[index_forb].sh &&
				room[index_forb].num_of_links > 2)
				return (index_forb);
		}
	}
	return (-1);
}

void ft_delete_ways(t_map *nest, int start, int end, int i)
{
	// 1. иду по связи старта, по форбиден
	// 2. отмечаю эту трубку как невидимую (или прям удалять?)
	// 3. перехожу на след и так до енд
	t_room *room;
	int index_way;

	room = nest->rooms;
	while (++i < room[start].num_of_links && start != end)
	{
		if (room[room[start].links[i]].sh == room[start].sh &&
			(room[start].weght + 1) == room[room[start].links[i]].weght)
		{
			nest->rooms[start].invisib = 1;
			nest->rooms[room[start].links[i]].invisib = 1;
            room[room[end].links[i]].sh = 0;
			index_way = ft_find_index_ways(nest, start, room[start].links[i]);
			nest->ways[index_way].invisible = 1;
			start = room[start].links[i];
			i = -1;
		}
	}
}


void 	ft_line_breaker(t_map *nest, int index_forb)
{ // ф-я удаляет линию без пересечений, до пересечения
	int index_intersections;
	int i;

	i = -1;
	// если нет пересечений до старта, а только линия, мы не трогаем
	// то есть сначала имеет смысл проверить есть ли пересечения до старта
	// если да, получить этот индекс
	if ((index_intersections = ft_find_intersections(nest, index_forb, -1, -1)) == - 1)
	{
		// нет пересечений, значит надо удалить ту линию по которой мы пришли к форбиден вершине
		// просто вычитанием веса я могу получить нужную вершину, так как
		// при запуске ft_find_shortest я обнулил вершины и заного отметил один (другой путь)

		// надо сделать невидимой линию до пересечения(своего пересечения, просто иди пока не будет более 2-х связей)
		// если его нет, то
		while (++i < nest->rooms[index_forb].num_of_links)
		{
			if ((nest->rooms[index_forb].weght - 1) == nest->rooms[nest->rooms[index_forb].links[i]].weght)
			{
				index_intersections = nest->rooms[index_forb].links[i];
				if (nest->rooms[index_forb].num_of_links > 2)
					ft_delete_ways(nest, index_intersections, index_forb, -1);
			}
			else
				break;
		}
		return ;
	}
	// иначе у меня есть пересечение и мне нужно удалить от пересечения до индекс_форб
	ft_delete_ways(nest, index_intersections, index_forb, -1);
}