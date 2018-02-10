/*
** EPITECH PROJECT, 2017
** Pushswap
** File description:
** pushswap
*/

#include "pushswap.h"

static char g_buffer[MAX_BUFF_SIZE] = { 0 };
static size_t g_pos = 0;

static inline void add_output(char *s)
{
		if (g_pos + 4 > MAX_BUFF_SIZE)
		{
				write(1, g_buffer, g_pos);
				g_pos = 0;
		}
		for (size_t i = 0; s[i] != 0; i++)
		{
				g_buffer[g_pos] = s[i];
				g_pos += 1;
		}
}

size_t find_min(t_node *list, size_t size)
{
		t_node *p = list;
		int min = p ? p->val : 0;
		int prev_min = min;
		int n = 0;
		int pos = 0;
		int pos_prev = 0;

		while (p) {
				if (p->val <= min) {
						prev_min = min;
						min = prev_min;
						min = p->val;
						pos_prev = pos;
						pos = n;
				}
				else if (p->val < prev_min) {
						prev_min = p->val;
						pos_prev = n;
				}
				++n;
				p = p->next;
		}
		return (!pos_prev ? pos :
				find_min_dist(pos_prev, pos, size));
}

static inline void final_sort(t_node **la, t_node **lb, int *f)
{
		while (*lb) {
				if ((*lb)->next && ((*lb)->next->val > (*lb)->val))
				{
						swap(lb);
						add_output(*f ? " sb" : "sb");
						FIRST(*f);
				}
				push(lb, la);
				add_output(*f ? " pa" : "pa");
				FIRST(*f);
		}
}

static inline void align(t_node **la, t_node **tail,
						 const size_t *size, size_t *dist,
						 size_t *count, int *f)
{
		if (*dist <= (*size / 2)) {
				for (register size_t i = 0; i < *dist; i++) {
						rotate_left(la, tail);
						add_output(*f ? " ra" : "ra");
						FIRST(*f);
				}
		} else {
				for (register size_t i = 0; i < *count - *dist; i++) {
						rotate_right(la, tail);
						add_output(*f ? " rra" : "rra");
						FIRST(*f);
				}
		}
}

void pushswap(t_node *la,
			  t_node *tail,
			  const size_t n)
{
		t_node *lb = NULL;
		size_t dist = 0;
		size_t count = n;
		int f = 0;

		while (la) {
				dist = find_min(la, n);
				align(&la, &tail, &n, &dist, &count, &f);
				push(&la, &lb);
				add_output(f ? " pb" : "pb");
				FIRST(f);
				count--;
		}
		final_sort(&la, &lb, &f);
		write(1, g_buffer, g_pos);
		write(1, "\n", 1);
		free_list(&la);
}
