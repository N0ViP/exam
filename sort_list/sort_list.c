#include <stdio.h>

typedef struct s_list t_list;

struct s_list
{
	int     data;
	t_list  *next;
};

int cmp(int a, int b)
{
	return (a <= b);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int tmp;
	t_list *i;
	t_list *j;

	if (!lst || !lst->next)
		return (lst);
	i = lst;
	j = lst->next;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (!cmp(i->data, j->data))
			{
				tmp = i->data;
				i->data = j->data;
				j->data = tmp;
			}
			j = j->next;
		}
		i = i->next;
	}
	return (lst);
}



int main()
{
	t_list ptr1 = {9,NULL};
	t_list ptr2 = {5,NULL};
	t_list ptr3 = {7,NULL};
	t_list ptr4 = {3,NULL};
	t_list ptr5 = {1,NULL};
	ptr1.next = &ptr2;
	ptr1.next->next = &ptr3;
	ptr1.next->next->next = &ptr4;
	ptr1.next->next->next->next = &ptr5;
	t_list *ptr = sort_list(&ptr1, cmp);
	while (ptr)
	{
		printf("%d\n", ptr->data);
		ptr = ptr->next;
	}
}
