#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	//char	*s = "Hello";
//	int		i = 42;
	//char	c = 'A';
	int		pf = 0;
	int		ftf = 0;
	//char	*s = NULL;

	ftf = ft_printf("ft -> |%c|\n", '0' - 256) - 9;
	ftf = ft_printf("ft -> |%c|\n", '0' + 256) - 9;
	pf = printf("OG -> |%c|\n", '0' - 256) - 9;
	pf = printf("OG -> |%c|\n", '0' + 256) - 9;
	pf = printf("OG -> |%c|\n", 0) - 9;
	//pf = printf("OG -> |%s|\n", s) - 9;
	//pf = printf("OG -> |%i|\n", i) - 9;
	//pf = ft_printf("|%#015x|", i);
	ft_printf("-- printed char count --\nft -> %d\nOG -> %d\n", ftf, pf);
	return 0;
}
