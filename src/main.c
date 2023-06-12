#include "woody.h"

int main(int ac, char **av)
{
	if (ac != 2)
		return (1);
	printf("%s\n", av[1]);
}