/*
** EPITECH PROJECT, 2017
** Pushswap
** File description:
** pushswap
*/

#include "pushswap.h"

inline void push(t_node **src,
				 t_node **dst)
{
		t_node *p = *src;

		if (p)
		{
				p = (*src)->next;
				(*src)->next = *dst;
				*dst = *src;
				(*dst)->prev = (*src);
				*src = p;
				if (*src)
						(*src)->prev = NULL;
		}
}

inline void swap(t_node **la)
{
		if (*la && (*la)->next)
		{
				(*la)->val ^= (*la)->next->val;
				(*la)->next->val ^= (*la)->val;
				(*la)->val ^= (*la)->next->val;
		}
}

inline void rotate_left(t_node **list,
						t_node **tail)
{
		if (*list && (*list)->next)
		{
				(*tail)->next = *list;
				(*list) = (*list)->next;
				(*list)->prev = NULL;
				(*tail)->next->next = NULL;
				(*tail)->next->prev = (*tail);
				(*tail) = (*tail)->next;
		}
}

inline void rotate_right(t_node **list,
						 t_node **tail)
{
		if (*list && (*list)->next)
		{
				(*tail)->next = (*list);
				(*list)->prev = (*tail);
				(*list) = (*tail);
				(*tail) = (*tail)->prev;
				(*tail)->next->prev = NULL;
				(*tail)->next = NULL;
		}
}
