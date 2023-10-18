void	stk_push(t_stack **stack, void *data)
{
	t_stack	*new;

	new = stk_new(data);
	if (new == NULL)
		return ;
	new->next = *stack;
	*stack = new;
}