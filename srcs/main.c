#include "push_swap.h"

int		main(int ac, char **av)
{
	t_all	*all;

	all = init_all(ac, av);
	display_list(all->a);
	return (0);
}