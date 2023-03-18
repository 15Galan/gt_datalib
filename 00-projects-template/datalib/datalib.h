/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datalib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/03/15 12:39:24 by juan-aga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATALIB_H
# define DATALIB_H

# include <unistd.h>
# include <stdlib.h>
# include "../../Libft/libft.h"

/***************************** DOUBLY LINKED LIST *****************************/

/**
 * @brief 	Structure for a doubly linked list.
 * 
 * @param data 	The data stored in the element.
 * @param prev 	Pointer to the previous element in the list.
 * @param next 	Pointer to the next element in the list.
 */
typedef struct s_dlist
{
	void			*data;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}	t_dlist;

/**
 * @brief 	Creates a new element for a doubly linked list.
 * 
 * @param data	The data to be stored in the element.
 * 
 * @return	Pointer to the new element.
 */
t_dlist	*dll_new(void *data);

/**
 * @brief	Adds a new element to the beginning of the list.
 * 
 * @param list	Pointer to the first element of the list.
 * @param new 	Pointer to the new element to be added.
 */
void	dll_add_first(t_dlist **list, t_dlist *elem);

/**
 * @brief	Adds a new element to the list before the given element.
 * 
 * @param elem	Pointer to the element to be added before.
 * @param new 	Pointer to the new element to be added.
 */
void	dll_add_after(t_dlist *elem, t_dlist *new);

/**
 * @brief	Adds a new element to the list after the given element.
 * 
 * @param elem	Pointer to the element to be added after.
 * @param new 	Pointer to the new element to be added.
 */
void	dll_add_last(t_dlist **list, t_dlist *elem);

/**
 * @brief 	Replaces the data of the given element with the given data.
 * 
 * @param elem		Pointer to the element to be replaced.
 * @param new_data	The new data to be stored in the element.
 * 
 * @return	Pointer to the new element.
 */
t_dlist	*dll_replace(t_dlist *elem, void *new_data);

/**
 * @brief 	Deletes the first element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	dll_remove_first(t_dlist **list);

/**
 * @brief 	Deletes the given element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the element to be deleted.
 */
void	dll_remove(t_dlist **list, t_dlist *elem);

/**
 * @brief 	Deletes the last element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	dll_remove_last(t_dlist **list);

/**
 * @brief 	Deletes all the elements in the list that match the given data.
 * 
 * @param list	Pointer to the first element of the list.
 * @param data	The data to be deleted.
 * 
 * @return	Number of elements deleted.
 */
void	dll_purge(t_dlist **list, void *data);

/**
 * @brief 	Deletes all the elements in the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	dll_clear(t_dlist **list);

/**
 * @brief	Checks if the list is empty.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return 	1 if the list is empty;
 *          0 otherwise.
 */
int		dll_empty(t_dlist *list);

/**
 * @brief   Counts the number of elements in the list. 
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return  The number of elements in the list.
 */
int		dll_size(t_dlist *list);

/**
 * @brief   Identifies the first element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return  Pointer to the first element of the list.
 */
t_dlist	*dll_first(t_dlist *list);

/**
 * @brief   Identifies the last element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return  Pointer to the last element of the list.
 */
t_dlist	*dll_last(t_dlist *list);

/**
 * @brief   Identifies the first element of the list with the given data.
 * 
 * @param list	Pointer to the first element of the list.
 * @param data  The data to be searched.
 * 
 * @return  Pointer to the element if found;
 *          NULL otherwise.
 */
t_dlist	*dll_search(t_dlist *list, void *data);

/**
 * @brief 	Prints the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	dll_print(t_dlist *list);

/*********************************** QUEUE ************************************/

/**
 * @brief 	Struct for the elements of the queue.
 * 
 * @param data	The data to be stored in the element.
 * @param next	Pointer to the next element in the queue.
 */
typedef struct s_queue
{
	void			*data;
	struct s_queue	*next;
}	t_queue;

/**
 * @brief   Creates a new node with the given data.
 *
 * @param data  Pointer to the data to be stored in the node.
 *
 * @return  Pointer to the new node.
 */
t_queue	*que_new(void *data);

/**
 * @brief   Adds a new node at the end of the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 * @param data	Pointer to the data to be stored in the node.
 */
void	que_enqueue(t_queue **queue, void *data);

/**
 * @brief   Removes the first node of the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 * 
 * @return  Pointer to the data stored in the removed node.
 */
void	*que_dequeue(t_queue **queue);

/**
 * @brief   Removes all the nodes of the queue.
 *
 * @param queue	Pointer to the first element of the queue.
 */
void	que_clear(t_queue **queue);

/**
 * @brief  	Checks if the queue is empty.
 * 
 * @param queue	Pointer to the first element of the queue.
 *  
 * @return	1 if the queue is empty;
 * 			0 otherwise.
 */
int		que_empty(t_queue *queue);

/**
 * @brief   Counts the number of elements in the queue.
 * 
 * @param queue	Pointer to the first element of the queue.
 * 
 * @return  The number of elements in the queue.
 */
int		que_size(t_queue *queue);

/**
 * @brief   Identifies the first element of the queue.
 * 
 * @param queue	Pointer to the first element of the queue.
 * 
 * @return  Pointer to the first element of the queue.
 */
t_queue	*que_first(t_queue *queue);

/**
 * @brief   Identifies the last element of the queue.
 * 
 * @param queue	Pointer to the first element of the queue.
 * 
 * @return  Pointer to the last element of the queue.
 */
