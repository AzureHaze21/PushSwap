/*
** EPITECH PROJECT, 2017
** Pushswap
** File description:
** pushswap
*/

#include "pushswap.h"

int find_min_dist(int a, int b, int size)
{
		if (ABS(a - (size / 2)) > ABS(b - (size / 2)))
				return (a);
		return (b);
}

int my_atoi(char *s)
{
		int ret = 0;
		short sign = 1;

		if (!s)
				return (0);
		sign = (*s == '-') ? -1 : 1;
		s += (*s == '-') ? 1 : 0;
		for (size_t i = 0; s[i]; i++)
				ret = (ret * 10) + (s[i] - '0');
		return (ret * sign);
}

void free_list(t_node **head)
{
		t_node *p;

		while ((p = *head))
		{
				*head = p->next;
				free(p);
		}
}

void push_head(t_node **head,
			   int val)
{
		t_node *new_node;

		if (!(new_node = malloc(sizeof(t_node))))
				return;
		if (!new_node)
				return;
		new_node->val = val;
		new_node->next = NULL;
		new_node->prev = NULL;
		if (*head)
		{
				new_node->next = *head;
				(*head)->prev = new_node;
				*head = new_node;
		}
		else
				*head = new_node;
}
