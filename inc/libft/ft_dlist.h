/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlist.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:26:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/25 01:07:09 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DLIST_H
# define FT_DLIST_H
# define FT_REQUIRE_TYPE_GENERIC
# define FT_REQUIRE_TYPE_SIZE_T
# include "private/ft_include.h"

typedef struct s_dlist	t_dlist;
struct	s_dlist
{
	void	*content;
	t_dlist	*prev;
	t_dlist	*next;
};

/*
** Appends the start of l2 to the end of l1.
** Returns a pointer to the first element of the doubly linked list.
*/
t_dlist	*ft_dlist_append(t_dlist *l1, t_dlist *l2);

/*
** Returns the element at the given index if it exists.
** The index can be negative if the element is located in a previous node.
** Returns NULL if the element does not exist.
*/
t_dlist	*ft_dlist_at(t_dlist *list, int index);

/*
** Free a doubly linked list from the given node.
** The function pointer del can be NULL.
** Returns NULL.
*/
void	*ft_dlist_clear(t_dlist **list, t_gfunction del);

/*
** Returns the first element if it exists.
*/
t_dlist	*ft_dlist_first(t_dlist *l);

/*
** Apply a function to each content of a doubly linked list from the given node.
*/
void	ft_dlist_foreach(t_dlist *l, t_gfunction function);

/*
** Insert an element in a sorted doubly linked list.
** The inserted element may be NULL.
** Comparison is done with a comparison fonction pointer.
** Returns a pointer to the inserted element.
*/
t_dlist	*ft_dlist_insert(t_dlist **list, t_dlist *element, t_gcompare cmp);

/*
** Returns the last element if it exists.
*/
t_dlist	*ft_dlist_last(t_dlist *l);

/*
** Set l values with the given prev and next node.
** The prev and next pointer of l are overwritten by the new values.
** Returns l.
*/
t_dlist	*ft_dlist_merge(t_dlist *l, t_dlist *prev, t_dlist *next);

/*
** Creates a new element with malloc.
** Returns NULL on error.
*/
t_dlist	*ft_dlist_new(void *content);

/*
** Destroy the first element from a doubly linked list if it exists.
** If the function pointer del is NULL, content is returned, NULL otherwise.
*/
void	*ft_dlist_pop(t_dlist **list, t_gfunction del);

/*
** Display the contents of the doubly linked list to given file descriptor.
** The print function is called to display the content of each item.
*/
void	ft_dlist_print_fd(t_dlist *l, t_gprint_fd print_fd, int fd);

/*
** Display the contents of the doubly linked list on standard output.
** The print function is called to display the content of each item.
*/
void	ft_dlist_print(t_dlist *l, t_gprint print);

/*
** Add an element at the end of a doubly linked list.
** The inserted element may be NULL.
** Returns a pointer to the inserted element.
*/
t_dlist	*ft_dlist_push_back(t_dlist **list, t_dlist *element);

/*
** Add an element at the given position of a doubly linked list.
** The inserted element may be NULL.
** Returns a pointer to the inserted element.
*/
t_dlist	*ft_dlist_push(t_dlist **list, t_dlist *element);

/*
** Removes every elements matching the reference content from a singly linked
** list. Comparison is done with a comparison fonction pointer.
** The function pointer del can be NULL.
*/
void	ft_dlist_remove_if(t_dlist **list, const void *reference,
		t_gcompare cmp, t_gfunction del);

/*
** Reverse the order of items in the doubly linked list.
** Returns a pointer to the start of the doubly linked list.
*/
t_dlist	*ft_dlist_rev(t_dlist *list);

/*
** Search an element from a doubly linked list from the given node which
** matches the reference content and returns a pointer to it.
** Comparison is done with a comparison fonction pointer.
** Returns NULL if not found.
*/
t_dlist	*ft_dlist_search(t_dlist *list, const void *reference, t_gcompare cmp);

/*
** Returns the size of a doubly linked list from the given node.
*/
size_t	ft_dlist_size(t_dlist *l);

/*
** Allocates and returns a doubly linked list of strings obtained by splitting s
** using all characters from set as delimiters.
** If the given set is empty, all spaces are delimiters by default.
** If insufficient memory is available or s is empty, NULL is returned.
*/
t_dlist	*ft_dlist_split(const char *s, const char *set);

#endif