t_queue	*que_last(t_queue *queue);

/**
 * @brief	Prints the queue.
 * 
 * @param queue	Pointer to the first element of the queue.
 */
void	que_print(t_queue *queue);

/*********************************** STACK ************************************/

/**
 * @brief 	Struct for the elements of the stack.
 * 
 * @param data	The data to be stored in the element.
 * @param next	Pointer to the next element in the stack.
 */
typedef struct s_stack
{
	void			*data;
	struct s_stack	*next;
}	t_stack;

/**
 * @brief	Creates a new element for the stack.
 *
 * @param data	The data to store in the element.
 *
 * @return	Pointer to the new element.
 */
t_stack	*stk_new(void *data);

/**
 * @brief	Adds an element to the stack.
 *
 * @param stack	Pointer to the stack.
 * @param data 	The data to store in the new element.
 */
void	stk_push(t_stack **stack, void *data);

/**
 * @brief	Extracts the top element from the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return 	Pointer to the top element;
 * 			NULL if the stack is empty.
 */
t_stack	*stk_pop(t_stack **stack);

/**
 * @brief	Deletes the stack.
 *
 * @param stack 	Pointer to the stack.
 */
void	stk_clear(t_stack **stack);

/**
 * @brief	Checks if the stack is empty.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	1 if the stack is empty;
 * 			0 otherwise.
 */
int		stk_empty(t_stack *stack);

/**
 * @brief	Counts the number of elements in the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	Number of elements in the stack.
 */
int		stk_size(t_stack *stack);

/**
 * @brief	Checks the top element of the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return 	Pointer to the top element;
 * 			NULL if the stack is empty.
 */
t_stack	*stk_top(t_stack *stack);

/**
 * @brief	Checks the data of the top element of the stack.
 *
 * @param stack	Pointer to the stack.
 *
 * @return	Pointer to the top element data;
 * 			NULL if the stack is empty.
 */
void	*stk_peek(t_stack *stack);

/**
 * @brief 	Prints the stack.
 * 
 * @param stack	Pointer to the stack. 
 */
void	stk_print(t_stack *stack);

/*********************************** SET ************************************/

/**
 * @brief	Struct for the elements of the set.
 * 
 * @param data	The data to be stored in the element.
 * @param next	Pointer to the next element in the set.
 */
typedef struct s_set
{
	void			*data;
	struct s_set	*next;
}	t_set;

/**
 * @brief	Creates a new element for the set.
 * 
 * @param data	The data to store in the element.
 * 
 * @return	Pointer to the new element.
 */
t_set	*set_new(void *data);

/**
 * @brief	Adds an element to the set.
 * 
 * @param set	Pointer to the set.
 * @param data	The data to store in the new element.
 */
void	set_add(t_set **set, void *data);

/**
 * @brief	Deletes an element from the set.
 * 
 * @param set	Pointer to the set.
 * @param data	The data to be deleted.
 */
void	set_remove(t_set **set, void *data);

/**
 * @brief	Deletes the set.
 * 
 * @param set	Pointer to the set.
 */
void	set_clear(t_set **set);

/**
 * @brief	Creates a new set resulting from the union of 2 sets.
 * 
 * @param set1	Pointer to the first set.
 * @param set2	Pointer to the second set.
 * 
 * @return	Pointer to a new set with elements in the first or second set.
 */
t_set	*set_union(t_set *set1, t_set *set2);

/**
 * @brief	Creates a new set resulting from the intersection of 2 sets.
 * 
 * @param set1	Pointer to the first set.
 * @param set2	Pointer to the second set.
 * 
 * @return	Pointer to the new set with elements in the first and second set.
 */
t_set	*set_inter(t_set *set1, t_set *set2);

/**
 * @brief	Creates a new set resulting from the difference of 2 sets.
 * 
 * @param set1	Pointer to the first set.
 * @param set2	Pointer to the second set.
 * 
 * @return	Pointer to the new set with elements in the first set,
 * 			but not in the second.
 */
t_set	*set_diff(t_set *set1, t_set *set2);

/**
 * @brief	Checks if the set is empty.
 * 
 * @param set	Pointer to the set.
 * 
 * @return	1 if the set is empty;
 * 			0 otherwise.
 */
int		set_empty(t_set *set);

/**
 * @brief	Checks if the set contains an element.
 * 
 * @param set	Pointer to the set.
 * @param data	The data to be checked.
 * 
 * @return	1 if the set contains the element;
 * 			0 otherwise.
 */
int		set_contains(t_set *set, void *data);

/**
 * @brief	Checks if the first set is a subset of the second set.
 * 
 * @param set1	Pointer to the first set.
 * @param set2	Pointer to the second set.
 * 
 * @return	1 if the second set contains all elements of the first set;
 * 			0 otherwise.
 */
int		set_subset(t_set *set1, t_set *set2);

/**
 * @brief	Checks if the first set is equal to the second set.
 * 
 * @param set1	Pointer to the first set.
 * @param set2	Pointer to the second set.
 * 
 * @return	1 if the first and second set contain the same elements;
 * 			0 otherwise.
 */
int		set_equal(t_set *set1, t_set *set2);

/**
 * @brief	Counts the number of elements in the set.
 * 
 * @param set	Pointer to the set.
 * 
 * @return	Number of elements in the set.
 */
int		set_size(t_set *set);

/**
 * @brief	Prints the set.
 * 
 * @param set	Pointer to the set.
 */
void	set_print(t_set *set);

#endif
