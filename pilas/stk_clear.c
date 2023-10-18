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