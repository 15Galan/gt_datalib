# Listas Doblemente Enlazadas

```C
/**
 * @brief   Creates a new node with the given data.
 *
 * @param data  Pointer to the data to be stored in the node.
 *
 * @return  Pointer to the new node.
 */
t_dlist	*dll_new(void *data)
{
	t_dlist	*new;

	new = (t_dlist *) malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
```

```C
/**
 * @brief   Adds a new node at the beginning of the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the new node to be added.
 */
void	dll_add_first(t_dlist **list, t_dlist *elem)
{
	if (dll_empty(*list))
		*list = elem;
	else
	{
		elem->next = *list;
		(*list)->prev = elem;
		*list = elem;
	}
}
```

```C
/**
 * @brief   Adds a new node after the given node.
 *
 * @param list	Pointer to the first element of the list.
 * @param data  Pointer to the data to be stored in the node.
 */
void	dll_add_after(t_dlist *elem, t_dlist *new)
{
	if (dll_empty(elem) || dll_empty(new))
		return ;
	new->next = elem->next;
	new->prev = elem;
	if (elem->next)
		elem->next->prev = new;
	elem->next = new;
}
```

```C
/**
 * @brief   Adds a new node at the end of the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the new node to be added.
 */
void	dll_add_last(t_dlist **list, t_dlist *elem)
{
	t_dlist	*last;

	if (dll_empty(*list))
		*list = elem;
	else
	{
		last = dll_last(*list);
		last->next = elem;
		elem->prev = last;
	}
}
```

```C
/**
 * @brief   Replace the data of the given node.
 *
 * @param elem	Pointer to the node to be modified.
 * @param data  The new data.
 *
 * @return  Pointer to the modified node;
 * 			NULL otherwise.
 */
t_dlist	*dll_replace(t_dlist *elem, void *data)
{
	t_dlist	*new;

	new = dll_new(data);
	if (!new)
		return (NULL);
	if (elem->prev)
		elem->prev->next = new;
	if (elem->next)
		elem->next->prev = new;
	new->prev = elem->prev;
	new->next = elem->next;
	free(elem);
	return (new);
}
```

```C
/**
 * @brief   Removes the first node of the list.
 *
 * @param list	Pointer to the first element of the list.
 */
void	dll_remove_first(t_dlist **list)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	aux = *list;
	*list = (*list)->next;
	if (*list)
		(*list)->prev = NULL;
	free(aux);
}
```

```C
/**
 * @brief   Removes the given node from the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the element to be removed.
 */
void	dll_remove(t_dlist **list, t_dlist *elem)
{
	if (dll_empty(*list))
		return ;
	if (elem->prev)
		elem->prev->next = elem->next;
	else
		*list = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}
```

```C
/**
 * @brief   Removes the last node of the list.
 *
 * @param list	Pointer to the first element of the list.
 */
void	dll_remove_last(t_dlist **list)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	aux = *list;
	while (aux->next)
		aux = aux->next;
	if (aux->prev)
		aux->prev->next = NULL;
	else
		*list = NULL;
	free(aux);
}
```

```C
/**
 * @brief	Removes all the nodes with the given data.
 *
 * @param list	Pointer to the first element of the list.
 * @param data	Pointer to the data to be removed.
 */
void	dll_purge(t_dlist **list, void *data)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	aux = *list;
	while (aux)
	{
		if (aux->data == data)
			dll_remove(list, aux);
		aux = aux->next;
	}
}
```

```C
/**
 * @brief   Removes all the nodes of the list.
 *
 * @param list	Pointer to the first element of the list.
 */
void	dll_clear(t_dlist **list)
{
	t_dlist	*aux;

	if (dll_empty(*list))
		return ;
	while (*list)
	{
		aux = *list;
		*list = (*list)->next;
		free(aux);
	}
}
```

```C
/**
 * @brief	Checks if the list is empty.
 * @param list	Pointer to the first element of the list.
 *
 * @return	1 if the list is empty;
 * 			0 otherwise.
 */
int	dll_empty(t_dlist *list)
{
	return (list == NULL);
}
```

```C
/**
 * @brief   Counts the number of nodes in the list.
 *
 * @param list   Pointer to the first element of the list.
 *
 * @return  Number of nodes in the list.
 */
int	dll_size(t_dlist *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
```

