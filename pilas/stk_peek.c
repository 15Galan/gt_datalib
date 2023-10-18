void	*stk_peek(t_stack *stack)
{
	if (stk_empty(stack))
		return (NULL);
	return (stack->data);
}