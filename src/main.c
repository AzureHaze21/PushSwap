/*
** EPITECH PROJECT, 2017
** Pushswap
** File description:
** pushswap
*/

#include "pushswap.h"

int main(int argc, char **argv)
{
		t_node *la = NULL;
		t_node *tail = NULL;
		size_t n = argc;
		
		if (n < 3)
		{
				write(1, "\n", 1);
				return (0);
		}
		push_head(&la, my_atoi(argv[n - 1]));
		tail = la;
		while (--n > 1)
				push_head(&la, my_atoi(argv[n - 1]));
		if (is_sorted(la) || handle_special(argc, argv))
		{
				free_list(&la);
				write(1, "\n", 1);
				return (0);
		}
		pushswap(la, tail, argc - 1);
		return (0);
}