```C
/**
 * @brief   Returns the first node of the list.
 *
 * @param list	Pointer to an element of the list.
 *
 * @return	Pointer to the first node of the list.
 */
t_dlist	*dll_first(t_dlist *list)
{
	while (list && list->prev)
		list = list->prev;
	return (list);
}
```

```C
/**
 * @brief   Returns the last node of the list.
 *
 * @param list	Pointer to an element of the list.
 *
 * @return	Pointer to the last node of the list.
 */
t_dlist	*dll_last(t_dlist *list)
{
	while (list && list->next)
		list = list->next;
	return (list);
}
```

```C
/**
 * @brief	Searches an element in the list.
 *
 * @param list	Pointer to the first element of the list.
 * @param data	The data to search.
 *
 * @return	Pointer to the node containing the data;
 * 			NULL if the data is not found.
 */
t_dlist	*dll_search(t_dlist *list, void *data)
{
	while (list)
	{
		if (list->data == data)
			return (list);
		list = list->next;
	}
	return (NULL);
}
```



# Colas

```C
/**
 * @brief   Creates a new node with the given data.
 *
 * @param data  Pointer to the data to be stored in the node.
 *
 * @return  Pointer to the new node.
 */
t_queue	*que_new(void *data)
{
	t_queue	*new;

	new = (t_queue *) malloc(sizeof(t_queue));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
```

```C
/**
 * @brief   Adds a new node at the end of the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 * @param data	Pointer to the data to be stored in the node.
 */
void	que_enqueue(t_queue **queue, void *data)
{
	t_queue	*new;

	new = que_new(data);
	if (!new)
		return ;
	if (que_empty(*queue))
	{
		*queue = new;
		return ;
	}
	que_last(*queue)->next = new;
}
```

```C
/**
 * @brief   Removes the first node of the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 * 
 * @return  Pointer to the data stored in the removed node.
 */
void	*que_dequeue(t_queue **queue)
{
	t_queue	*aux;
	void	*data;

	if (que_empty(*queue))
		return (NULL);
	aux = *queue;
	*queue = (*queue)->next;
	data = aux->data;
	free(aux);
	return (data);
}
```

```C
/**
 * @brief   Removes all the nodes of the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 */
void	que_clear(t_queue **queue)
{
	while (!que_empty(*queue))
		que_dequeue(queue);
}
```

```C
/**
 * @brief	Checks if the queue is empty.
 * @param queue	Pointer to the first element of the queue.
 *
 * @return	1 if the queue is empty;
 * 			0 otherwise.
 */
int	que_empty(t_queue *queue)
{
	return (queue == NULL);
}
```

```C
/**
 * @brief   Counts the number of nodes in the queue.
 *
 * @param queue   Pointer to the first element of the queue.
 *
 * @return  Number of nodes in the queue.
 */
int	que_size(t_queue *queue)
{
	int	i;

	i = 0;
	while (queue)
	{
		queue = queue->next;
		i++;
	}
	return (i);
}
```

```C
/**
 * @brief   Returns the first node of the queue.
 *
 * @param queue	Pointer to an element of the queue.
 *
 * @return	Pointer to the first node of the queue.
 */
t_queue	*que_first(t_queue *queue)
{
	return (queue);
}
```

```C
/**
 * @brief   Returns the last node of the queue.
 *
 * @param queue	Pointer to an element of the queue.
 *
 * @return	Pointer to the last node of the queue.
 */
t_queue	*que_last(t_queue *queue)
{
	while (queue && queue->next)
		queue = queue->next;
	return (queue);
}
```

```C
/**
 * @brief	Searches an element in the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 * @param data	The data to search.
 *
 * @return	Pointer to the node containing the data;
 * 			NULL if the data is not found.
 */
t_queue	*que_search(t_queue *queue, void *data)
{
	while (queue)
	{
		if (queue->data == data)
			return (queue);
		queue = queue->next;
	}
	return (NULL);
}
```



# Pilas

```C
/**
 * @brief	Creates a new element for the stack.
 *
 * @param data	The data to store in the element.
 *
 * @return	Pointer to the new element.
 */
t_stack	*stk_new(void *data)
{
	t_stack	*new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
```

