void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (!begin_list || !*begin_list)
		return ;
	t_list *tmp;
	t_list *ptr;
	while (*begin_lits && !cmp(data_ref, (*begin_list)->data))
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	ptr = *begin_list;
	while (ptr && ptr->next)
	{
		tmp = ptr->next;
		if (!cmp(data_ref, tmp->data))
		{
			ptr->next = tmp->next;
			free(tmp);
		}
		else
			ptr = ptr->next;
	}
}

