#include "woody.h"

int main(int ac, char **av)
{
	if (ac != 2)
		error("Usage : ./woody_woodpacker [FILE]");
	woody w;
	w.new = 0;
	w.file = cp_file(av[1], w);
	
}