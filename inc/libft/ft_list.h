/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:02:20 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 19:26:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H
# include <stddef.h>

typedef struct s_list	t_list;
struct	s_list
{
	void	*content;
	t_list	*next;
};

/*
** Returns the element at the given index if it exists.
*/
t_list	*ft_list_at(t_list *list, size_t index);

/*
** Free a list.
** The function pointer del can be NULL.
** Returns NULL.
*/
void	*ft_list_clear(t_list **list, void (*del)(void *));

/*
** Extracts an element from a list which matches the reference content
** and returns a pointer to it.
** Comparison is done with cmp.
*/
t_list	*ft_list_extract(t_list **list, const void *reference,
		int (*cmp)(const void *reference, const void *content));

/*
** Apply a function on each content from a list.
*/
void	ft_list_foreach(t_list *l, void (*f)(void *));

/*
** Insert an element in a sorted list.
** Comparison is done with cmp.
*/
void	ft_list_insert(t_list **list, t_list *element,
		int (*cmp)(const void *, const void *));

/*
** Returns the last element if it exists.
*/
t_list	*ft_list_last(t_list *l);

/*
** Creates a new element with malloc.
*/
t_list	*ft_list_new(void *content);

/*
** Destroy the first element from a list if it exists.
** If the function pointer del is NULL, content is returned, NULL otherwise.
*/
void	*ft_list_pop(t_list **list, void (*del)(void *));

/*
** Add an element at the end of a list.
** Returns a pointer to the inserted element.
*/
t_list	*ft_list_push_back(t_list **list, t_list *element);

/*
** Add an element at the beginning of a list.
** Returns a pointer to the inserted element.
*/
t_list	*ft_list_push(t_list **list, t_list *element);

/*
** Removes every elements matching the reference content from a list.
** Comparison is done with cmp.
** The function pointer del can be NULL.
*/
void	ft_list_remove_if(t_list **list, const void *reference,
		int (*cmp)(const void *reference, const void *content),
		void (*del)(void *));

/*
** Reverse the order of items in the list.
** Returns a pointer to the start of the list.
*/
t_list	*ft_list_rev(t_list *list);

/*
** Search an element from a list which matches the reference content
** and returns a pointer to it.
** Comparison is done with cmp.
*/
t_list	*ft_list_search(t_list *list, const void *reference,
		int (*cmp)(const void *reference, const void *content));

/*
** Returns the size of a list.
*/
size_t	ft_list_size(t_list *l);

/*
** Sort a list in O(nlogn) time.
** Comparison is done with cmp.
*/
void	ft_list_sort(t_list **list,
		int (*cmp)(const void *, const void *));

/*
** Allocates and returns a list of strings obtained by splitting s
** using all characters from set as delimiters.
** If the given set is empty, all spaces are delimiters by default.
** If insufficient memory is available or s is empty, NULL is returned.
*/
t_list	*ft_list_split(const char *s, const char *set);

#endif
