#include "woody.h"

void error(char *s)
{
    write(2, s, strlen(s));
    exit(1);
}