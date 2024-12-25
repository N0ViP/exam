#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list *i = lst;
	t_list *j;
	int swp = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (cmp(j->data, i->data))
			{
				swp = i->data;
				i->data = j->data;
				j->data = swp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (lst);
}