```C
/**
 * @brief	Adds an element to the stack.
 *
 * @param stack	Pointer to the stack.
 * @param data 	The data to store in the new element.
 */
void	stk_push(t_stack **stack, void *data)
{
	t_stack	*new;

	new = stk_new(data);
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}
```

```C
/**
 * @brief	Extracts the top element from the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return 	Pointer to the top element;
 * 			NULL if the stack is empty.
 */
t_stack	*stk_pop(t_stack **stack)
{
	t_stack	*aux;

	if (*stack == NULL)
		return (NULL);
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = NULL;
	return (aux);
}
```

```C
/**
 * @brief	Deletes the stack.
 *
 * @param stack 	Pointer to the stack.
 */
void	stk_clear(t_stack **stack)
{
	t_stack	*aux;

	while (*stack != NULL)
	{
		aux = *stack;
		*stack = (*stack)->next;
		free(aux);
	}
}
```

```C
/**
 * @brief	Checks if the stack is empty.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	1 if the stack is empty;
 * 			0 otherwise.
 */
int	stk_empty(t_stack *stack)
{
	return (stack == NULL);
}
```

```C
/**
 * @brief	Counts the number of elements in the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	Number of elements in the stack.
 */
int	stk_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
```

```C
/**
 * @brief	Checks the top element of the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return 	Pointer to the top element;
 * 			NULL if the stack is empty.
 */
t_stack	*stk_top(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack);
}
```

```C
/**
 * @brief	Checks the top element data of the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	Pointer to the top element data;
 * 			NULL if the stack is empty.
 */
void	*stk_peek(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack->data);
}
```



# Conjuntos

```C
t_set	*set_new(void *data)
{
	t_set	*new;

	new = (t_set *) malloc(sizeof(t_set));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	return (new);
}
```

```C
void	set_add(t_set **set, void *data)
{
	t_set	*new;

	new = set_new(data);
	if (!new || set_contains(*set, data))
		return ;
	while (*set)
		set = &(*set)->next;
	*set = new;
}
```

```C
void	set_remove(t_set **set, void *data)
{
	t_set	*aux;
	t_set	*prev;

	if (!set_contains(*set, data))
		return ;
	aux = *set;
	prev = NULL;
	while (aux)
	{
		if (aux->data == data)
		{
			if (prev)
				prev->next = aux->next;
			else
				*set = aux->next;
			free(aux);
			return ;
		}
		prev = aux;
		aux = aux->next;
	}
}
```

```C
t_set	*set_union(t_set *set1, t_set *set2)
{
	t_set	*aux;
	t_set	*new;

	new = NULL;
	aux = set1;
	while (aux)
	{
		set_add(&new, aux->data);
		aux = aux->next;
	}
	aux = set2;
	while (aux)
	{
		set_add(&new, aux->data);
		aux = aux->next;
	}
	return (new);
}
```

```C
t_set	*set_inter(t_set *set1, t_set *set2)
{
	t_set	*aux;
	t_set	*new;

	new = NULL;
	aux = set1;
	while (aux)
	{
		if (set_contains(set2, aux->data))
			set_add(&new, aux->data);
		aux = aux->next;
	}
	return (new);
}
```

```C
t_set	*set_diff(t_set *set1, t_set *set2)
{
	t_set	*aux;
	t_set	*new;

	new = NULL;
	aux = set1;
	while (aux)
	{
		if (!set_contains(set2, aux->data))
			set_add(&new, aux->data);
		aux = aux->next;
	}
	return (new);
}
```

```C
int	set_empty(t_set *set)
{
	if (!set)
		return (1);
	return (0);
}
```

```C
int	set_contains(t_set *set, void *data)
{
	while (set)
	{
		if (set->data == data)
			return (1);
		set = set->next;
	}
	return (0);
}
```

```C
int	set_subset(t_set *set1, t_set *set2)
{
	while (set1)
	{
		if (!set_contains(set2, set1->data))
			return (0);
		set1 = set1->next;
	}
	return (1);
}
```

```C
int	set_equal(t_set *set1, t_set *set2)
{
	if (set_size(set1) != set_size(set2))
		return (0);
	return (set_subset(set1, set2));
}
```

```C
int	set_size(t_set *set)
{
	int	i;

	i = 0;
	while (set)
	{
		i++;
		set = set->next;
	}
	return (i);
}
```
