#include <libft.h>

int	main(int ac, char **av)
{
	int i;

	i = 0;
	while (++i < ac)
	{
		ft_putrawstr(av[i]);
		ft_putchar('\n');
	}
	return (0);
}
