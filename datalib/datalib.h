/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   datalib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antgalan <antgalan@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:40:27 by antgalan          #+#    #+#             */
/*   Updated: 2023/01/23 11:16:50 by antgalan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATALIB_H
# define DATALIB_H

# include <unistd.h>
# include <stdlib.h>

/******************************** LINKED LIST *********************************/

/**
 * @brief	Linked list structure.
 * 
 * @param data 	The data stored in the element.
 * @param next 	Pointer to the next element in the list.
 */
typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}	t_list;

/**
 * @brief	Creates a new element for the list.
 * 
 * @param data 	The data to be stored in the new element.
 * 
 * @return 	Pointer to the new element.
 */
t_list	*lst_new(void *data);

/**
 * @brief	Adds a new element to the beginning of the list.
 * 
 * @param lst 	Pointer to the first element of the list.
 * @param new 	Pointer to the new element to be added.
 */
void	lst_add_first(t_list **list, t_list *elem);

/**
 * @brief	Adds a new element to the list in the given position.
 * 
 * @param elem	Pointer to the element after which the new element will be added.
 * @param new 	Pointer to the new element to be added.
 */
void	lst_add_after(t_list *elem, t_list *new);

/**
 * @brief	Adds a new element to the end of the list.
 * 
 * @param lst 	Pointer to the first element of the list.
 * @param new 	Pointer to the new element to be added.
 */
void	lst_add_last(t_list **list, t_list *elem);

/**
 * @brief 	Replace all the elements in the list that match the old element
 * 			with the new element.
 * 
 * @param lst	Pointer to the first element of the list.
 * @param old 	The data to be replaced.
 * @param new	The data to replace the old data.
 * 
 * @return	Number of elements replaced.
 */
int		lst_replace(t_list **list, void *old, void *new);

/**
 * @brief 	Deletes the first element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	lst_remove_first(t_list **list);

/**
 * @brief	Deletes the given element from the list.
 * 
 * @param list	Pointer to the first element of the list.
 * @param elem	Pointer to the element to be deleted.
 */
void	lst_remove(t_list **list, t_list *elem);

/**
 * @brief	Deletes the last element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	lst_remove_last(t_list **list);

/**
 * @brief	Deletes all the elements in the list that match the given data.
 * 
 * @param list	Pointer to the first element of the list.
 * @param data	The data to be deleted.
 * 
 * @return	Number of elements deleted.
 */
int		lst_purge(t_list **list, void *data);

/**
 * @brief	Deletes all the elements in the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	lst_clear(t_list **list);

/**
 * @brief	Checks if the list is empty.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return	1 if the list is empty, 0 otherwise.
 */
int		lst_empty(t_list *list);

/**
 * @brief	Checks the number of elements in the list.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return	Number of elements in the list.
 */
int		lst_size(t_list *list);

/**
 * @brief	Identifies the first element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return	Pointer to the first element of the list.
 */
t_list	*lst_first(t_list *list);

/**
 * @brief	Identifies the last element of the list.
 * 
 * @param list	Pointer to the first element of the list.
 * 
 * @return	Pointer to the last element of the list.
 */
t_list	*lst_last(t_list *list);

/**
 * @brief	Identifies the first element int the list with the given data.
 * 
 * @param list	Pointer to the first element of the list.
 * @param pos	Position of the element to be returned.
 * 
 * @return	Pointer to the element if found;
 * 			NULL otherwise.
 */
t_list	*lst_search(t_list *list, void *data);

/**
 * @brief 	Prints the list.
 * 
 * @param list	Pointer to the first element of the list.
 */
void	lst_print(t_list *list);

#endif
