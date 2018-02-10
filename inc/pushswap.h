/*
** EPITECH PROJECT, 2017
** Pushswap
** File description:
** pushswap
*/

#ifndef _PUSHSWAP_H_
	#define _PUSHSWAP_H_

	#include <stdlib.h>
	#include <unistd.h>
	#include <malloc.h>

	#define MAX_BUFF_SIZE 0x1000
	#define FIRST(f) (f = !f ? 1 : f)
	#define ABS(n) (((int)n < 0) ? (int)(-n) : (int)(n))

typedef struct s_node t_node;

struct s_node
{
		int val;
		t_node *next;
		t_node *prev;
};

void push_head(t_node **head, int val);
void free_list(t_node **head);
void push_head(t_node **head, int val);
void rotate_right(t_node **list, t_node **tail);
void rotate_left(t_node **list, t_node **tail);
int is_sorted(t_node *list);
int handle_special(int argc, char **argv);
void swap(t_node **la);
void push(t_node **src, t_node **dst);
int my_atoi(char *s);
int find_min_dist(int a, int b, int size);
void pushswap(t_node *head,
			  t_node *tail,
			  size_t n);

#endif
